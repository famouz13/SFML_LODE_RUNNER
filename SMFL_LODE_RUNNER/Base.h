#pragma once
#include"SFML/Graphics.hpp"
#include<string.h>
#include"Pole.h"

class Base {
	float X;
	float Y;
	float speed;
	int direction;
	bool isAlive;
protected:
	sf::Sprite characterSprite;
	sf::Texture characterTexture;
	int  Loss,MaxLoss;
public:
	int getLoss()const { return Loss; }
	int getMaxLoss()const { return MaxLoss; }
	float getX()const { return X; }
	float getY()const { return Y; }
	float getSpeed()const { return speed; }
	int getDirection()const { return direction; }
	bool is_Alive()const { return isAlive; }

	void setMaxLoss(int ls) { MaxLoss = ls; }
	void setLoss(int ls) { Loss = ls; }
	void setIsAlive(bool is_al) { isAlive = is_al; }
    void setX(float x) { X = x; }
	void setY(float y) { Y = y;}
	void setSpeed(float nSpeed) { speed = nSpeed; }
	void setDirection(int dir) { direction = dir; }

	virtual void Move(Pole& gamep, Base&obj) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	Base() :X(), Y(), speed(), direction(),Loss(),MaxLoss() {};
	~Base() {};
};



