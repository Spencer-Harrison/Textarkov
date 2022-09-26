#include "Game.hpp"

Game::Game() {
	playerInput_ = 0;
	sleepTime_ = 150;
	gameRunning_ = true;
	inShop_ = true;
	inRest_ = true;
	inAdventure_ = true;
	locations_.push_back("n old Foxhole! You slide down one of the walls and find an old rotting bench to sit on.");
	locations_.push_back(" Fallen Tree! You eye a comfortable spot on some dry moss and take a seat.");
	locations_.push_back(" Ravine! Too scared to look over the edge you make camp by a nearby rock.");
	locations_.push_back(" River! You take your shoes off and dip your feet in the water. You spot a deer across the river.");

	angryCivilians_.push_back(Enemy("Disgruntled Civilian", 1, 1.05));
	angryCivilians_.push_back(Enemy("Angry Civilian", 2, 1.05));
	angryCivilians_.push_back(Enemy("Very Angry Civilian", 3, 1.05));

	angryCivilians_.push_back(Enemy("Beat Cop", 4, 1.15));
	angryCivilians_.push_back(Enemy("Officer Smith", 5, 1.15));
	angryCivilians_.push_back(Enemy("Officer Jenkins", 6, 1.15));

	angryCivilians_.push_back(Enemy("Sheriff Spencer", 7, 1.25));
	angryCivilians_.push_back(Enemy("Sheriff Ryan", 8, 1.25));
	angryCivilians_.push_back(Enemy("Sheriff Dan", 9, 1.25));


	pmcs_.push_back(Enemy("PMC Connery", 10, 1.50));
	pmcs_.push_back(Enemy("PMC Ghost", 11, 1.50));
	pmcs_.push_back(Enemy("Mountain Man Darty", 12, 1.50));

	Brett_.push_back(Enemy("Gunner Rogers", 13, 1.75));
	Brett_.push_back(Enemy("Master Bombardier Rogers", 14, 1.75));
	Brett_.push_back(Enemy("Warrant Rogers", 15, 1.75));
	Brett_.push_back(Enemy("Master Remy", 16, 1.75));
}

Game::~Game() {

}


void Game::adventureMenu(Player& player) {

	while (inAdventure_) {

	}
}

void Game::shopSellMenu(Player& player, Vendor& vendor) {
	int playerInput = 0;
	int counter = 1;
	bool selling = true;
	while (selling) {
		counter = 1;
		system("cls");
		std::cout << "============== Sell Menu ==============" << std::endl << std::endl;
		if (player.inventory().empty()) {
			std::cout << "You have no items in your inventory" << std::endl;
			std::cout << "[0]: to exit" << std::endl;
		}
		else {
			for (auto& item : player.inventory()) {
				std::cout << "[" << counter++ << "]Item: " << item.getName() << "\tCost:" << item.getCost() << "\n";
			}
			std::cout << "[0]: to exit" << std::endl;
		}
		std::cout << std::endl << "============== Inventory ==============" << std::endl << std::endl;
		std::cout << "> ";
		std::cout << "What do you want to sell? > ";
		std::cin >> playerInput;
		system("cls");
		if (playerInput >= 1 && playerInput <= player.inventorySize()) {
			std::cout << "you sold a " << player.inventory().at(playerInput - 1).getName() << std::endl;
			vendor.purchase(player.inventory().at(playerInput - 1));
			player.sellItem(playerInput - 1);

		}
		else if (playerInput == 0) {
			selling = false;
		}
		else {
			std::cout << "invalid input\n";
		}
	}
}

