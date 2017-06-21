#include "Game.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"
#include <assert.h>

Game::Game()
{
	//Creates all sprites for the game state
	loading = new Texture("./textures/loading.png");
	assert(loading);
	questionMark = new Texture("./textures/questionMark.png");
	assert(questionMark);
	tip = new Texture("./textures/tip.png");
	assert(tip);
	fidget = new Texture("./textures/fidget.png");
	assert(fidget);

	//So you can not see a difference between states. 
	//CHANGE IF SPLASH SCREEN duration IS LENGTHENED.
	//Calculated by stopping the loading animation the 
	//frame before it changes and checking the rotation 
	//of the question mark
	rot = 20.0264;

	//Fade in variable for the tip
	x = 0;

	//Times how long you are in the state for
	time = 0;

	//Players x location
	playerX = 700;

	//Players y location
	playerY = 360;

	//Bools to check whether the easter egg has been activated
	qMark = true;
	easterEgg = false;

	//Bool to check if the player has returned back to the screen
	backIn = false;
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
	if (time > 5)
		x += DeltaTime / 1.00000001f;

	time += DeltaTime;

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_W))
		playerY += 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		playerY -= 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		playerX -= 500.0f * DeltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		playerX += 500.0f * DeltaTime;

	// change to menu
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		state->PushState(4);
}

void Game::OnDraw(Renderer2D* m_2dRenderer)
{
	//Checks whether the player has gone beyond the bounds 
	//of the window, changing the player from a question mark 
	//to the easter egg
	if (playerX > 1450 || playerY > 770 || playerX < -20 || playerY < -20 && !easterEgg)
	{
		qMark = false;
		easterEgg = true;
	}

	//Used if the player has activated the easter egg
	if (easterEgg)
	{
		m_2dRenderer->drawSprite(loading, 170, 40);

		//Checks if the player has come back into the window
		if (playerX < 1400 && playerX > 0 && playerY < 720 && playerY > 0)
			backIn = true;

		//If they are back in the window, this will ensure 
		//that it is only allowed in the bounds of the window 
		if (backIn)
		{
			if (playerX > 1400)
				playerX = 1400;
			if (playerY > 720)
				playerY = 720;
			if (playerX < 0)
				playerX = 0;
			if (playerY < 0)
				playerY = 0;
		}
		m_2dRenderer->drawSprite(fidget, playerX, playerY, 0, 0, -rot * 2);
	}

	//Used initially so that no difference can be noticed 
	//between the loading and game screens
	else if (qMark)
	{
		m_2dRenderer->drawSprite(loading, 170, 40);
		m_2dRenderer->drawSprite(questionMark, playerX, playerY, 0, 0, -rot);
	}

	//Displays the tip in the top left of the window 
	//after 5 seconds to ensure players are not left 
	//waiting too long without any guidance
	if (time > 5)
	{
		m_2dRenderer->setRenderColour(1, 1, 1, x);
		m_2dRenderer->drawSprite(tip, 215, 685, 0, 0, 0, 1);
	}
}

void Game::OnExit(){}
