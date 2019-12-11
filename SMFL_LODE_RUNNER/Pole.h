#pragma once
#include"SFML/Graphics.hpp"
#define MAX_POLE_HIGH 18
#define MAX_POLE_WIDTH 32


class Pole {
public:
	bool exit=false;
	bool gameStarted = true;
	int cntOfMoney=7;
	sf::Texture tileSet;
	sf::Texture door;
	sf::Texture city;

	char gamePole[MAX_POLE_HIGH][MAX_POLE_WIDTH] = {
	"E                              ",
	"        $         =            ",
	"WWWWWWWWWWWWWWWWWW=            ",
	"                  =       $    ",
	"                  =WWWWWWWWWWWW",
	" $     =          =++++++++++++",
	"WWWWWWW=          =            ",
	"       =    $     =   =        ",
	"       =WWWWWWWWWWWWWW=        ",
	"       =              =       $",
	"       =              =WWWWWWWW",
	"   =   =        =  $  =        ",
	"   =WWWWWWWWWWWW=WWWWWWW       ",
	"   =    ++++++++=+++++++       ",
	"   =            =              ",
	"   =            =    $         ",
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"###############################"
};
	Pole() {
		tileSet.loadFromFile("resources/tileSet.png");
		door.loadFromFile("resources/door.jpg");
		city.loadFromFile("resources/city.jpg");
	}


	void PoleDraw(sf::RenderWindow& window) {
		    window.clear();
			gameStarted = false;
		
		sf::Sprite pit(tileSet, sf::IntRect(673, 51, 40, 15));
		//-------------------------------------------------------------
		sf::Sprite stairs(tileSet, sf::IntRect(54, 33, 30, 32));
		sf::Sprite map(tileSet, sf::IntRect(12, 210, 30, 30));
		sf::Sprite floor(tileSet, sf::IntRect(11, 165, 30, 30));
		sf::Sprite floor2(tileSet, sf::IntRect(450, 455, 30, 30));
		//------------------------------------------------------------
	    sf::Sprite ExitP(door, sf::IntRect(47, 95, 41, 65));
		//-------------------------------------------------------------
		sf::Sprite money(tileSet, sf::IntRect(655, 291, 20, 20));
		//------------------------------------------------------------
		sf::Sprite Background(city, sf::IntRect(0, 0, 1000, 600));
		window.draw(Background);
		//-------------------------------------------------------------
		for (int i = 0; i <= MAX_POLE_HIGH; i++) {
			for (int j = 0; j <= MAX_POLE_WIDTH; j++) {
				if (gamePole[i][j] == 'W') {
					map.setTexture(tileSet);
					map.setPosition(j * 32, i * 32);
				window.draw(map);
				}
				else if (gamePole[i][j] == '=') {
					stairs.setTexture(tileSet);
					stairs.setPosition(j * 32, i *32);
				window.draw(stairs);
				}
				else if (gamePole[i][j] == '#') {
					floor.setTexture(tileSet);
					floor.setPosition(j * 32, i * 32);
				window.draw(floor);
				}
				else if (gamePole[i][j] == '+') {
					floor2.setTexture(tileSet);
					floor2.setPosition(j * 32, i * 32);
				window.draw(floor2);
				}
				
				else if (gamePole[i][j] == 'E') {
					if (exit) ExitP.setTextureRect(sf::IntRect(167, 95, 41, 65));
						ExitP.setTexture(door);
						ExitP.setPosition(j * 32, i * 32);
				window.draw(ExitP);
				}
				else if (gamePole[i][j] == '$') {
					money.setTexture(tileSet);
					money.setPosition(j * 32, i * 32);
					window.draw(money);
				}
				else if (gamePole[i][j] == 'P') {
					pit.setTexture(tileSet);
					pit.setPosition(j * 32, i * 32+20);
					window.draw(pit);
				}
			}
			if (cntOfMoney == 0) exit = true;
}
		//while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace));
	}
};
