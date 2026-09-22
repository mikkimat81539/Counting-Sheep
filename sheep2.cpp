# include <iostream>
# include <vector>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 350
# define SCREEN_HEIGHT 500
# define FPS 60

# define print(x) cout << x << endl;


enum BTN {
	OFF,
	ON
};

struct SHEEP{
	float x;
	float y;
	float width;
	float height;
	float velocity;
	BTN button;
};

void sheep_mvmt(SHEEP& sheep, float dt) {
	sheep.velocity = 200;
	sheep.x -= sheep.velocity * dt;
}


int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Counting Sheep");

	SHEEP sheep;
	sheep.x = 505;
	sheep.y = 250;
	sheep.width = 30;
	sheep.height = 30;


	int sheep_counter = 0;

	vector <SHEEP> sheep_pen = {};


	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();
		
		if (IsKeyPressed(KEY_ENTER)){
			sheep_pen.push_back({sheep.x, sheep.y, sheep.width, sheep.height});

			//sheep.button = ON;
			sheep_counter++;

		}


		print(sheep_pen.size())


		for (int i=0; i < sheep_pen.size(); i++){
			sheep_mvmt(sheep_pen[i], dt);


			if (sheep_pen[i].x < 0){
				sheep_pen.erase(sheep_pen.begin() + i);
				// sheep.button = OFF;
				// sheep.x = 505;
				i--;
			}

		}

			
		// print(sheep_counter)

		// DRAW
		BeginDrawing();
		ClearBackground(Color {0,0,67});


		for (int i=0; i < sheep_pen.size(); i++){
			DrawRectangle(sheep_pen[i].x, sheep_pen[i].y, sheep_pen[i].width, sheep_pen[i].height, WHITE);
		}

		EndDrawing();
	}	

	CloseWindow();

	return 0;
}
