## Marvel Sandbox Specification
<sub>(This library is available under a free and permissive license)</sub>

### Widget Adding Interface
- [addButton](#addButton)
- [addCheckbox](#addCheckbox)
- [addChild](#addChild)
- [addCollapsingHeader](#addCollapsingHeader)
- [addColorEdit4](#addColorEdit4)
- [addCombo](#addCombo)
- [addGroup](#addGroup)
- [addInputFloat](#addInputFloat)
- [addInputInt](#addInputInt)
- [addInputText](#addInputText)
- [addLabelText](#addlabeltext)
- [addListbox](#addListbox)
- [addMenuBar](#addMenuBar)
- [addMenu](#addMenu)
- [addMenuItem](#addMenuItem)
- [addPopup](#addPopup)
- [addRadioButton](#addRadioButton)
- [addSameLine](#addSameLine)
- [addSelectable](#addSelectable)
- [addSimplePlot](#addsimpleplot)
- [addSpacing](#addSpacing)
- [addTab](#addTab)
- [addText](#addtext)
- [addTooltip](#addTooltip)
- [addTreeNode](#addTreeNode)
- [addWindow](#addWindow)
- [indent](#indent)
- [unindent](#unindent)


### App Interface
- [isItemHovered](#isItemHovered)
- [isItemActive](#isItemActive)
- [isItemFocused](#isItemFocused)
- [isItemClicked](#isItemClicked)
- [isItemVisible](#isItemVisible)
- [isItemEdited](#isItemEdited)
- [isItemActivated](#isItemActivated)
- [isItemDeactivated](#isItemDeactivated)
- [isItemDeactivatedAfterEdit](#isItemDeactivatedAfterEdit)
- [isItemToggledOpen](#isItemToggledOpen)
- [getItemRectMin](#getItemRectMin)
- [getItemRectMax](#getItemRectMax)
- [getItemRectSize](#getItemRectSize)
- [changeStyleItem](#changeStyleItem)
- [changeThemeItem](#changeThemeItem)
- [getValue](#getValue)
- [setValue](#setValue)
- [showItem](#showItem)
- [hideItem](#hideItem)
- [setMainCallback](#setMainCallback)
- [setMouseDownCallback](#setMouseDownCallback)
- [setMouseDoubleClickCallback](#setMouseDoubleClickCallback)
- [setMouseClickCallback](#setMouseClickCallback)
- [setKeyDownCallback](#setKeyDownCallback)
- [setKeyPressCallback](#setKeyPressCallback)
- [setKeyReleaseCallback](#setKeyReleaseCallback)
- [setItemCallback](#setItemCallback)
- [setItemPopup](#setItemPopup)
- [setItemTip](#setItemTip)
- [setItemWidth](#setItemWidth)
- [setTheme](#setTheme)



### Logging Interface
- [Log](#Log)
- [LogDebug](#LogDebug)
- [LogError](#LogError)
- [LogInfo](#LogInfo)
- [LogWarning](#LogWarning)
- [SetLogLevel](#SetLogLevel)


### Plot Interface
- [addPlot](#addPlot)
- [addLineSeries](#addLineSeries)
- [addScatterSeries](#addScatterSeries)


### Drawing Interface
- [addDrawing](#addDrawing)
- [clearDrawing](#clearDrawing)
- [drawBezierCurve](#drawBezierCurve)
- [drawCircle](#drawCircle)
- [drawLine](#drawLine)
- [drawPolygon](#drawPolygon)
- [drawPolyline](#drawPolyline)
- [drawRectangle](#drawRectangle)
- [drawQuad](#drawQuad)
- [drawText](#drawText)
- [drawTriangle](#drawTriangle)


### Input Interface
- [isMouseButtonPressed](#isMouseButtonPressed)
- [isKeyPressed](#isKeyPressed)



--------------------------------
### addButton
#### Inputs
**name:** (string) The button name

#### Keywords
**callback:** (string) the name of the function that the button will run when the button is pressed

#### Description
Buttons are useful for letting the user perform functions when pressed 

---------------------------------

### addCheckBox
#### Inputs
**name:** (string) The checkbox name

#### Keywords
**default_value:** (Integer) The value of the checkbox. A value of 1 = checked and 0 = false. 

#### Description
Checkboxed are useful for controlling the state of an input.

---------------------------------

### addSimplePlot
#### Inputs
**name:** (string) The name of the plot
</br>**value:** (tuple) A set of y-axis data values

#### Keywords
**autoscale:** (bool) Autoscales the y-axis to to be the range of the data. The y axis will start at the smallest value and end at the largest value.
</br>**overlay:** (string) Title of the graph.
</br>**minscale:** (float) Lower bounds of y-axis.
</br>**maxscale:** (float) Upper bounds of y-axis.
</br>**height:** (float) The overall height of the graph
</br>**histogram:** (bool) Enables histogram plot mode.

#### Description
A simple plot is useful for quickly displaying y-axis data values. The x-axis will be the item count.

--------------------------------

### addText
#### Inputs
**name:** (string) the text to be displayed

#### Keywords
**wrap:**
</br>**colory:**
</br>**bullet:**

#### Description
Text is useful to display item names, informaion, state, and much more to the user through the GUI.
