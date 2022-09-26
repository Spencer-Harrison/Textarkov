#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Weapon.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <string.h>


class Player {
	std::string name_;
	int experience_;
	int level_;
	double maxhp_;
	double currentHP_;
	double money_;
	Weapon primaryWeapon_;
	Weapon secondaryWeapon_;

	std::vector<Item> inventory_;

public:
	Player(std::string _name, int _level, Weapon _primaryStarterWeapon, Weapon _secondaryStarterWeapon) : name_(_name), level_(_level), experience_(_level * 25), maxhp_(_level * 25), currentHP_(_level * 25), money_(500), primaryWeapon_(_primaryStarterWeapon), secondaryWeapon_(_secondaryStarterWeapon) {
		inventory_.push_back(_primaryStarterWeapon);
		inventory_.push_back(_secondaryStarterWeapon);
	}

	virtual ~Player() {

	}

	//accessors
	inline std::string name() const { return name_; }
	inline std::vector<Item> inventory() { return inventory_; }
	constexpr double money() const { return money_; }
	constexpr int playerlevel() const { return level_; }
	constexpr double currentHP() const { return currentHP_; }
	constexpr double maxHP() const { return maxhp_; }
	constexpr int EXP() const { return experience_; }
	inline size_t inventorySize() const { return inventory_.size(); }

	//setters
	void setPrimaryWeapon(Weapon wep) { primaryWeapon_ = wep; }
	void setSecondaryWeapon(Weapon wep) { secondaryWeapon_ = wep; }
	constexpr void setLevel(int level);

	//functions
	void heal(double _amount);
	void addItem(Item _item);
	void sellItem(int _index);
	void removeItem(Item _item);
	void printInventory();
	void makePurchase(double _amount);
	void damage(double _amount);
	void gainXp(int exp);
	void printStats();
	Weapon attackWithPrimaryWeapon() const;
	Weapon attackWithSecondaryWeapon() const;


};

#endif