#include "raylib.h"

int main (){

    // window dimensions
    int width = 1000;
    int height = 600;

    // circle coordinates
    int circle_x = width / 2;
    int circle_y = height  / 2;
    int circle_radius = 50;
    // circle edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;
    
    // axe coordinates
    int axe_x = 700;
    int axe_y = 0;
    int axe_length = 50;
    //axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;
    // axes speed/direction
    int direction = 10;

    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

    
    
    InitWindow(width,height, "Epic game");

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe){
            DrawText("Game Over!", 400, 200, 20, RED);
        } else {
        // game logic starts

        // update the edges
        int l_circle_x = circle_x - circle_radius;
        int r_circle_x = circle_x + circle_radius;
        int u_circle_y = circle_y - circle_radius;
        int b_circle_y = circle_y + circle_radius;
        int l_axe_x = axe_x;
        int r_axe_x = axe_x + axe_length;
        int u_axe_y = axe_y;
        int b_axe_y = axe_y + axe_length;
        // update collision with axe
        collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

        DrawCircle(circle_x,circle_y,circle_radius,BLUE);
        DrawRectangle(axe_x,axe_y,axe_length,axe_length,RED);

        // move the axe
        axe_y += direction;
        
        // whenever axe_y goes to the edge of the window direction will reverse
        if(axe_y > height || axe_y < 0){
            // when axe is moving down the direction is positive, when upwards direction is negative
            direction = -direction;
        }

        // move right if keydown and circle within window
        if(IsKeyDown(KEY_D) && circle_x < width) {
            circle_x += 10;
        }

        // move left
        if(IsKeyDown(KEY_A) && circle_x > 0){
            circle_x -= 10;
        }

        // game logic ends
        }
        EndDrawing();
    }
}