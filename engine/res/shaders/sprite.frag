#version 330 core

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TextureId;

uniform sampler2D u_Textures[32];

out vec4 FragColor;

void main() {
    FragColor = v_Color * texture(u_Textures[int(v_TextureId + 0.5f)], v_TexCoord);
}
