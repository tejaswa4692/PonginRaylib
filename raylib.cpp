#include "raylib.h"
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <string.h>
using namespace std;


int score = 0;

struct vec2{
    int x;
    int y;
};


class paddle{  
public:
    vec2 position = {20, 300};
    int width = 20;
    int height = 200;
    int speed = 15;

    int drawpaddle(){
        DrawRectangle(position.x, position.y, width, height, DARKBLUE);
        return 0;
    }
    int updatepositionup(){
        if(IsKeyDown(KEY_W) && position.y > 0){
            position.y -= speed;
        }

        if(IsKeyDown(KEY_S) && position.y < GetScreenHeight() - height){
            position.y += speed;
        }
        return 0;
    }
};





class ball{
public:
    vec2 position = {200, 60};
    vec2 speed = {10, 10};
    int radius = 20;
    int drawball(){
        DrawCircle(position.x, position.y, radius, MAROON);
        return 0;
    }
    int updtateposition(){
        position.y += speed.y;
        position.x += speed.x;

        if(position.x > GetScreenWidth() - radius || position.x < 0 + radius){
            if(position.x < 0 + radius){
                if(score > 0){
                    score -= 1;
                }
            }
            speed.x = -speed.x;
        }
        if(position.y > GetScreenHeight() - radius || position.y < 0 + radius){
            speed.y = -speed.y;
        }
        return 0;
    }

    int checkcollisonwithpaddle(paddle mypaddle){

        if(position.x - radius <= mypaddle.position.x + mypaddle.width){
            if(position.y >= mypaddle.position.y && position.y <= mypaddle.position.y + mypaddle.height){
                speed.x = -speed.x;
                score += 1;
            }
        }
        
        return 0;
    }

};


class paddle2{
  public:
    int hello;
    
};


int main()
{
    paddle mypaddle;    
    ball myball;
    InitWindow(1024, 720, "raylib + C++ + VS Code");
    SetTargetFPS(60);



    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(to_string(score).c_str(), 500, 10, 50, BLACK);

        mypaddle.drawpaddle();
        mypaddle.updatepositionup();
        myball.drawball();
        myball.updtateposition();
        myball.checkcollisonwithpaddle(mypaddle);

        if(score >= 20){
            DrawText("You Win!", 500, 360, 80, GREEN);
        }
        EndDrawing();
    
        

    }

    CloseWindow();
    return 0;
}
