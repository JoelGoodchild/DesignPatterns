#pragma once
#include "BaseState.h"

class Menu : public BaseState
{
public:
	//---------------------------------------------------------------------------------------
	//Constuctor to initiate the class and all its variables
	//---------------------------------------------------------------------------------------
	Menu();
	//---------------------------------------------------------------------------------------
	//Destructor to delete or clear up the memory to ensure that there are no memory leaks 
	//---------------------------------------------------------------------------------------
	~Menu();

	//---------------------------------------------------------------------------------------
	//Function in charge of any operations done when this state is entered
	//---------------------------------------------------------------------------------------
	void OnEnter();
	//---------------------------------------------------------------------------------------
	//Function that controls the updating for this state
	//Taking in delta time to conduct any calculations that require time
	//And a state machine pointer to change states when neccessary
	//---------------------------------------------------------------------------------------
	void OnUpdate(float DeltaTime, StateMachine* state);
	//---------------------------------------------------------------------------------------
	//Function that draws all sprites and objects to the screen
	//Taking in a Renderer2D pointer to draw the object to the window
	//---------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);
	//---------------------------------------------------------------------------------------
	//Function in charge of any operations done when this state is exited
	//---------------------------------------------------------------------------------------
	void OnExit();

private:
	//---------------------------------------------------------------------------------------
	//The texture that is drawn to the window when the menu state is active
	//---------------------------------------------------------------------------------------
	Texture* menu;
};
