#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter() {

}


void BaseCharacter::UndoMovement() {
    worldPosition = worldPositionLastFrame;
}

Rectangle BaseCharacter::getCollisionRec() {
    return Rectangle {
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::tick(float deltaTime) {
    worldPositionLastFrame = worldPosition;

    runningTime += deltaTime;
    if(runningTime >= updateTime) {
        animationFrame++;
        runningTime = 0.f;
        if(animationFrame > maxFrame) animationFrame = 0;
    }

    // Update the Movement
    if (Vector2Length(velocity) != 0.0) {
        // Set World Position = World Position + Direction
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    } else {
        texture = idle;
    } 
    velocity = {};

    // Draw the Character
    Rectangle source{animationFrame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}