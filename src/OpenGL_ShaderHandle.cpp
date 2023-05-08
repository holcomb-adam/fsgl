#include "fsgl_pch.hpp"
#include "impl/API/OpenGL/OpenGL_ShaderHandle.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- GLM ---
#include <glm/gtc/type_ptr.hpp>

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"



fsgl::impl::OpenGL_ShaderHandle::OpenGL_ShaderHandle(const std::string& vertex_src, const std::string& fragment_src)
{
	// For reference on OpenGL shader compilation and where this code came from
	//     see: https://www.khronos.org/opengl/wiki/Shader_Compilation
	// The code here is slightly modified from the code in the "Example" 
	//     sub-section under "Shader and program objects"

	// Create an empty vertex shader handle
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar* source = (const GLchar*)vertex_src.c_str();
	glShaderSource(vertexShader, 1, &source, 0);

	// Compile the vertex shader
	glCompileShader(vertexShader);

	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(vertexShader);

		// Log shader compilation data
		FSGL_CORE_ERROR("{0}", infoLog.data());
		assert(false); // Vertex shader compilation has failed
	}

	// Create an empty fragment shader handle
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Send the fragment shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	source = (const GLchar*)fragment_src.c_str();
	glShaderSource(fragmentShader, 1, &source, 0);

	// Compile the fragment shader
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(fragmentShader);
		// Either of them. Don't leak shaders.
		glDeleteShader(vertexShader);

		// Log shader compilation data
		FSGL_CORE_ERROR("{0}", infoLog.data());
		assert(false); // Fragment shader compilation has failed
	}

	// Vertex and fragment shaders are successfully compiled.
	// Now time to link them together into a program.
	// Get a program object.
	GLuint program = glCreateProgram();

	// Attach our shaders to our program
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// Link our program
	glLinkProgram(program);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(program);
		// Don't leak shaders either.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		// Log shader compilation data
		FSGL_CORE_ERROR("{0}", infoLog.data());
		assert(false); // Fragment shader compilation has failed
	}

	// Always detach shaders after a successful link.
	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	// Let this object use the shader id
	m_ID = program;
}

fsgl::impl::OpenGL_ShaderHandle::~OpenGL_ShaderHandle()
{
	glDeleteProgram(m_ID);
}

void fsgl::impl::OpenGL_ShaderHandle::bind() const
{
	glUseProgram(m_ID);
}

void fsgl::impl::OpenGL_ShaderHandle::unbind() const
{
	glUseProgram(0);
}

void fsgl::impl::OpenGL_ShaderHandle::uploadUniform(const std::string& name, const glm::mat4& matrix)
{
	const auto location = glGetUniformLocation(m_ID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
