#ifndef GAME_HPP
#define GAME_HPP
#include "Vendor.hpp"
#include "Weapon.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
#include <algorithm>
#include <random>
#include <conio.h>

class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void mainMenu(Player& player, Vendor& vendor);
	void adventureMenu(Player& player);
	void restMenu(Player& player);
	void shopMenu(Player& player, Vendor& vendor);
	void shopSellMenu(Player& player, Vendor& vendor);
	Player createCharacter();
	std::vector<std::string> locations_;
	std::vector<Enemy> angryCivilians_;
	std::vector<Enemy> beatCops_;
	std::vector<Enemy> sheriffs_;
	std::vector<Enemy> pmcs_;
	std::vector<Enemy> Brett_;


	//accessors
	constexpr bool isGameRunning() const { return gameRunning_; }

private:
	int playerInput_;
	int sleepTime_;
	bool gameRunning_;
	bool inShop_;
	bool inRest_;
	bool inAdventure_;

};

#endif


