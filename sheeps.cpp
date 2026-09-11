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
	STATE state = IDLE;
	float velocity;
};

void sheep_draw(SHEEP &name, float x, float y, Color color){
	name.rect = {0, 0, 30, 30};
	name.position = {x, y};
	name.color = color;
}


void sheep_mvmt(SHEEP &sheep, int &counter, STATE &rand_state, float dt){
	counter++; // increment counter

	if (counter >= 120 && sheep.state == IDLE){
		sheep.state = rand_state;
	}

	else if (sheep.state != IDLE){
		if (sheep.state == RIGHT){
			sheep.position.x += sheep.velocity * dt;

			if (sheep.position.x > SCREEN_WIDTH - sheep.rect.width){
				sheep.state = LEFT;
			}
		}

		else if (sheep.state == LEFT){
			sheep.position.x -= sheep.velocity * dt;

			if (sheep.position.x < 0 + sheep.rect.width){
				sheep.state = RIGHT;
			}
		}


		if (counter == 240){
			sheep.state = IDLE;
			counter = 0;
			STATE* ptr = &rand_state; // pointer for rand_state

			*ptr = STATE((rand() % 2) + 1); // redine the rand_state that I am reference
			//print("\n\nTHE POINTER")
			//print(*ptr)
		}
	}

	sheep.velocity = 50;

}

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sheeps");	

	// Define Sheeps
	SHEEP sheep1;
	SHEEP sheep2;

	sheep_draw(sheep1, 300, 500, WHITE);
	sheep_draw(sheep2, 70, 500, GRAY);

	int sheep_counter = 0; // this allows me to start and stop movement of sheep

	srand(time(0)); // use current time as seed for random generator

	STATE rand_state = STATE((rand() % 2) + 1); // grab random state for sheep
	// print(rand_state)

	// FPS
	SetTargetFPS(FPS); // 60 Frames every second

	// GAME LOOP
	while(!WindowShouldClose()){
		// Delta Time
		float dt = GetFrameTime();

		// Vector contain all sheeps
		vector<SHEEP> sheep_pen = {sheep1, sheep2};

		sheep_mvmt(sheep1, sheep_counter, rand_state, dt);


		/*sheep_counter++; // increment counter
		
		if (sheep_counter >= 120 && sheep1.state == IDLE){
			sheep1.state = rand_state;
		}

		else if (sheep1.state != IDLE){
			if (sheep1.state == RIGHT){
				sheep1.position.x += sheep1.velocity * dt;

				if (sheep1.position.x > SCREEN_WIDTH - sheep1.rect.width){
					sheep1.state = LEFT;
				}
			}

			else if (sheep1.state == LEFT){
				sheep1.position.x -= sheep1.velocity * dt;

				if (sheep1.position.x < 0 + sheep1.rect.width){
					sheep1.state = RIGHT;
				}
			}


			if (sheep_counter == 240){
				sheep1.state = IDLE;
				sheep_counter = 0;
				STATE* ptr = &rand_state; // pointer for rand_state

				*ptr = STATE((rand() % 2) + 1); // redine the rand_state that I am reference
				//print("\n\nTHE POINTER")
				//print(*ptr)
			}
		}*/



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
