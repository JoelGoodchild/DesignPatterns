#include "Splash.h"
#include "Texture.h"
#include "Input.h"

Splash::Splash()
{
	sprite = new Texture("./textures/ship.png");
}

Splash::~Splash()
{
	delete sprite;
}

void Splash::OnEnter()
{

}

void Splash::OnUpdate(float DeltaTime)
{
	Input* input = Input::getInstance();
}

void Splash::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(sprite, 100, 100);
}

void Splash::OnExit()
{

}