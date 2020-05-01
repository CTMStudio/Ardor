#pragma once
#include <string>
#include "glm/ext/vector_float3.hpp"

/*
shader ½Ó¿Ú
@Author Hdan
@Time 2020/05/01
*/

namespace Ardor {



	class IShader {
	public:
		virtual void setBool(const std::string& name, bool value) const = 0;
		virtual void setInt(const std::string& name, int value) const = 0;
		virtual void setFloat(const std::string& name, float value) const = 0;

		virtual void setMat4(const std::string & name, float value[]) const = 0;
		virtual void setVec3(const std::string & name, float x, float y, float z)const = 0;
		virtual void setVec3(const std::string & name, const glm::vec3& vec) const = 0;
		virtual void use() = 0;;
		virtual unsigned int GetID() = 0;
	};


}