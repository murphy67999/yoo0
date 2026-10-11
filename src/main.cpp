#include "Game.h"
#include "Menu.h"
#include "Death.h"
#include "Screen.h"

int main(){
	InitWindow(1700, 1000, "Yooo0");

	Game game;
	game.init();
	Menu menu;
	menu.init();
	Death death;
	death.init();

	Screen currentScreen = MENU;
	bool running = true;

	SetTargetFPS(60);

	while (running && !WindowShouldClose())
	{
		BeginDrawing();
		switch (currentScreen){
		case MENU:
			menu.update(currentScreen);
			menu.draw();
			break;
		case GAME:
			game.update(currentScreen);
			game.draw();
			break;
		case DEATH:
			death.update(currentScreen);
			death.draw();
			break;
		case EXIT:
			running = false;
		}
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}
