#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Interface.h"
#include "Widget.h"
#include "WidgetManager.h"
#include "Slider.h"
#include <functional>

enum Tool {
	NONE,
	PEN,
	BRUSH,
	ERASER,
	FILL_BUCKET
};

enum Colors {
	BLACK,
	WHITE,
	BLUE,
	RED,
	GREEN,
	PINK,
	CYAN,
	YELLOW,
	COLOR_PICKER
};

class Paint
{
public:
	 Paint(sf::RenderWindow& window);
	~Paint();
public:
	void Initialize (Data* data);
	void Run();
private:
	inline void init_toolIcons();
	inline void init_colorIcons();
	inline void init_tweakIcons();
	inline void init_randomStuff();

	void Draw(sf::RenderWindow& window, const sf::IntRect& bounds, int width, int height, const sf::Color& color);
	void RunWindow(sf::RenderWindow& window, sf::Vector2u windowSize, std::string title, void(Paint::*run)());
	inline void SetBgColor(const sf::Color& color);

	inline void Clear();
	void SelectClickedColor();
	void SelectClickedTools();
	void ChangeColor();
	void Launch_colorPicker();
	void Launch_toolSize();
	void PaintStuff();
	inline void UpdateColorDisplay();

	void ColorPickerWindow();
	void ToolSizeWindow();
private:
	Data*              m_data;
	Tool               m_tool;

	WidgetManager       m_toolIcons;
	WidgetManager       m_tweakIcons;
	WidgetManager       m_colorIcons;
	Colors              m_selectedColor;
	sf::Color           m_paintColor;

	Slider              m_brushSlider;
	sf::RectangleShape  m_currentColorDisplay;

	sf::RenderWindow&   m_mainWindow;
	sf::RenderWindow    m_colorPickerWindow;
	sf::RenderWindow    m_toolSizeWindow;

	sf::RectangleShape  m_colorWheel;
	sf::Texture         m_colorWheel_tex;
	sf::Image           m_colorWheel_img;

	std::string   m_colorsNames[8] = { 
		"BLACK",
		"WHITE",
		"BLUE",
		"RED",
		"GREEN",
		"PINK",
		"CYAN",
		"YELLOW",
	};
};