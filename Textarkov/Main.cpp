#include "Game.hpp"


int main() {

	srand(static_cast<unsigned int>(time(NULL)));//rng seed

	//create vendor inventory;
	Vendor shadySal("Shady Sal", "Welcome! my name is ", ", how ya doing? Please my friend, let me show you my finest wares.", 2000.00);
	shadySal.addItem(Weapon("M4A1", 5, 2.0));
	shadySal.addItem(Weapon("SR-25", 7, 4.0));
	shadySal.addItem(Weapon("Combat Knife", 2, 1.3));
	shadySal.addItem(Item("MedKit", 3, 100.0, 2, 50));
	shadySal.addItem(Item("Rations", 1, 10.0, 2, 10));



	Game game;

	Player player = game.createCharacter();
	system("cls");
	while (game.isGameRunning())
	{
		game.mainMenu(player, shadySal);
	}


	return 0;
}