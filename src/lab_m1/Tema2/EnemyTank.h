#pragma once
#include "components/simple_scene.h"
#include "lab_m1/lab4/transform3D.h"
#include "lab_m1/lab5/lab_camera.h"
using namespace std;


class EnemyTank : public  gfxc::SimpleScene
{
	public:
		EnemyTank();
		~EnemyTank();
		void TankMeshes();
		void RenderTank(float x, float z);

	private:
		void EnemyTank::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& objectColor);
	
	protected:
		implemented::Camera* camera;
		glm::mat4 projectionMatrix;
};
