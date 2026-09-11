# include <iostream>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define print(x) cout << x << endl;

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sheeps");


	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(Color{11, 16, 38});

		EndDrawing();
	}	

	return 0;
}
