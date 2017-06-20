#include "Menu.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"
#include "quitSingleton.h"

Menu::Menu()
{
	menu = new Texture("./textures/pauseMenu.png");
}

Menu::~Menu()
{
	delete menu;
}

void Menu::OnEnter()
{
}

void Menu::OnUpdate(float DeltaTime, StateMachine* state)
{
	x += DeltaTime;

	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ENTER))
		state->PopState();

	if(input->wasKeyPressed(INPUT_KEY_ESCAPE))
		quitSingleton::instance()->gameQuit();
}

void Menu::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(menu, 700, 365);
}

void Menu::OnExit()
{
}