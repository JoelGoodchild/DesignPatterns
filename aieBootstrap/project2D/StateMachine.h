#pragma once
#include "Renderer2D.h"
#include "Stack.h"
#include "BaseState.h"

using namespace aie;

class StateMachine

{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int newState);
	void PopState();
	void AddState(BaseState* state, int newState);

private:
	Stack<BaseState*> Stack;
	dynamicArray<BaseState*> baseState;
};