# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define FPS 60

# define print(x) cout << x << endl;

enum STATE {
	IDLE,
	LEFT,
	RIGHT
};

struct SHEEP {
	Rectangle rect;
	Vector2 position;
	Color color;
	STATE state;
	float velocity;
};

void sheep_draw(SHEEP &name, float x, float y, Color color){
	name.rect = {0, 0, 30, 30};
	name.position = {x, y};
	name.color = color;
}

float sheep_mvmt(SHEEP &object, float dt){
	object.velocity = 70;

	object.position.x += object.velocity * dt;

	// STATE pick = STATE((rand() % 2) + 1);

	/*if (pick == RIGHT){
		object.position.x += object.velocity * dt;
		object.state = pick;
		return object.state;
	}


	else if (pick == LEFT){
		object.position.x -= object.velocity * dt;
		object.state = pick;
		return object.state;
	}*/

	return object.position.x;

}

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sheeps");	

	// Define Sheeps
	SHEEP sheep1;
	SHEEP sheep2;

	sheep_draw(sheep1, 300, 500, WHITE);
	sheep_draw(sheep2, 70, 500, GRAY);

	sheep1.state = IDLE;

	int sheep_counter = 0; // this allows me to start and stop movement of sheep
	
	srand(time(0)); // use current time as seed for random generator

	STATE rand_state = STATE((rand() % 2) + 1);

	// FPS
	SetTargetFPS(FPS); // 60 Frames every second

	// GAME LOOP
	while(!WindowShouldClose()){
		// Delta Time
		float dt = GetFrameTime();

		sheep_counter++; // increment counter
		
		if (sheep_counter >= 120 && sheep1.state == IDLE){
			sheep1.state = RIGHT;
		}

		else if (sheep1.state != IDLE){
			sheep_mvmt(sheep1, dt);
		
			if (sheep_counter == 240){
				sheep1.state = IDLE;
				sheep_counter = 0;
			}
		}

		vector<SHEEP> sheep_pen = {sheep1, sheep2};


		// DRAW
		BeginDrawing();
		ClearBackground(Color{11, 16, 38});

		for (int i=0; i < sheep_pen.size(); i++){
			DrawRectangle(sheep_pen[i].position.x, sheep_pen[i].position.y, sheep_pen[i].rect.width, sheep_pen[i].rect.height, sheep_pen[i].color);
		}

		EndDrawing();
	}	

	return 0;
}
