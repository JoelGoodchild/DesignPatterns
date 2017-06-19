#include "Ship.h"
#include "Texture.h"
#include "Input.h"
#include "Matrix3.h"

Ship::Ship()
{
	sprite = new Texture("./textures/ship.png");
}
Ship::~Ship()
{
	delete sprite;
}

void Ship::update(float deltaTime)
{
	Input* input = Input::getInstance();
}

void Ship::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(sprite, 100, 100);
}