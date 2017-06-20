#pragma once
#include "BaseState.h"

class Splash2 : public BaseState
{
public:
	Splash2();
	~Splash2();

	void OnEnter();
	void OnUpdate(float DeltaTime, StateMachine* state);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	Texture* joel;
	float x;
	float time;
};

