#include <raylib.h> // HISTORY [ Love2D(Lua) -3 rewrites- -> CPP + Raylib -> {YOU ARE HERE}C + Raylib ] HGM Iskander Pong clone.
int main() {
	SetConfigFlags(FLAG_VSYNC_HINT); // Enable V-SYNC.
	InitWindow(1280, 720, "PONC");
	SetTargetFPS(60);
	// Set all game variables.
	// Player paddle vars.
	int plPosX = 10;
	int plPosY = 285;
	// Enemy paddle vars.
	int enPosX = 1260;
	int enPosY = 285;
	// Paddle shared vars.
	int paSizX = 10;
	int paSizY = 150;
	// Ball vars.
	int baPosX = 22;
	int baPosY = 356;
	int baSizA = 8;
	int baVelX = 2;
	int baVelY = GetRandomValue(-2, 2);
	// Main game loop.
	while (!WindowShouldClose()) {
		// Player paddle movement.
		if ((IsKeyDown(KEY_UP)) && (plPosY > 5)) plPosY -= 2;
		else if ((IsKeyDown(KEY_DOWN)) && (plPosY + 150 < 715)) plPosY += 2;
		// Enemy paddle movement.
		if (baPosX > 640) {
			if ((enPosY + 70 > baPosY) && (enPosY > 5)) enPosY -= 2;
			else if ((enPosY + 80 < baPosY) && (enPosY + 150 < 715)) enPosY += 2; }
		// Paddle - Ball collison.
		if ((baPosX <= plPosX + 10) && (baPosY >= plPosY) && (baPosY <= plPosY + paSizY)) baVelX = -baVelX;
		else if ((baPosX >= enPosX - 10) && (baPosY >= enPosY) && (baPosY <= enPosY + paSizY)) {
 			baVelX = -baVelX;
			baVelY = GetRandomValue(-2, 2); }
		// Edge - Ball collsion.
		if (baPosY < 5) baVelY = -baVelY;
		else if (baPosY + 8 > 715) baVelY = -baVelY;
		// Ball movement and Game Over logic.
		if ((baPosX > 10) && (baPosX < 1270)) {
			baPosX += baVelX;
			baPosY += baVelY;
		} else { break; }
		// Draw to screen.
		BeginDrawing();
		ClearBackground(BLACK);
		// Player paddle
		DrawRectangle(plPosX, plPosY, paSizX, paSizY, RAYWHITE);
		// Enemy paddle.
		DrawRectangle(enPosX, enPosY, paSizX, paSizY, RAYWHITE);
		// Ball.
		DrawRectangle(baPosX, baPosY, baSizA, baSizA, RAYWHITE);
		EndDrawing();
	}
}
