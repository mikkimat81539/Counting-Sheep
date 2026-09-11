# include <iostream>
# include <vector>

# include "raylib.h"

using namespace std;

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

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
};

void sheep_draw(SHEEP &name, float x, float y, Color color){
	name.rect = {0, 0, 30, 30};
	name.position = {x, y};
	name.color = color;
}

int main(){
	// SETUP
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sheeps");	

	SHEEP sheep1;
	SHEEP sheep2;

	sheep_draw(sheep1, 300, 500, WHITE);
	sheep_draw(sheep2, 70, 500, GRAY);

	vector<SHEEP> sheep_pen = {sheep1, sheep2};

	// GAME LOOP
	while(!WindowShouldClose()){

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
