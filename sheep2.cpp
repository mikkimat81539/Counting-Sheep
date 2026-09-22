# include <iostream>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 350
# define SCREEN_HEIGHT 500
# define FPS 60

# define print(x) cout << x << endl;

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Counting Sheep");


	// GAME LOOP
	while(!WindowShouldClose()){


		// DRAW
		BeginDrawing();
		ClearBackground(Color {0,0,67});

		EndDrawing();
	}	

	CloseWindow();

	return 0;
}
