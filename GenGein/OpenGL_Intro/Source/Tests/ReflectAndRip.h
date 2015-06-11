#pragma once
#include "Engine\Core\BaseApp.h"

class FBXModel;
class TransGrid;

class ReflectAndRip : public BaseApp
{
public:
	ReflectAndRip();
	ReflectAndRip(c_int a_width, c_int a_height, c_pChar a_title);
	~ReflectAndRip();

	// Initialised content 
	virtual void StartUp();
	// Deconstructed content
	virtual void ShutDown();
	// Update loop
	virtual void Update(const double_t a_dt);
	// Render to GUI
	virtual void Render();

	void CreateRenderObject(); 
	void SetUpTextureData();
	void SetUpDepthBuffer();

private:
	FBXModel* m_sphere;
	TransGrid* m_waterPlane;
	
	// FBO stuff
	uint m_fbo;
};

