#version 330 core

layout (location = 0) in vec4 v_Position;

void main() {
    gl_Position = v_Position;
}
