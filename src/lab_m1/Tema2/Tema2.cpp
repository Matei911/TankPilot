#include "lab_m1/Tema2/Tema2.h"

#include <vector>
#include <iostream>

#include "core/engine.h"
#include "utils/gl_utils.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{

    //initialize the player
    player.TankMeshes();

    //initialize the map
    world.BuildingMesh();

    //initialize the enemys
    enemy.TankMeshes();
   
   
}




void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema2::Update(float deltaTimeSeconds)
{
    //render the player
    player.RenderTank(x_player, z_player, rotation_y, turretRotationAngle);

    //render the map
    world.BuildingRender();

    //render the projectiles
    for (int i = 0; i < projectiles.size(); i++) {
        if (projectiles[i].active == true) {
            projectiles[i].time += deltaTimeSeconds;
            projectiles[i].x += 1 * deltaTimeSeconds * projectiles[i].initialDirectionX * projectiles[i].speed;
            projectiles[i].z += 1 * deltaTimeSeconds * projectiles[i].initialDirectionZ * projectiles[i].speed;

            player.RenderProjectile(projectiles[i].x, projectiles[i].y, projectiles[i].z);

            if (projectiles[i].time >= 10) {
                // Set the projectile as inactive or remove it from the vector
                projectiles[i].active = false;
                projectiles.erase(projectiles.begin() + i);
            }
        }
    }

    //render the enemys
    for (auto& tank : tanks) {
        enemy.RenderTank(tank.x, tank.z);

        if (tank.movingRight) {
            tank.x += deltaTimeSeconds * enemySpeed;

            if (tank.x >= tank.maxX) {
                tank.movingRight = false;
            }
        }
        else {
            tank.x -= deltaTimeSeconds * enemySpeed;

            if (tank.x <= tank.minX) {
                tank.movingRight = true;
            }
        }
    }
}

void Tema2::FrameEnd()
{
    DrawCoordinateSystem();

}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    if (window->KeyHold(GLFW_KEY_W)) {
        x_player += 1 * deltaTime * glm::sin(DEGREES(rotation_y + 2.001f));
        z_player += 1 * deltaTime * glm::cos(DEGREES(rotation_y + 2.001f));
    }
    if (window->KeyHold(GLFW_KEY_S)) {

        x_player -= 1 * deltaTime * glm::sin(DEGREES(rotation_y + 2.001f));
        z_player -= 1 * deltaTime * glm::cos(DEGREES(rotation_y + 2.001f));
    }
    if (window->KeyHold(GLFW_KEY_D)) {
        rotation_y -= 0.05 * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_A)) {
        rotation_y += 0.05 * deltaTime;
    }
    static bool spacePressedPrev = false;
    bool spacePressed = window->KeyHold(GLFW_KEY_SPACE);

    timeSinceLastShot += deltaTime;

    if (spacePressed && !spacePressedPrev && timeSinceLastShot >= shootCooldown) {
        timeSinceLastShot = 0.0f;
        //end of the turret distance
        float distanceFactor = 0.5f;

        // Calculate the offset from the tank's position for the projectile
        float xOffset = distanceFactor * glm::sin(DEGREES(rotation_y + 2.001f + turretRotationAngle));
        float zOffset = distanceFactor * glm::cos(DEGREES(rotation_y + 2.001f + turretRotationAngle));

        // Create a new projectile at an offset position from the tank
        Projectile newProjectile;
        newProjectile.active = true;
        newProjectile.time = 0;
        newProjectile.speed = 2;
        newProjectile.x = x_player + xOffset;
        newProjectile.y = 0.3;
        newProjectile.z = z_player + zOffset;
        newProjectile.initialDirectionX = glm::sin(DEGREES(rotation_y + 2.001f + turretRotationAngle));
        newProjectile.initialDirectionZ = glm::cos(DEGREES(rotation_y + 2.001f + turretRotationAngle));

        // Add the new projectile to the list of projectiles
        projectiles.push_back(newProjectile);
    }

    spacePressedPrev = spacePressed;

}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    float sensitivity = -0.0001f;
    turretRotationAngle +=  sensitivity * static_cast<float>(deltaX);
}

void Tema2::OnKeyPress(int key, int mods)
{
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
