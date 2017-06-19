#pragma once
#include "BaseState.h"

class Game : public BaseState
{
public:
	Game();
	~Game();

	void OnEnter();
	void OnUpdate(float DeltaTime);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};

