#include "Menu.h"
#include "Texture.h"
#include "Input.h"
#include "StateMachine.h"
#include "quitSingleton.h"
#include <assert.h>
//---------------------------------------------------------------------------------------
Menu::Menu()
{
	//---------------------------------------------------------------------------------------
	//Creates the sprite for the menu state 
	//And asserts to ensure it is created successfully
	//---------------------------------------------------------------------------------------
	menu = new Texture("./textures/pauseMenu.png");
	assert(menu);

	//---------------------------------------------------------------------------------------
	//Times how long you are in the state for
	//---------------------------------------------------------------------------------------
	time = 0;
}
//---------------------------------------------------------------------------------------
Menu::~Menu()
{
	delete menu;
}
//---------------------------------------------------------------------------------------
void Menu::OnEnter(){} //LEFT BLANK
//---------------------------------------------------------------------------------------
void Menu::OnUpdate(float DeltaTime, StateMachine* state)
{
	Input* input = Input::getInstance();

	//---------------------------------------------------------------------------------------
	//If enter is pressed, returns to the game state
	//---------------------------------------------------------------------------------------
	if (input->isKeyDown(INPUT_KEY_ENTER))
		state->PopState();

	//---------------------------------------------------------------------------------------
	//If escape is pressed, uses the quit singleton to exit the game
	//---------------------------------------------------------------------------------------
	if(input->wasKeyPressed(INPUT_KEY_ESCAPE))
		quitSingleton::instance()->gameQuit();
}
//---------------------------------------------------------------------------------------
void Menu::OnDraw(Renderer2D* m_2dRenderer)
{
	//---------------------------------------------------------------------------------------
	//Sets the opacity of the sprites to be drawn, and then draws them
	//---------------------------------------------------------------------------------------
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(menu, 700, 365, 0, 0, 0, -1);
}
//---------------------------------------------------------------------------------------
void Menu::OnExit(){} //LEFT BLANK