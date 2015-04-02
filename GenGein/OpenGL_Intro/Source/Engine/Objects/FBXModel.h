#pragma once
#include <glm\glm.hpp>
#include <FBXFile.h>
#include "BaseObject.h"

typedef unsigned int uint;

class TextureLoader;

class FBXModel : public BaseObject
{
public:
	FBXModel();
	FBXModel(vec3 a_position);
	~FBXModel();

	bool LoadFBX(uint a_prog, 
		std::string a_directory,
		FBXFile::UNIT_SCALE a_scale = FBXFile::UNITS_METER,
		bool a_loadTextures = true,
		bool a_loadAnimations = true,
		bool a_flipTextureY = true);
	
	// Returns found mesh count
	inline uint getMeshCount() const {
		return m_pFbx->getMeshCount();
	}
	// Returns Mesh based on index element
	FBXMeshNode* getMeshByIndex(uint a_index) const {
		return m_pFbx->getMeshByIndex(a_index);
	}
	
	void CleanupOpenGLBuffers();

	void Update(const double a_dt);
	void Render();
private:
	void CreateOpenGLBuffers();

	int bonesUniform;
	FBXMaterial* m_material;
	std::vector<FBXVertex> m_vertices;
	std::vector<uint> m_indices;
	void* m_userData;

	FBXFile* m_pFbx;
};