#include "Tile.h"

Tile::Tile()
{
	init();
}

void Tile::init()
{
	shape.setSize(sf::Vector2f{ SIZE, SIZE });
	shape.setFillColor(sf::Color::White);
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color::Black);
	count++;
}

void Tile::draw(sf::RenderWindow& t_window)
{
	t_window.draw(shape);
}

void Tile::checkCollision(sf::Vector2f t_mouse, sf::Color& t_color)
{
	if (t_mouse.x > shape.getPosition().x &&
		t_mouse.x < shape.getPosition().x + SIZE &&
		t_mouse.y > shape.getPosition().y &&
		t_mouse.y < shape.getPosition().y + SIZE)
	{
		shape.setFillColor(t_color);
	}
}

sf::Color Tile::checkColor(sf::Vector2f t_mouse)
{
	if (t_mouse.x > shape.getPosition().x &&
		t_mouse.x < shape.getPosition().x + shape.getSize().x &&
		t_mouse.y > shape.getPosition().y &&
		t_mouse.y < shape.getPosition().y + shape.getSize().x)
	{
		return shape.getFillColor();
	}
	return sf::Color::Black;
}
