# pragma once

#include "Core/mvPythonTranslator.h"
#include <map>
#include <string>

namespace Marvel{

	static std::map<std::string, mvPythonTranslator> BuildTranslations()
	{
		std::map<std::string, mvPythonTranslator> translators = {

			{"addDrawing", mvPythonTranslator({
				{mvPythonDataType::String, "name"},
				{mvPythonDataType::Integer, "width"},
				{mvPythonDataType::Integer, "height"}
			}, false, "Needs documentation")},

			{"drawLine", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "p1"},
				{mvPythonDataType::FloatList, "p2"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Integer, "thickness"},
			}, false, "Needs documentation")},

			{"drawTriangle", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "p1"},
				{mvPythonDataType::FloatList, "p2"},
				{mvPythonDataType::FloatList, "p3"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::FloatList, "fill"},
				{mvPythonDataType::Float, "thickness"}
			}, false, "Needs documentation")},

			{"drawRectangle", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "pmin"},
				{mvPythonDataType::FloatList, "pmax"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::FloatList, "fill"},
				{mvPythonDataType::Float, "rounding"},
				{mvPythonDataType::Float, "thickness"}
			}, false, "Needs documentation")},

			{"drawQuad", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "p1"},
				{mvPythonDataType::FloatList, "p2"},
				{mvPythonDataType::FloatList, "p3"},
				{mvPythonDataType::FloatList, "p4"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::FloatList, "fill"},
				{mvPythonDataType::Float, "thickness"}
			}, false, "Needs documentation")},

			{"drawText", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "pos"},
				{mvPythonDataType::String, "text"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Integer, "size"}
			}, false, "Needs documentation")},

			{"drawCircle", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "center"},
				{mvPythonDataType::Float, "radius"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::Integer, "segments"},
				{mvPythonDataType::Float, "thickness"},
				{mvPythonDataType::FloatList, "fill"}
			}, false, "Needs documentation")},

			{"drawPolyline", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "points"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::Integer, "closed"},
				{mvPythonDataType::Float, "thickness"}
			}, false, "Needs documentation")},

			{"drawPolygon", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "points"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::FloatList, "fill"},
				{mvPythonDataType::Float, "thickness"}
			}, false, "Needs documentation")},

			{"drawBezierCurve", mvPythonTranslator({
				{mvPythonDataType::String, "drawing"},
				{mvPythonDataType::FloatList, "p1"},
				{mvPythonDataType::FloatList, "p2"},
				{mvPythonDataType::FloatList, "p3"},
				{mvPythonDataType::FloatList, "p4"},
				{mvPythonDataType::FloatList, "color"},
				{mvPythonDataType::Optional},
				{mvPythonDataType::Float, "thickness"},
				{mvPythonDataType::Integer, "segments"}
			}, false, "Needs documentation")},

			{"clearDrawing", mvPythonTranslator({
				{mvPythonDataType::String, "draw"}
			}, false, "Needs documentation")},

		};

		return translators;
	}

}