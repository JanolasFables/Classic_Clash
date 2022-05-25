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

    // Enemy Array
    int enemiesAlive{40};

    // Goblin Enemies
    Enemy goblin1{Vector2{800.f, 300.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin2{Vector2{900.f, 400.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin3{Vector2{1000.f, 500.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin4{Vector2{1100.f, 600.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin5{Vector2{1200.f, 700.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin6{Vector2{1300.f, 800.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin7{Vector2{1400.f, 900.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin8{Vector2{1500.f, 1000.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin9{Vector2{1600.f, 1100.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin10{Vector2{1700.f, 1200.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin11{Vector2{1800.f, 1300.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin12{Vector2{1900.f, 1400.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin13{Vector2{2000.f, 1500.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin14{Vector2{2100.f, 1600.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin15{Vector2{2200.f, 1700.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin16{Vector2{2300.f, 1800.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin17{Vector2{2400.f, 1900.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin18{Vector2{2500.f, 2000.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin19{Vector2{2600.f, 2100.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin20{Vector2{2700.f, 2200.f},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};

    // Slime Enemies
    Enemy slime1 {Vector2{500.f, 700.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime2 {Vector2{600.f, 800.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime3 {Vector2{700.f, 900.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime4 {Vector2{800.f, 1000.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime5 {Vector2{900.f, 1100.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime6 {Vector2{1000.f, 1200.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime7 {Vector2{1100.f, 1300.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime8 {Vector2{1200.f, 1400.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime9 {Vector2{1300.f, 1500.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime10 {Vector2{1400.f, 1600.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime11 {Vector2{1500.f, 1700.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime12 {Vector2{1600.f, 1800.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime13 {Vector2{1700.f, 1900.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime14 {Vector2{1800.f, 2000.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime15 {Vector2{1900.f, 2100.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime16 {Vector2{2000.f, 2200.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime17 {Vector2{2100.f, 2300.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime18 {Vector2{2200.f, 2400.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime19 {Vector2{2300.f, 2500.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime20 {Vector2{2400.f, 2600.f},LoadTexture("characters/slime_idle_spritesheet.png"),LoadTexture("characters/slime_run_spritesheet.png")};

    Enemy* enemies[]{
        &goblin1,&goblin2,&goblin3,&goblin4,&goblin5,&goblin6,&goblin7,&goblin8,&goblin9,&goblin10,
        &goblin11,&goblin12,&goblin13,&goblin14,&goblin15,&goblin16,&goblin17,&goblin18,&goblin19,&goblin20,
        &slime1,&slime2,&slime3,&slime4,&slime5,&slime6,&slime7,&slime8,&slime9,&slime10,
        &slime11,&slime12,&slime13,&slime14,&slime15,&slime16,&slime17,&slime18,&slime19,&slime20
    };

    // Sets enemy target to player
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

        // 
        if(!knight.getAlive() && enemiesAlive > 0) {
            // Character is dead
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        } else if(knight.getAlive() && enemiesAlive <= 0) {
            DrawText("You Win!", 55.f, 45.f, 40, RED);
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

            // ISSUE HERE

            enemy->tick(GetFrameTime());
        }

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for(auto enemy : enemies) {
                if(CheckCollisionRecs(enemy->getCollisionRec(), knight.getWeaponCollisionRec())) {
                    enemy->setAlive(false);
                    enemiesAlive--;
                }
            }    
        }
        EndDrawing();
    }
    CloseWindow();
}