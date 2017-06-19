#include "StateMachine.h"
#include "Stack.h"
#include "dynamicArray.h"
#include "BaseState.h"

StateMachine::StateMachine(){}
StateMachine::~StateMachine(){}

void StateMachine::Update(float deltaTime)
{
	if (Stack.size() > 0)
		Stack.top()->OnUpdate(deltaTime);
}

void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if(Stack.size() > 0)
		Stack.top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int newState)
{

}

void StateMachine::PopState()
{

}

void StateMachine::AddState(BaseState * state, int newState)
{
	baseState.Insert(newState, state);
}
