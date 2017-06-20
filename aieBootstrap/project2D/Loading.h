#pragma once
#include "BaseState.h"
#include "Texture.h"

class Loading : public BaseState
{
public:
	Loading();
	~Loading();

	void OnEnter();
	void OnUpdate(float DeltaTime, StateMachine* state);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	Texture* loading;
	Texture* questionMark;

	float rot;
	float x;
	float time;
};
