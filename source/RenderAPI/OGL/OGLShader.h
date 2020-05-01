#pragma once
#include "../API/Shader.h"

/*
@Shader使用OpenGL的具体实现
@Author Hdan
@Time 2020/05/01
*/

namespace Ardor {


	class Shader : public IShader
	{
	public:
		Shader(const char* vsPath, const char* vfPath);
		~Shader();
		virtual void setBool(const std::string& name, bool value) const;
		virtual void setInt(const std::string& name, int value) const;
		virtual void setFloat(const std::string& name, float value) const;

		virtual void setMat4(const std::string & name, float value[]) const;
		virtual void setVec3(const std::string & name, float x, float y, float z) const;
		virtual void setVec3(const std::string & name, const glm::vec3& vec) const;
		virtual void use();
		virtual unsigned int GetID() const { return mID; }
	private:

		void CheckCompileErr(unsigned int ss, const std::string& str);

		unsigned int mID;





	};



}