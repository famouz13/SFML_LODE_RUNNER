#pragma once
#include"SFML/Graphics.hpp"
#include"Player.h"
#include"Enemy.h"
#include<iostream>

class Game {
	Pole gamep;
	//Player pl1;
	Enemy en1;
	Enemy en2;
	Enemy en3;
	Enemy en4;
	bool isGameEnded;
public:
    void Play(sf::RenderWindow& window, Player& pl1);
	void initGame(Player& pl1);
	void Pause(sf::RenderWindow& window);
    Game():gamep(),isGameEnded() {};
	~Game() {};
};




