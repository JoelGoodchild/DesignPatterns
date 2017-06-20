#pragma once
#include "BaseState.h"

class Game : public BaseState
{
public:
	Game();
	~Game();

	void OnEnter();
	void OnUpdate(float DeltaTime, StateMachine* state);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	Texture* loading;
	Texture* questionMark;
	Texture* tip;
	Texture* fidget;

	float rot;
	float x;
	float otherx;
	float time;
	float quesMX;
	float quesMY;
	bool qMark;
	bool easterEgg;
};

