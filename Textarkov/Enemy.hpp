#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Player.hpp"

class Enemy : public Player {

	double scalingFactor_;
public:
	//, Weapon("Kitchen Knide", 1, 10.0, 100, 0.8), Weapon("Rock", 1, 1.0, 10, 0.9)
	Enemy(std::string _name, int _level, double _scalingFactor) : Player(_name, _level, Weapon("Hunting Knife", 1, 1.1), Weapon("Rock", 1, 0.9)), scalingFactor_(_scalingFactor) { }
	virtual ~Enemy() {

	};
	//functions
	void attackWithItem(Player& player);

};


#endif