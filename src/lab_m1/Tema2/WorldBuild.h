#pragma once
#include "components/simple_scene.h"
#include "lab_m1/lab4/transform3D.h"
#include "lab_m1/lab5/lab_camera.h"
using namespace std;


class WorldBuild : public  gfxc::SimpleScene
{
	private:
		void WorldBuild::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& objectColor);
	public:
		WorldBuild();
		void BuildingMesh();
		void BuildingRender();
		struct Building {
			float x, z;
		};
		Building building[36];
	protected:
		implemented::Camera* camera;
		glm::mat4 projectionMatrix;
};
