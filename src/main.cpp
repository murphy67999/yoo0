#include "Game.h"
#include "Menu.h"
#include "Screen.h"

int main(){
	InitWindow(1700, 1000, "Yooo0");

	Game game;
	game.init();
	Menu menu;
	menu.init();

	Screen currentScreen = MENU;
		
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		switch (currentScreen){
		case MENU:
			menu.update(currentScreen);
			menu.draw();
			break;
		case GAME:
			game.update();
			game.draw();
			break;
		}
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}
