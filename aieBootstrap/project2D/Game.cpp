#include "Game.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"

Game::Game()
{
	loading = new Texture("./textures/loading.png");
	questionMark = new Texture("./textures/questionMark.png");
	tip = new Texture("./textures/tip.png");
	fidget = new Texture("./textures/fidget.png");
	rot = 20.0264; //So you can not see a difference between states. CHANGE IF SPLASH SCREEN IS LENGTHENED
	x = 0;
	otherx = 0;
	time = 0;
	quesMX = 700;
	quesMY = 360;
	qMark = true;
	easterEgg = false;
}


Game::~Game()
{
	delete questionMark;
	delete loading;
}

void Game::OnEnter(){}

void Game::OnUpdate(float DeltaTime, StateMachine* state)
{
	Input* input = Input::getInstance();
	rot += 4 * DeltaTime;
	x += DeltaTime;
	if (time > 5)
		otherx += DeltaTime / 1.00000001f;
	time += DeltaTime;

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_W))
		quesMY += 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		quesMY -= 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		quesMX -= 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		quesMX += 500.0f * DeltaTime;

	// change to menu
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		state->PushState(4);
}

void Game::OnDraw(Renderer2D* m_2dRenderer)
{
	if (quesMX > 1450 || quesMY > 770 || quesMX < -20 || quesMY < -20 && !easterEgg)
	{
		qMark = false;
		easterEgg = true;
	}

	if (easterEgg)
	{
		m_2dRenderer->drawSprite(loading, 170, 40);
		m_2dRenderer->drawSprite(fidget, quesMX, quesMY, 0, 0, -rot * 2);
	}
	else if (qMark)
	{
		m_2dRenderer->drawSprite(loading, 170, 40);
		m_2dRenderer->drawSprite(questionMark, quesMX, quesMY, 0, 0, -rot);
	}

	if (time > 5)
	{
		m_2dRenderer->setRenderColour(1, 1, 1, otherx);
		m_2dRenderer->drawSprite(tip, 215, 685);
	}
}

void Game::OnExit(){}
