#include "Splash.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"

Splash::Splash()
{
	sprite1 = new Texture("./textures/splash.png");
	sprite2 = new Texture("./textures/splash2.png");
	
	x = 0;
	time = 0;
}

Splash::~Splash()
{
	
	delete sprite2;
	delete sprite1;
}

void Splash::OnEnter()
{
}

void Splash::OnUpdate(float DeltaTime, StateMachine* state)
{
	Input* input = Input::getInstance();
	x += DeltaTime / 1.5;
	time += DeltaTime;
	if (time >= 2.5)
		state->PushState(1);
}

void Splash::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, x);
	m_2dRenderer->drawSprite(sprite1, 700, 400);
	m_2dRenderer->drawSprite(sprite2, 700, 340);
}

void Splash::OnExit()
{

}