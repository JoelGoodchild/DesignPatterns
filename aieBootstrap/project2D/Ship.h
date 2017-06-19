#pragma once
#include "Renderer2D.h"
#include "Entity.h"
#include "Vector2.h"

using namespace aie;

class Ship

{
public:
	Ship();
	~Ship();

	void update(float deltaTime);
	void draw(Renderer2D* m_2dRenderer);

private:
	Texture* sprite;
	float speed;
	float mass = 1;
	float drag = 1;

	Vector2 velocity;
};

