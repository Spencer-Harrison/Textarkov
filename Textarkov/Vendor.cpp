#include "Vendor.hpp"


void Vendor::addItem(Item _item) {
	inventory_.push_back(_item);
}

void Vendor::buyItem(Player& _player, int index) {
	if (_player.money() >= inventory_.at(index).getCost()) {
		std::cout << "You have purchased a " << inventory_.at(index).getName() << " for: $" << inventory_.at(index).getCost() << " from " << vendorName() << std::endl;
		_player.addItem(inventory_.at(index));
		_player.makePurchase(inventory_.at(index).getCost());
		money_ += inventory_.at(index).getCost();
		if (index != inventory_.size() - 1)
		{
			// Beware of move assignment to self
			// see http://stackoverflow.com/questions/13127455/
			inventory_[index] = std::move(inventory_.back());
		}
		inventory_.pop_back();
	}
	else {
		std::cout << "You dont have enough money.";
	}

}

void Vendor::displayShop(Player& _player) {
	size_t counter = 1;
	std::cout << std::endl;
	if (inventory_.empty()) {
		std::cout << "Aw shit, nothing for sale right now, check back later..." << std::endl << std::endl;
	}
	else {
		std::cout << "[0]: to exit" << std::endl;
		for (auto& item : inventory_) {
			std::cout << "[" << counter++ << "]" << "Item Name: " << std::left << std::setw(15) << item.getName() << " Cost: " << std::setw(15) << item.getCost() << "\n";
		}
		std::cout << "[" << counter++ << "]" << "Open inventory" << "\n";
		std::cout << "[" << counter << "]" << "Sell Items" << "\n";
	}
	std::cout << "============== Shop ==============" << std::endl << std::endl;
	std::cout << "So, what will it be?[1-" << inventorySize() + 1 << "]: ";
}

void Vendor::purchase(Item item) {
	inventory_.push_back(item);
	money_ -= item.getCost();
}


