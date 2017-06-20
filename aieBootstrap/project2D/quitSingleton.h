#pragma once
class quitSingleton
{
protected:
	quitSingleton();
	~quitSingleton();
	static quitSingleton* ptrInstance;

public:
	static quitSingleton* instance();
	void gameQuit();
	bool getQuit();

private:
	bool quitGame;
};

