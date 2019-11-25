#version 330 core

layout (location = 0) in vec2 in_Position;
layout (location = 1) in vec4 in_Color;
layout (location = 2) in vec2 in_TextureCoord;
layout (location = 3) in float in_TextureId;

uniform mat4 u_Model;
uniform mat4 u_ProjectionView;

out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TextureId;

void main() {
    gl_Position = u_ProjectionView * u_Model * vec4(in_Position.xy, 0.0f, 1.0f);
    v_Color = in_Color;
    v_TexCoord = in_TextureCoord;
    v_TextureId = in_TextureId;
}
