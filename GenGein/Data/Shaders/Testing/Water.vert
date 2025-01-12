#version 430

in layout(location=0) vec4 vertPosition;
in layout(location=1) vec4 vertColour;
in layout(location=2) vec4 vertNormal;
in layout(location=7) vec2 vertCoords;

out vec4 vPosition;
out vec4 vColour;
out vec3 vNormal;
out vec2 vCoords;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 LocalMatrix;

void main()
{
	vPosition = vertPosition;
	vColour = vertColour;
	vNormal = vertNormal.xyz;
	vCoords = vertCoords;
		
	gl_Position = Projection * View * LocalMatrix * vPosition;
}