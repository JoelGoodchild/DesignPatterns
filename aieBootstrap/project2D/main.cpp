#include "Application2D.h"
#include <iostream>
#include "time.h"

int main() 
{
	srand(time(0));
	Application2D* app = new Application2D();
	app->run("Loading... that's all", 1400, 720, false);
	delete app;

	return 0;
}