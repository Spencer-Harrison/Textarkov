#include "Weapon.hpp"


double Weapon::attack() {
	return static_cast<double>(rand() % static_cast<int>((minDamage_ - maxDamage_ + 1) + minDamage_));
}



