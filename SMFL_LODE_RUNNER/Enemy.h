#pragma once
#include "Base.h"


class Enemy :virtual public Base {
	bool isInPit;
public:
	
	void Move(Pole& gamep, Base& obj)override;
	void Draw(sf::RenderWindow& window)override;

	Enemy() :isInPit(false) { characterTexture.loadFromFile("resources/enemy.png"); setLoss(0); setMaxLoss(5); };
	Enemy(float X, float Y, float speed) :Enemy() { setX(X); setY(Y); setSpeed(speed); }
	~Enemy() {};
};