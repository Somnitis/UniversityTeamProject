/******************************************************************************
Class:Shader
Implements:
Author:Rich Davison	<richard.davison4@newcastle.ac.uk>
Description:VERY simple class to encapsulate GLSL shader loading, linking,
and binding. Useful additions to this class would be overloaded functions to
replace the glUniformxx functions in external code, and possibly a map to store
uniform names and their resulting bindings. 

-_-_-_-_-_-_-_,------,   
_-_-_-_-_-_-_-|   /\_/\   NYANYANYAN
-_-_-_-_-_-_-~|__( ^ .^) /
_-_-_-_-_-_-_-""  ""   

*//////////////////////////////////////////////////////////////////////////////

#pragma once


#include "OGLRenderer.h"

#define SHADER_VERTEX   0
#define SHADER_FRAGMENT 1
#define SHADER_GEOMETRY 2
#define SHADER_CONTROL 2
#define SHADER_EVALUATION 3
#define SHADER_GEOMETRY2 4
#define SHADER_COMPUTE 0

using namespace std;
class Shader	{
public:
	Shader(string vertex, string fragment, string control, string evaluation, string geometry = "");
	Shader(string vertex, string fragment , string geometry = "");
	Shader(string compute);
	~Shader(void);

	GLuint  GetProgram() { return program;}
	

	void	Reload(bool deleteOld = true);


	bool	LoadSuccess() {
		return !loadFailed;
	}
	bool	LinkProgram();

	GLuint	GenerateShader(string from, GLenum type);
protected:
	bool	LoadShaderFile(string from, string &into);
	
	void	SetDefaultAttributes();
	
	GLuint	objects[5];
	GLuint	program;

	bool	loadFailed;

	string	vertexName;
	string	fragName;
	string	geomName;
};
