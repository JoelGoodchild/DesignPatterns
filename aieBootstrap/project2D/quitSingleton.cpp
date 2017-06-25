#include "quitSingleton.h"

quitSingleton* quitSingleton::ptrInstance = nullptr;
//---------------------------------------------------------------------------------------
quitSingleton::quitSingleton()
{
	quitGame = false;
}
//---------------------------------------------------------------------------------------
quitSingleton::~quitSingleton(){}
//---------------------------------------------------------------------------------------
quitSingleton* quitSingleton::instance()
{
	if (!ptrInstance)
	{
		ptrInstance = new quitSingleton;
	}
	return ptrInstance;
}
//---------------------------------------------------------------------------------------
void quitSingleton::gameQuit()
{
	quitGame = true;
}
//---------------------------------------------------------------------------------------
bool quitSingleton::getQuit()
{
	return quitGame;
}
