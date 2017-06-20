#pragma once
#include "BaseState.h"

class Menu : public BaseState
{
public:
	Menu();
	~Menu();

	void OnEnter();
	void OnUpdate(float DeltaTime, StateMachine* state);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	Texture* menu;

	float x;
};
