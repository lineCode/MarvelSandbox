#pragma once

#include "Core/AppItems/mvTypeBases.h"
#include <implot.h>
#include <map>
#include "Core/mvCore.h"

//-----------------------------------------------------------------------------
// Widget Index
//
//     * mvPlot
//
//-----------------------------------------------------------------------------

namespace Marvel {

	//-----------------------------------------------------------------------------
	// mvSeries
	//-----------------------------------------------------------------------------
	class mvSeries
	{

	public:

		mvSeries(const std::string& name, const std::vector<mvVec2>& points)
			: m_name(name)
		{
			for (auto point : points)
			{
				m_xs.push_back(point.x);
				m_ys.push_back(point.y);
			}

		}

		virtual ~mvSeries() = default;

		virtual void draw() = 0;

	protected:

		std::string        m_name;
		std::vector<float> m_xs;
		std::vector<float> m_ys;

	};

	//-----------------------------------------------------------------------------
	// mvPlot
	//-----------------------------------------------------------------------------
	class mvPlot : public mvNoneItemBase
	{

	public:

		MV_APPITEM_TYPE(mvAppItemType::Plot)

		mvPlot(const std::string& parent, const std::string& name, const std::string& xname="", 
			const std::string& yname="", int width = -1, int height = 0, ImPlotFlags flags = 0, 
			ImPlotAxisFlags xflags = 0, ImPlotAxisFlags yflags = 0)
			: mvNoneItemBase(parent, name), m_xaxisName(xname), m_yaxisName(yname)
		{
			m_width = width;
			m_height = height;
		}

		void addSeries(mvSeries* series)
		{
			m_series.push_back(series);
		}

		void SetColorMap(ImPlotColormap colormap)
		{
			m_colormap = colormap;
		}

		void clear()
		{
			for (auto series : m_series)
			{
				delete series;
				series = nullptr;
			}

			m_series.clear();
		}

		virtual void draw() override
		{
			ImGui::PushID(m_colormap);

			if (ImPlot::BeginPlot(m_name.c_str(), m_xaxisName.c_str(), m_yaxisName.c_str(), ImVec2(m_width, m_height), m_flags,
				m_xflags, m_yflags) )
			{
				ImPlot::SetColormap(m_colormap);

				for (auto series : m_series)
					series->draw();
		

				ImPlot::SetColormap(ImPlotColormap_Default);

				ImPlot::EndPlot();
			}

			ImGui::PopID();
		}


	private:

		std::string     m_xaxisName;
		std::string     m_yaxisName;
		ImPlotFlags     m_flags    = ImPlotFlags_Default;
		ImPlotAxisFlags m_xflags  = ImPlotAxisFlags_Default;
		ImPlotAxisFlags m_yflags  = ImPlotAxisFlags_Default;
		ImPlotColormap  m_colormap = ImPlotColormap_Default;

		std::vector<mvSeries*> m_series;

	};

	//-----------------------------------------------------------------------------
	// mvLineSeries
	//-----------------------------------------------------------------------------
	class mvLineSeries: public mvSeries
	{

	public:

		mvLineSeries(const std::string& name, const std::vector<mvVec2>& points, float weight=1.0f,
			mvColor color = MV_DEFAULT_COLOR)
			: mvSeries(name, points), m_lineWeight(weight), m_color(color)
		{
		}

		virtual void draw() override
		{
			if (m_color.specified)
				ImPlot::PushStyleColor(ImPlotCol_Line, m_color);

			ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, m_lineWeight);

			ImPlot::PlotLine(m_name.c_str(), m_xs.data(), m_ys.data(), m_xs.size());

			if (m_color.specified)
				ImPlot::PopStyleColor();

			ImPlot::PopStyleVar();
		}

	private:

		float m_lineWeight;
		mvColor m_color;

	};

	//-----------------------------------------------------------------------------
	// mvScatterSeries
	//-----------------------------------------------------------------------------
	class mvScatterSeries : public mvSeries
	{

	public:

		mvScatterSeries(const std::string& name, const std::vector<mvVec2>& points, int marker=2, float markerSize=4.0f, float markerWeight =1.0f,
			mvColor markerOutlineColor = MV_DEFAULT_COLOR, mvColor markerFillColor = MV_DEFAULT_COLOR)
			: mvSeries(name, points), m_marker(marker), m_markerSize(markerSize), m_markerWeight(markerWeight),
			m_markerOutlineColor(markerOutlineColor), m_markerFillColor(markerFillColor)
		{
		}

		virtual void draw() override
		{
			if (m_markerOutlineColor.specified)
				ImPlot::PushStyleColor(ImPlotCol_MarkerOutline, m_markerOutlineColor);
			if (m_markerFillColor.specified)
				ImPlot::PushStyleColor(ImPlotCol_MarkerFill, m_markerFillColor);
				
			ImPlot::PushStyleVar(ImPlotStyleVar_Marker, m_marker);
			ImPlot::PushStyleVar(ImPlotStyleVar_MarkerSize, m_markerSize);
			ImPlot::PushStyleVar(ImPlotStyleVar_MarkerWeight, m_markerWeight);

			ImPlot::PlotScatter(m_name.c_str(), m_xs.data(), m_ys.data(), m_xs.size());

			if (m_markerOutlineColor.specified)
				ImPlot::PopStyleColor();
			if (m_markerFillColor.specified)
				ImPlot::PopStyleColor();

			ImPlot::PopStyleVar(3);
		}

	private:

		int   m_marker = 2;
		float m_markerSize = 4.0f;
		float m_markerWeight = 1.0f;
		mvColor m_markerOutlineColor = MV_DEFAULT_COLOR;
		mvColor m_markerFillColor = MV_DEFAULT_COLOR;

	};

	//-----------------------------------------------------------------------------
	// mvLabelSeries
	//-----------------------------------------------------------------------------
	class mvLabelSeries : public mvSeries
	{

	public:

		mvLabelSeries(const std::string& name, const std::vector<mvVec2>& points, int xoffset=0, int yoffset=0, bool vertical = false)
			: mvSeries(name, points), m_xoffset(xoffset), m_yoffset(yoffset), m_vertical(vertical)
		{
		}

		virtual void draw() override
		{
			ImPlot::PlotText(m_name.c_str(), m_xs[0], m_ys[0], m_vertical, ImVec2(m_xoffset, m_yoffset));
		}

	private:

		int m_xoffset;
		int m_yoffset;
		bool m_vertical;

	};

}