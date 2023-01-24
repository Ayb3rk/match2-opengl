#version 120 

uniform int numberOfRows;
uniform int numberOfColumns;

uniform int rowPos;
uniform int colPos;

uniform float intensity;
vec3 I = vec3(intensity, intensity, intensity);
vec3 Iamb = vec3(0.8, 0.8, 0.8);

uniform vec3 kd;
vec3 ka = vec3(0.1, 0.1, 0.1);
vec3 ks = vec3(0.8, 0.8, 0.8);

uniform mat4 modelingMat;
uniform mat4 modelingMatInvTr;
uniform mat4 perspectiveMat;

attribute vec3 inVertex;
attribute vec3 inNormal;

void main(void)
{
	vec3 result = vec3(0, 0, 0);
	for(int i = 0; i<numberOfRows; i++){
		for(int j = 0; j< numberOfColumns; j++){
			vec3 lightPos = vec3(rowPos, colPos, 20);
			vec3 eyePos = vec3(rowPos, colPos, 1);
			vec4 p = modelingMat * vec4(inVertex, 1); // translate to world coordinates
			vec3 Lorg = lightPos - vec3(p);
			vec3 L = normalize(Lorg);
			vec3 V = normalize(eyePos - vec3(p));
			vec3 H = normalize(L + V);
			vec3 N = vec3(modelingMatInvTr * vec4(inNormal, 0)); // provided by the programmer
			N = normalize(N);
			float NdotL = dot(N, L);
			float NdotH = dot(N, H);

			float d = length(Lorg);
			vec3 diffuseColor = I * kd * max(0, NdotL) / (d * d);
			vec3 ambientColor = Iamb * ka;
			vec3 specularColor = I * ks * pow(max(0, NdotH), 20) / (d * d);
			result += diffuseColor + ambientColor + specularColor;
		}
	}

	gl_FrontColor = vec4(result, 1);

    gl_Position = perspectiveMat * modelingMat * vec4(inVertex, 1);
}

