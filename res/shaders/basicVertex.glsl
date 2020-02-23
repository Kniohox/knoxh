#version 430 core

in vec3 vertex;
in vec3 color;

out vec4 passColor;

void main(void)
{
	gl_Position = vec4(vertex, 1.0);

	passColor = vec4(color, 1.0);
}