void Game::shopMenu(Player& player, Vendor& vendor) {
	system("cls");
	size_t counter = 0;
	while (inShop_) {
		std::cout << "\n" << vendor.vendorGreeting() << vendor.vendorName() << vendor.vendorShopPhrase() << std::endl << std::endl;
		std::cout << "============== Shop ==============\n";
		std::cout << "Your funds $" << player.money() << std::endl;
		std::cout << "Vendors funds $" << vendor.money();
		vendor.displayShop(player);
		std::cin >> playerInput_;
		std::cout << std::endl;
		system("cls");
		if (playerInput_ >= 1 && playerInput_ <= vendor.inventorySize()) {
			vendor.buyItem(player, playerInput_ - 1);
			Sleep(sleepTime_);
		}
		else if (playerInput_ == 0) {
			inShop_ = false;
		}
		else if (playerInput_ == vendor.inventorySize() + 1) {
			player.printInventory();
		}
		else if (playerInput_ == vendor.inventorySize() + 2) {
			shopSellMenu(player, vendor);
		}
		else {
			++counter;
			if (counter > 5) {
				std::cout << "I told you I dont carry that.\nJust pick something on the damm menu..." << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Sorry dont have that in stock.." << std::endl;
			Sleep(sleepTime_);
			std::cout << std::endl;
		}
	}
}


void Game::restMenu(Player& player) {
	system("cls");
	int locationIndex = rand() % (0 - 3 + 1) + 0;
	while (inRest_) {
		player.printStats();
		std::cout << "============== Rest ==============\n\n";
		std::cout << "You stumble upon a" << locations_[locationIndex] << "\n";
		std::cout << "[0]: Leave" << std::endl;
		int counter = 1;
		std::vector<Item> healInventory;
		for (Item item : player.inventory()) {
			if (item.getType() == 2) {
				std::cout << "[" << counter++ << "]" << ": Use " << item.getName() << " to heal: " << item.healAmount() << std::endl;
				healInventory.push_back(item);
			}
		}
		std::cout << "============== Rest ==============\n\n";
		std::cout << "What do you want to do?[0-1] > ";
		std::cin >> playerInput_;
		system("cls");
		std::cout << std::endl;
		if (playerInput_ == 0) {
			inRest_ = false;
		}
		else if (playerInput_ >= 1 && playerInput_ <= healInventory.size()) {
			double healAmount = healInventory.at(playerInput_ - 1).healAmount();
			player.heal(healAmount);
			std::cout << "You take out and use your " << healInventory.at(playerInput_ - 1).getName() << ". You recover " << healAmount << " health.\n\n";
			player.removeItem(healInventory.at(playerInput_ - 1));
			healInventory.erase(std::find(healInventory.begin(), healInventory.end(), healInventory.at(playerInput_ - 1)));

		}
	}
	inRest_ = true;
}

Player Game::createCharacter() {
	std::string playerName;
	std::cout << "What is your name? : ";
	std::cin >> playerName;
	std::cout << std::endl;
	return Player(playerName, 1, Weapon("Kitchen Knife", 1, 1.0), Weapon("Wooden Plank", 1, 1.1));
}

void Game::mainMenu(Player& player, Vendor& vendor) {
	system("cls");
	player.printStats();
	std::cout << "\n============ Main Menu ============" << std::endl;
	std::cout << "0: Exit Game" << std::endl;
	std::cout << "1: Go Adventure" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Rest" << std::endl;
	std::cout << "4: Inventory" << std::endl;
	std::cout << "============ Main Menu ============" << std::endl;
	std::cout << "What do you want to do?[0-4] > ";
	std::cin >> playerInput_;
	std::cout << std::endl;
	Sleep(sleepTime_);
	switch (playerInput_) {
	case 0://quit
		gameRunning_ = false;
		break;
	case 1://adventure

		break;
	case 2://shop
		shopMenu(player, vendor);
		Sleep(sleepTime_);
		system("cls");
		break;
	case 3://rest
		restMenu(player);
		Sleep(sleepTime_);
		system("cls");
		break;
	case 4://Inventory
		player.printInventory();
		Sleep(sleepTime_);
		system("cls");
		break;
	default:
		std::cout << "invalid input enter value between 0-3" << std::endl;
		break;
	}
	std::cout << std::endl;
}

