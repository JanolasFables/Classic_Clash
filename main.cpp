#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

int main() {
    // Window Variables
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Top Down Game");

    // Map Variables
    Texture2D map = LoadTexture("nature_tileset/second_map.png");
    Vector2 mapPosition{0.0, 0.0};
    const float mapScale{4.0f};

    // Create Instance of Player Character
    Character knight{windowWidth,windowHeight};

    // Create Props
    Prop props[2] {
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };

    Enemy goblin{
        Vector2{800.f, 300.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };

    Enemy slime {
        Vector2{500.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
    };

    Enemy* enemies[]{
        &goblin,
        &slime
    };

    for(auto enemy : enemies) {
        enemy->setTarget(&knight);
    }

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPosition = Vector2Scale(knight.getWorldPosition(), -1.f);

        // Draw the Map
        DrawTextureEx(map, mapPosition, 0.0, mapScale, WHITE);

        // Draw the Props
        for(auto prop : props) {
            prop.Render(knight.getWorldPosition());
        }

        if(!knight.getAlive()) {
            // Character is dead
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        } else {
            // Character is alive
            std::string knightsHealth = "Health: ";
            knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);
            DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        // Call Tick Method
        knight.tick(GetFrameTime());

        // Check Map Bountaries
        if(knight.getWorldPosition().x < 0.f ||
            knight.getWorldPosition().y < 0.f ||
            knight.getWorldPosition().x + windowWidth > map.width * mapScale ||
            knight.getWorldPosition().y + windowHeight > map.height * mapScale) 
        {
            knight.UndoMovement();
        }

        // Check Prop Collision
        for(auto prop : props) {
            if(CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPosition()),knight.getCollisionRec())) {
                 knight.UndoMovement();   
            }
        }

        for(auto enemy : enemies) {
            enemy->tick(GetFrameTime());
        }

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for(auto enemy : enemies) {
                if(CheckCollisionRecs(enemy->getCollisionRec(), knight.getWeaponCollisionRec())) {
                    enemy->setAlive(false);
                }
            }    
        }
        EndDrawing();
    }
    CloseWindow();
}