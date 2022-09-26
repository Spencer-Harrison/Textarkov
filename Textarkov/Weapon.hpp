#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"


class Weapon : public Item {
	double minDamage_;
	double maxDamage_;
	//int uses_;
public:
	Weapon() : Item("", 1, 10.0, 1, 1), minDamage_(5 * 1), maxDamage_((1 * 15) * 1) {};
	Weapon(std::string _name, int _level, double _scalingFactor) : Item(_name, _level, ((50 * _level)* _scalingFactor), 1, _scalingFactor), minDamage_((5 * _level)* _scalingFactor), maxDamage_((_level * 15)* _scalingFactor) { }

	virtual ~Weapon() {}
	//accessors
	constexpr double getMinDamage() const { return minDamage_; }
	constexpr double getMaxDamage() const { return maxDamage_; }
	//constexpr int getUses() const { return uses_; }

	//consider adding a magazine object which stores the ammo count for the weapon. 
	//each magazine has a type attribute which associates it with the caliber

	double attack();


};


#endif