//
// Created by grzegorz on 24.08.2019.
//
#include <glm/glm.hpp>
#include "../buffers/vertex_buffer_layout.h"
#include "../buffers/vertex_array.h"
#include "../buffers/vertex_buffer.h"
#include "../buffers/index_buffer.h"
#include "../textures/texture.h"
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
        std::vector<Vertex> m_vertices;
        std::vector<uint32_t> m_indices;
        std::vector<std::shared_ptr<Texture>> m_textures;

        Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices, const std::vector<std::shared_ptr<Texture>>& textures);

        Mesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices, std::vector<std::shared_ptr<Texture>>&& textures);

        void Draw(const Shader& shader);

    private:
        std::shared_ptr<VertexBuffer> m_VBO;
        std::shared_ptr<IndexBuffer> m_EBO;
        std::shared_ptr<VertexArray> m_VAO;

        void Init();
    };

}


