#ifndef VENDOR_HPP
#define VENDOR_HPP

#include "Item.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>


class Vendor {
	std::string vendorName_;
	std::string vendorShopPhrase_;
	std::string vendorGreeting_;
	std::vector<Item> inventory_;
	double money_;

public:
	Vendor(std::string _vendorName, std::string _vendorGreeting, std::string _vendorShopPhrase, double _money) : vendorName_(_vendorName), vendorGreeting_(_vendorGreeting), vendorShopPhrase_(_vendorShopPhrase), money_(_money) {}
	~Vendor() {};

	inline std::string vendorName() const { return vendorName_; }
	inline std::string vendorShopPhrase() const { return vendorShopPhrase_; }
	inline std::string vendorGreeting() const { return vendorGreeting_; }
	inline std::vector<Item> inventory() { return inventory_; };
	constexpr double money() const { return money_; }
	inline size_t inventorySize() const { return inventory_.size(); }
	void addItem(Item _item);
	void buyItem(Player& _player, int index);
	void displayShop(Player& _player);
	void purchase(Item item);

};



#endif