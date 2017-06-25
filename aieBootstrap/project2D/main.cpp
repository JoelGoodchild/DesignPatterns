#include "Application2D.h"
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------------------
int main() 
{
	Application2D* app = new Application2D();
	assert(app);
	app->run("Loading... that's all", 1400, 720, false);
	delete app;

	return 0;
}