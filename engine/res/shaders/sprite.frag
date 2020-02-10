#version 330 core

in vec4 v_Position;
in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TextureId;

uniform vec2 u_lightPos;
uniform sampler2D u_Textures[32];

out vec4 FragColor;

void main() {
    float intensity = 50.0 / length(u_lightPos - v_Position.xy);
    FragColor = intensity * v_Color * texture(u_Textures[int(v_TextureId + 0.5f)], v_TexCoord);
}
