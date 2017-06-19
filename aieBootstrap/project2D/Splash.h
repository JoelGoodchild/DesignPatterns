#pragma once
#include "BaseState.h"

class Splash : public BaseState
{
public:
	Splash();
	~Splash();

	void OnEnter();
	void OnUpdate(float DeltaTime);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	Texture* sprite;
};

