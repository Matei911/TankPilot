#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"
#include "lab_m1/Tema2/PlayerTank.h"
#include "lab_m1/Tema2/WorldBuild.h"
#include "lab_m1/Tema2/EnemyTank.h"

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;


        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        implemented::Camera* camera;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        // TODO(student): If you need any other class variables, define them here.
        float length, width, radians, z_near, z_far;
        bool perspective;
        PlayerTank player;
        WorldBuild world;
        EnemyTank enemy;
            
        float first_enemy_x = 2.0f;
        float first_enemy_z = 2.0f;

        float second_enemy_x = 4.0f;
        float second_enemy_z = -5.0f;

        float third_enemy_x = -5.0f;
        float third_enemy_z = -2.0f;

        struct TankData {
            float x;
            float z;
            bool movingRight;
            float minX;
            float maxX;
        };

        std::vector<TankData> tanks = {
            {2.0f, 2.0f, true, -6.0f, 6.0f},   // First tank
            {4.0f, -5.0f, true, -10.0f, 10.0f}, // Second tank
            {-5.0f, -2.0f, true, -8.0f, 8.0f}    // Third tank (Add more tanks if needed)
        };
        float enemySpeed = 1.0f;

        float turretRotationAngle = 0.0f;

        float timeSinceLastShot = 0.0f;
        const float shootCooldown = 1.0f;

        float x_player = 0.0f;
        float y_player = 0.0f; 
        float z_player = 0.0f;
        float rotation_y = 0;
        struct Projectile
        {
			float x;
			float y;
			float z;
			float speed;
			float time;
			bool active;
            float initialDirectionX;
            float initialDirectionZ;
		};
        Projectile projectile;

        std::vector<Projectile> projectiles;
        float timer_projectile = 0;
    };
}   // namespace m1
