#include "lab_m1/Tema2/PlayerTank.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
PlayerTank::PlayerTank()
{
}


PlayerTank::~PlayerTank()
{
}

void PlayerTank::TankMeshes()
{
	//create meshes for the tank components
	Mesh* mesh = new Mesh("TankTrack");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "TankTrack.obj");
	meshes[mesh->GetMeshID()] = mesh;

	mesh = new Mesh("TankBody");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "TankBody.obj");
	meshes[mesh->GetMeshID()] = mesh;

	mesh = new Mesh("TankTurret");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "TankTurret.obj");
	meshes[mesh->GetMeshID()] = mesh;

	mesh = new Mesh("CanonTank");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "CanonTank.obj");
	meshes[mesh->GetMeshID()] = mesh;

	//create mesh for the projectile

	mesh = new Mesh("Projectile");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
	meshes[mesh->GetMeshID()] = mesh;


	Shader* shader = new Shader("Tema2");
	shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "s", "VertexShader.glsl"), GL_VERTEX_SHADER);
	shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "s", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
	shader->CreateAndLink();
	shaders[shader->GetName()] = shader;

	std::cout << "Tank meshes created" << std::endl;

}
void PlayerTank::RenderTank(float x, float z, float rotation_y, float turretRotationAngle)
{
	//render the tank components

	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(x, 0.0f, z);
	modelMatrix *= transform3D::Scale(0.2, 0.2, 0.2);
	modelMatrix *= transform3D::RotateOY(rotation_y);
	RenderMesh(meshes["TankTrack"], shaders["VertexNormal"], modelMatrix);
	//RenderSimpleMesh(meshes["TankTrack"], shaders["Tema2"], modelMatrix, glm::vec3(0.137255f, 0.46863f, 0.137255f));
	
	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(x, 0.0f, z);
	modelMatrix *= transform3D::Scale(0.2, 0.2, 0.2);
	modelMatrix *= transform3D::RotateOY(rotation_y);
	RenderSimpleMesh(meshes["TankBody"], shaders["Tema2"], modelMatrix, glm::vec3(0.237255f, 0.46863f, 0.137255f));

	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(x, 0.0f, z);
	modelMatrix *= transform3D::Scale(0.2, 0.2, 0.2);
	modelMatrix *= transform3D::RotateOY(rotation_y + turretRotationAngle);
	RenderSimpleMesh(meshes["TankTurret"], shaders["Tema2"], modelMatrix, glm::vec3(0.237255f, 0.46863f, 0.137255f));

	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(x, 0.0f, z);
	modelMatrix *= transform3D::Scale(0.2, 0.2, 0.2);
	modelMatrix *= transform3D::RotateOY(rotation_y + turretRotationAngle);
	RenderSimpleMesh(meshes["CanonTank"], shaders["Tema2"], modelMatrix, glm::vec3(0.5f, 0.5f, 0.5f));

}

void PlayerTank::RenderProjectile(float x, float y, float z)
{
	//render the projectile
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(x, y, z);
	modelMatrix *= transform3D::Scale(0.05, 0.05, 0.05);
	RenderSimpleMesh(meshes["Projectile"], shaders["Tema2"], modelMatrix, glm::vec3(0.1f, 0.1f, 0.1f));
}

void PlayerTank::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& objectColor)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// Render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Get shader location for uniform mat4 "Model"
	int location = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Get shader location for uniform mat4 "View"
	location = glGetUniformLocation(shader->program, "View");
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Get shader location for uniform mat4 "Projection"
	location = glGetUniformLocation(shader->program, "Projection");
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// Set object color
	location = glGetUniformLocation(shader->program, "object_color");
	glUniform3fv(location, 1, glm::value_ptr(objectColor));

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->m_VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}

