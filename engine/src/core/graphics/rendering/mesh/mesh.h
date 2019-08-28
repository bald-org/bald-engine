//
// Created by grzegorz on 24.08.2019.
//
#include <glm/glm.hpp>
#include "../buffers/vertex_buffer_layout.h"
#include "../buffers/vertex_array.h"
#include "../buffers/vertex_buffer.h"
#include "../buffers/index_buffer.h"
#include "graphics/rendering/shaders/shader.h"

#pragma once

namespace Bald::Graphics {

    class Mesh {
    public:
        struct Vertex {
            glm::vec3 Pos;
            glm::vec3 Normal;
            glm::vec2 TexCoords;
        };
        struct Texture {
            uint32_t id;
            std::string type;
        };
        std::vector<Vertex> m_vertices;
        std::vector<uint32_t> m_indices;
        std::vector<Mesh::Texture> m_textures;
        Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Mesh::Texture> textures);
        void Draw(const Shader& shader);
    private:
        std::shared_ptr<VertexBuffer> m_VBO;
        std::shared_ptr<IndexBuffer> m_EBO;
        std::shared_ptr<VertexArray> m_VAO;
        void Init();
    };

}


