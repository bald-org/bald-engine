//
// Created by grzegorz on 24.08.2019.
//

#include "mesh.h"

namespace Bald::Graphics {


    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Mesh::Texture> textures)
    : m_vertices(std::move(vertices)), m_indices(std::move(indices)), m_textures(std::move(textures)),
        m_VBO(VertexBuffer::Create(&(m_vertices[0].Pos.x), static_cast<unsigned int>(m_vertices.size()) * 8)),
        m_EBO(IndexBuffer::Create(m_indices.data(), static_cast<unsigned int>(m_indices.size()))),
        m_VAO(VertexArray::Create())
    {
        Init();
    }

    void Mesh::Init() {
        m_VBO->SetLayout({
            {0, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec3, "in_Position"},
            {1, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec3, "in_Normal"},
            {2, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        });

        m_VAO->AddVertexBuffer(m_VBO);
        m_VAO->AddIndexBuffer(m_EBO);
    }

    void Mesh::Draw([[maybe_unused]]const Shader& shader) {

    }
}