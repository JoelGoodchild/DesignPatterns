#include "Splash2.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"
#include <assert.h>


Splash2::Splash2()
{
	joel = new Texture("./textures/joel.png");
	assert(joel);
	x = 0;
	time = 0;
}

Splash2::~Splash2()
{
	delete joel;
}

void Splash2::OnEnter(){}

void Splash2::OnUpdate(float DeltaTime, StateMachine * state)
{
	Input* input = Input::getInstance();
	x += DeltaTime / 1.5;
	time += DeltaTime;
	if (time >= 2.5)
		state->PushState(2);
}

void Splash2::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, x);
	m_2dRenderer->drawSprite(joel, 700, 360);
}

void Splash2::OnExit(){}