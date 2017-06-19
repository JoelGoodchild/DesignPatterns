#pragma once
#include "BaseState.h"

class Menu : public BaseState
{
public:
	Menu();
	~Menu();

	void OnEnter();
	void OnUpdate(float DeltaTime);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};
