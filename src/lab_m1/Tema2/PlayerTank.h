#pragma once
#include "components/simple_scene.h"
#include "lab_m1/lab4/transform3D.h"
#include "lab_m1/lab5/lab_camera.h"
using namespace std;


class PlayerTank : public  gfxc::SimpleScene
{
	public:
		PlayerTank();
		~PlayerTank();
		void TankMeshes();
		void RenderTank(float x, float z, float rotation_y, float turretRotationAngle);
		void RenderProjectile(float x, float y, float z);

	private:
		void PlayerTank::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& objectColor);
	
	protected:
		implemented::Camera* camera;
		glm::mat4 projectionMatrix;
};
