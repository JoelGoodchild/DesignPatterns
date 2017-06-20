#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Splash.h"
#include "Splash2.h"
#include "Loading.h"
#include "Menu.h"
#include "Game.h"
#include "quitSingleton.h"

using namespace aie;

Application2D::Application2D() {}
Application2D::~Application2D() {}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();
	m_font = new Font("./font/consolas.ttf", 32);
	m_pStates = new StateMachine();
	m_pStates->AddState(new Splash(), 0);
	m_pStates->AddState(new Splash2(), 1);
	m_pStates->AddState(new Loading(), 2);
	m_pStates->AddState(new Game(), 3);
	m_pStates->AddState(new Menu(), 4);
	m_pStates->PushState(0);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_pStates;
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_pStates->Update(deltaTime);
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	if (quitSingleton::instance()->getQuit())
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pStates->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	/*char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);*/

	// done drawing sprites
	m_2dRenderer->end();
}