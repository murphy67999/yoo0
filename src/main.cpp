#include "Game2D.h"
#include "Game3D.h"
#include "Menu.h"
#include "Death.h"
#include "Scene.h"

int main(){
	InitWindow(1800, 1000, "Yooo0");

	Game2D game2D;
	Game3D game3D;
	Menu menu;
	Death death;

	Scene currentScene = MENU;
	bool running = true;

	while (running && !WindowShouldClose()){
		BeginDrawing();
		switch (currentScene){
		case MENU:
			menu.update(currentScene);
			menu.draw();
			break;
		case GAME_2D:
			game2D.update(currentScene);
			game2D.draw();
			break;
		case GAME_3D:
			game3D.update(currentScene);
			game3D.draw();
			break;
		case DEATH:
			death.update(currentScene);
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
