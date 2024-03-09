#include "lab_m1/Tema2/WorldBuild.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


WorldBuild::WorldBuild()
{

}

void WorldBuild::BuildingMesh()
{
	//create meshes for the buildings
	for (int i = 0; i < 3; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building1.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 3; i < 6; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building2.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 6; i < 9; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}


	for (int i = 9; i < 12; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 12; i < 15; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 15; i < 18; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = static_cast<float>(rand() % 20 + 2);
	}

	for (int i = 18; i < 21; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 21; i < 24; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 24; i < 27; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}

	for (int i = 27; i < 30; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 30; i < 33; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}
	for (int i = 33; i < 36; i++) {
		Mesh* mesh = new Mesh("Building" + std::to_string(i));
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Building3.obj");
		meshes[mesh->GetMeshID()] = mesh;
		building[i].x = -static_cast<float>(rand() % 20 + 2);
		building[i].z = -static_cast<float>(rand() % 20 + 2);
	}
	Mesh* mesh = new Mesh("Plane");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
	meshes[mesh->GetMeshID()] = mesh;
	Shader* shader = new Shader("Tema2");
	shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "s", "VertexShader.glsl"), GL_VERTEX_SHADER);
	shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "s", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
	shader->CreateAndLink();
	shaders[shader->GetName()] = shader;


}
void WorldBuild::BuildingRender()
{
	//render the buildings
	for (int i = 0; i < 9; i++) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= transform3D::Translate(building[i].x, 0.0f, building[i].z);
		modelMatrix *= transform3D::Scale(1, 1, 1);
		RenderSimpleMesh(meshes["Building" + std::to_string(i)], shaders["Tema2"], modelMatrix, glm::vec3(0.184314f, 0.309804f, 0.309804f));
	}
	for (int i = 9; i < 18; i++) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= transform3D::Translate(building[i].x, 0.0f, building[i].z);
		modelMatrix *= transform3D::Scale(1, 1, 1);
		RenderSimpleMesh(meshes["Building" + std::to_string(i)], shaders["Tema2"], modelMatrix, glm::vec3(0.184314f, 0.309804f, 0.309804f));
	}
	for (int i = 18; i < 27; i++) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= transform3D::Translate(building[i].x, 0.0f, building[i].z);
		modelMatrix *= transform3D::Scale(1, 1, 1);
		RenderSimpleMesh(meshes["Building" + std::to_string(i)], shaders["Tema2"], modelMatrix, glm::vec3(0.184314f, 0.309804f, 0.309804f));
	}
	for (int i = 27; i < 36; i++) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= transform3D::Translate(building[i].x, 0.0f, building[i].z);
		modelMatrix *= transform3D::Scale(1, 1, 1);
		RenderSimpleMesh(meshes["Building" + std::to_string(i)], shaders["Tema2"], modelMatrix, glm::vec3(0.184314f, 0.309804f, 0.309804f));
	}
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(0.0, 0.0f, 0.0f);
	modelMatrix *= transform3D::Scale(1.0, 1.0, 1.0);
	RenderSimpleMesh(meshes["Plane"], shaders["Tema2"], modelMatrix, glm::vec3(0.196078f, 0.8f, 0.196078f));
	
}
void WorldBuild::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& objectColor)
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

