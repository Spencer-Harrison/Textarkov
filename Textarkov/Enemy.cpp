#include "Enemy.hpp"

void Enemy::attackWithItem(Player& player) {
	Weapon weapon;
	weapon = player.attackWithPrimaryWeapon();
	player.damage(weapon.attack());
}