#version 330 core

layout (location = 0) in vec3 in_Position;
layout (location = 1) in vec4 in_Color;
layout (location = 2) in vec2 in_TexCoord;

out vec4 v_Color;
out vec2 v_TexCoord;

void main() {
    gl_Position = vec4(in_Position.xyz, 1.0);
    v_Color = in_Color;
    v_TexCoord = in_TexCoord;
}
