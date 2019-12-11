#pragma once
#include <SFML/Graphics.hpp>
#define cnt_of_menu_Puncts 5
#include<vector>
#include<fstream>
#include<algorithm>
#include"Game.h"

class Menu {
	int selected;
	std::vector<Player> rateList;
	bool isTextEnter;

    sf::Font menuFont;
	sf::Text menuText[cnt_of_menu_Puncts];
    std::multimap<std::string,int> Raiting;
public:
	int getSelected()const { return selected; }
	bool getIsEntered()const{return isTextEnter;}
	std::vector<Player> getList()const { return rateList; }

	void isEntered(bool yn) { isTextEnter = yn; }
	void PrintMenu(sf::RenderWindow& window);
	void printSelected(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void menuStart();
	void PrintRaiting(sf::RenderWindow& window);
	void CompareRaiting(Player& pl1);
	void getNickname(sf::RenderWindow& window, sf::Event& event, sf::String& nickname);

    Menu() :selected(),isTextEnter(true) {};
	Menu(float width, float height);
	~Menu();
};


