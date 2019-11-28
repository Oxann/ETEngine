#pragma once
#include <EtRendering/GraphicsContext/GraphicsTypes.h>


class Camera;
class Gbuffer;


namespace render {


//--------------------
// SharedVarController
//
// Keeps common uniform variables up to date to avoid this responsibility for shaders
//
class SharedVarController final
{
	// definititions
	//---------------
	struct GlobalData
	{
		mat4 view;
		mat4 viewInv;
		mat4 projection;
		mat4 viewProjection;
		mat4 viewProjectionInv;
		mat4 staticViewProjection;
		mat4 staticViewProjectionInv;

		float time = 0.f;
		float deltaTime = 0.f;

		float projectionA = 0.f;
		float projectionB = 0.f;

		vec3 camPos;
	};

	// construct deconstruct
	//-----------------------
public:
	SharedVarController() = default;
	~SharedVarController();

	void Init();
	void Deinit();

	// functionality
	//---------------
	void UpdataData(Camera const& camera);

	// accessors
	//-----------
	T_BufferLoc const GetBufferLocation() const { return m_BufferLocation; }
	uint32 const GetBufferBinding() const { return m_BufferBinding; }
	std::string const& GetBlockName() const { return m_UniformBlockName; }

private:

	// Data
	///////

	bool m_IsInitialized = false;

	GlobalData m_Data;
	T_BufferLoc m_BufferLocation;

	std::string m_UniformBlockName = "SharedVars";
	uint32 m_BufferBinding = 0u;
};


} // namespace render
