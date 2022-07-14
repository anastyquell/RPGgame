#include "Character.h"
#include "File.h"
#include "Game.h"
#include "Menu.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "Ukrainian");
	
	int so, x;
	Menu menu;
	Game* game = NULL;
	so = menu.startMenu();
	Magician* mag = new Magician(file->Load());
	if (mag && so == 2) {
		game = new Game(mag);
	}
	else {
		game = new Game();
	}
	
	switch (so)
	{
	case 1:
		x = menu.educationOrBegin();
		if (x == 1) {
			game->educationPart1();
			game->battle(4, 1000, 500);
			game->educationPart2();
			game->mainMenu();
		}
		else {
			game->mainMenu();
		}
		break;
	case 2:
		game->mainMenu();
		break;
	case 3:
		break;
	}
}


/*int main()
{
    auto mag = new Magician(3, 3, 3, 3, 3);

    auto fire = mag->UseFireMagic();
    std::cout << mag << std::endl;
    auto* file = new File<Magician>("", "data.bin");
    //cout << "Save = " << file->Save(*mag) << endl;
    cout << "Load = ";
    mag = new Magician(file->Load());
    std::cout << mag << std::endl;
    return 0;
}

*/