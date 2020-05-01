#include "OGLShader.h"
#include "glad/glad.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace Ardor;

Shader::Shader(const char* vefilepath, const char* fragfilepath)
	: mID(0)
{

	if (!vefilepath || !fragfilepath)
	{
		std::cout << "SHADER FILE PATH ERROR!" << std::endl;
		return;
	}

	std::string codev;
	std::string codef;
	std::ifstream strfilev;
	std::ifstream strfilef;

	try {
		strfilev.open(vefilepath);
		strfilef.open(fragfilepath);
		std::stringstream streamv;
		std::stringstream streamf;
		streamv << strfilev.rdbuf();
		streamf << strfilef.rdbuf();
		strfilev.close();
		strfilef.close();
		codev = streamv.str();
		codef = streamf.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << " SHADER FILE OPEN FAILED! " << e.code() << std::endl;
	}
	const char* char_codev = codev.c_str();
	const char* char_codef = codef.c_str();

	unsigned int ssv = glCreateShader(GL_VERTEX_SHADER);
	unsigned int ssf = glCreateShader(GL_FRAGMENT_SHADER);


	glShaderSource(ssv, 1, &char_codev, NULL);
	glShaderSource(ssf, 1, &char_codef, NULL);
	glCompileShader(ssv);
	glCompileShader(ssf);
	CheckCompileErr(ssv, "vertex");
	CheckCompileErr(ssf, "fragment");
	mID = glCreateProgram();
	glAttachShader(mID, ssv);
	glAttachShader(mID, ssf);
	glLinkProgram(mID);
	CheckCompileErr(mID, "program");

	glDeleteShader(ssv);
	glDeleteShader(ssf);
}


Shader::~Shader()
{
}


void Shader::CheckCompileErr(unsigned int ss, const std::string& str)
{
	int success = 0;
	char infoLog[512] = { 0 };
	if (str == "program")
	{
		glGetProgramiv(ss, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ss, 512, NULL, infoLog);
			std::cout << str << " : Link Program shader FAILED!\n" << infoLog << std::endl;
		}
	}
	else
	{

		glGetShaderiv(ss, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(ss, 512, NULL, infoLog);
			std::cout << str << " : complie shader FAILED!\n" << infoLog << std::endl;
		}

	}

}

void Shader::use()
{
	glUseProgram(mID);
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(mID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(mID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(mID, name.c_str()), value);
}



void Shader::setMat4(const std::string& name, float value[]) const
{
	glUniformMatrix4fv(glGetUniformLocation(mID, name.c_str()), 1, GL_FALSE, value);
}

void Shader::setVec3(const std::string & name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(mID, name.c_str()), x, y, z);
}

void Shader::setVec3(const std::string & name, const glm::vec3& vec) const
{
	glUniform3fv(glGetUniformLocation(mID, name.c_str()), 1, &vec[0]);
}
