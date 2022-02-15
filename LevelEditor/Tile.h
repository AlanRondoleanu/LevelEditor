#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Tile
{
public:
	Tile();
	void init();
	void draw(sf::RenderWindow& t_window);
	void setPosition(int t_x, int t_y) { shape.setPosition(t_x,t_y); }
	void setColor(sf::Color& t_color) { shape.setFillColor(t_color); }
	void setColor(sf::Color t_color) { shape.setFillColor(t_color); }
	void setSize(sf::Vector2f t_size) { shape.setSize(t_size); } 
	void checkCollision(sf::Vector2f t_mouse, sf::Color& t_color);
	int checkColor(sf::Vector2f t_mouse);
	sf::Color getColor() { return shape.getFillColor(); }

	static int count;

private:
	sf::RectangleShape shape;
	const float SIZE{ 20 };
};

