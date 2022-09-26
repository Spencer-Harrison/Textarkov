#include "Player.hpp"

Weapon Player::attackWithPrimaryWeapon() const {
	return primaryWeapon_;
}

Weapon Player::attackWithSecondaryWeapon() const {
	return secondaryWeapon_;
}

void Player::printStats() {
	std::cout << "============= Stats ==============" << std::endl;
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "HP: " << currentHP_ << "/" << maxhp_ << std::endl;
	std::cout << "Level: " << level_ << std::endl;
	std::cout << "Exp: " << experience_ << std::endl;
	std::string primaryDmg = "damage: [";
	std::string temp = std::to_string(primaryWeapon_.getMinDamage());
	temp.erase(temp.find_last_not_of('0') + 1, std::string::npos);
	temp.erase(temp.find_last_not_of('.') + 1, std::string::npos);
	primaryDmg.append(temp);
	primaryDmg.append("-");
	temp = std::to_string(primaryWeapon_.getMaxDamage());
	temp.erase(temp.find_last_not_of('0') + 1, std::string::npos);
	temp.erase(temp.find_last_not_of('.') + 1, std::string::npos);
	primaryDmg.append(temp);
	primaryDmg.append("]");

	std::string secondaryDmg = "damage: [";
	std::string temp2 = std::to_string(secondaryWeapon_.getMinDamage());
	temp2.erase(temp2.find_last_not_of('0') + 1, std::string::npos);
	temp2.erase(temp2.find_last_not_of('.') + 1, std::string::npos);
	secondaryDmg.append(temp2);
	secondaryDmg.append("-");
	temp2 = std::to_string(secondaryWeapon_.getMaxDamage());
	temp2.erase(temp2.find_last_not_of('0') + 1, std::string::npos);
	temp2.erase(temp2.find_last_not_of('.') + 1, std::string::npos);
	secondaryDmg.append(temp2);
	secondaryDmg.append("]");
	std::cout << std::setw(26) << std::left << "Primary:   " + primaryWeapon_.getName() << std::setw(20) << primaryDmg << std::endl;
	std::cout << std::setw(26) << std::left << "Secondary: " + secondaryWeapon_.getName() << std::setw(20) << secondaryDmg << std::endl << std::endl;
	std::cout << "============ Inventory ============\n";
	if (inventory_.size() >= 0) {
		for (auto& item : inventory_) {
			std::cout << "Item: " << std::left << std::setw(15) << item.getName() << "\tCost : " << item.getCost() << "\n";
		}
	}
}

void Player::printInventory() {
	bool inInventory = true;
	size_t counter = 1;
	int playerInput;
	while (inInventory) {
		system("cls");
		counter = 1;
		printStats();
		std::cout << "================ Inventory ================" << std::endl << std::endl;
		if (inventory_.empty()) {
			std::cout << "You have no items in your inventory" << std::endl;
			std::cout << "[0]: to exit" << std::endl;
		}
		else {
			std::cout << "[0]: to exit" << std::endl;
			for (auto& item : inventory_) {
				std::cout << "[" << counter++ << "] Item: " << std::left << std::setw(15) << item.getName() << "\tCost:" << item.getCost() << "\n";
			}
		}
		std::cout << std::endl << "================ Inventory ================" << std::endl;
		std::cout << "Select the weapon you would like to make your primary > ";
		std::cin >> playerInput;
		if (playerInput >= 1 && playerInput <= inventory_.size()) {
			if (inventory_[playerInput - 1].getType() == 1) {
				Item tempInput = inventory_[playerInput - 1];
				Weapon playerSelection(tempInput.getName(), tempInput.getLevel(), tempInput.getScaling());
				if (playerSelection == primaryWeapon_) {

				}
				else if (playerSelection == secondaryWeapon_) {
					Weapon temp = primaryWeapon_;
					primaryWeapon_ = secondaryWeapon_;
					secondaryWeapon_ = temp;
				}
				else {
					primaryWeapon_ = playerSelection;
				}
			}
		}
		else if (playerInput == 0) {
			inInventory = false;
			system("cls");
		}
		else {
			std::cout << "invalid input." << std::endl;
		}
	}
}


void Player::makePurchase(double _amount) {
	money_ -= _amount;
}

//void Player::gainXp(int exp) {
	//FILL THIS IN
//}

void Player::sellItem(int index) {

	money_ += inventory_[index].getCost();
	if (index != inventory_.size() - 1)
	{
		// Beware of move assignment to self
		// see http://stackoverflow.com/questions/13127455/
		inventory_[index] = std::move(inventory_.back());
	}
	inventory_.pop_back();
}


void Player::damage(double _amount) {
	currentHP_ = currentHP_ - _amount;
}



void Player::heal(double _amount) {
	double healedValue = _amount + currentHP_;
	if (healedValue <= maxhp_) {
		currentHP_ = healedValue;
	}
	else {
		currentHP_ = maxhp_;
	}
}

void Player::removeItem(Item _item) {
	auto val = std::find(inventory_.begin(), inventory_.end(), _item);
	inventory_.erase(val);
}

void Player::addItem(Item _item) {
	std::cout << _item.getName() << " has been added to your inventory." << std::endl;
	inventory_.push_back(_item);
}

