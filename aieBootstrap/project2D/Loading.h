#pragma once
#include "BaseState.h"

class Loading : public BaseState
{
public:
	Loading();
	~Loading();

	void OnEnter();
	void OnUpdate(float DeltaTime);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};
