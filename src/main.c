#include <raylib.h>

#include "util.h"

int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 900;

    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(screenWidth, screenHeight, "Particles");

    FixedLoop fixedLoop = CreateFixedLoop(30);

    while (!WindowShouldClose())
    {
        // Update logic
        OuterUpdateFixedLoop(&fixedLoop);
        while (IsFixedLoopReady(&fixedLoop))
        {

            InnerUpdateFixedLoop(&fixedLoop);
        }

        // Render
        BeginDrawing();
        {
            ClearBackground(BLACK);

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}