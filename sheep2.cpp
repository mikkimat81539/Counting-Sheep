# include <iostream>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define FPS 60

# define print(x) cout << x << endl;

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Opponents");


	// GAME LOOP
	while(!WindowShouldClose()){


		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}	

	CloseWindow();

	return 0;
}
