#version 330

in vec2 texCoord0;
uniform sampler2D tex;

layout(location = 0) out vec4 outputColor;

void main()
{
	outputColor = texture(tex, texCoord0);
}