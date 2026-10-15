#include "Game2D.h"
#include "Sandbox2D.h"
#include "Sandbox3D.h"
#include "Menu.h"
#include "Death.h"
#include "Scene.h"

int main(){
	InitWindow(1800, 1000, "Yooo0");

	Menu menu;
	Game2D game2D;
	Sandbox2D sandbox2D;
	Sandbox3D sandbox3D;
	Death death;

	Scene currentScene = MENU;
	bool running = true;

	while (running && !WindowShouldClose()){
		BeginDrawing();
		int fps = GetFPS();
    	DrawText(TextFormat("FPS %d", fps), 10, 10, 50, RAYWHITE);

		switch (currentScene){
		case MENU:
			menu.run(currentScene);
			break;
		case GAME_2D:
			game2D.run(currentScene);
			break;
		case SANDBOX_2D:
			sandbox2D.run(currentScene);
			break;
		case SANDBOX_3D:
			sandbox3D.run(currentScene);
			break;
		case DEATH:
			death.run(currentScene);
			break;
		case EXIT:
			running = false;
		}
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}
