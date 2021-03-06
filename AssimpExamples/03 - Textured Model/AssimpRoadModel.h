#pragma once

#include <Transform.h>
#include <vector>
#include <memory>

#include "MaterialOnlyShader.h"

namespace sess
{

class AssimpRoadModel
{
public:
	struct Mesh
	{
		MaterialOnlyShader::RenderCall Call;
		MaterialOnlyShader::Material Material;
	};

public:
	
	AssimpRoadModel(const std::vector<Mesh>& meshes, const Transform& transform);

	static std::shared_ptr<AssimpRoadModel> LoadFromFile(const char* fName, ComPtr<ID3D11Device> d3dDevice, const Transform& transform);
	bool Update(float dt);
	bool Render(ComPtr<ID3D11DeviceContext> context, MaterialOnlyShader* shader) const;

	AssimpRoadModel(const AssimpRoadModel&) = delete;
	~AssimpRoadModel() = default;

protected:
	std::vector<Mesh> meshes_;
	Transform transform_;
};

};