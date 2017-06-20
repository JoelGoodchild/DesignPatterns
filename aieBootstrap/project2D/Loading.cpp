#include "Loading.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"

Loading::Loading()
{
	loading = new Texture("./textures/loading.png");
	questionMark = new Texture("./textures/questionMark.png");
	rot = 0;
	x = 0;
	time = 0;
}


Loading::~Loading()
{
	delete questionMark;
	delete loading;
}

void Loading::OnEnter(){}

void Loading::OnUpdate(float DeltaTime, StateMachine * state)
{
	Input* input = Input::getInstance();
	rot += 4 * DeltaTime;
	x += DeltaTime;
	time += DeltaTime;
	if (time >= 5)
		state->PushState(3);
}

void Loading::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, x);
	m_2dRenderer->drawSprite(loading, 170, 40);
	m_2dRenderer->drawSprite(questionMark, 700, 360, 0, 0, -rot);
}

void Loading::OnExit(){}