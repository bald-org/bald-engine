//
// Created by grzegorz on 24.08.2019.
//

#include "mesh.h"

namespace Bald::Graphics {


//    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices, const std::vector<std::shared_ptr<Texture>>& textures)
//            :
//            m_vertices(vertices), m_indices(indices), m_textures(textures),
//            m_VBO(VertexBuffer::Create(&( m_vertices[0].Pos.x ), static_cast<unsigned int>(m_vertices.size()) * 8)),
//            m_EBO(IndexBuffer::Create(m_indices.data(), static_cast<unsigned int>(m_indices.size()))),
//            m_VAO(VertexArray::Create()) {
//        Init();
//    }
//
//    Mesh::Mesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices, std::vector<std::shared_ptr<Texture>>&& textures)
//            :
//            m_vertices(std::move(vertices)), m_indices(std::move(indices)), m_textures(std::move(textures)),
//            m_VBO(VertexBuffer::Create(&( m_vertices[0].Pos.x ), static_cast<unsigned int>(m_vertices.size()) * 8)),
//            m_EBO(IndexBuffer::Create(m_indices.data(), static_cast<unsigned int>(m_indices.size()))),
//            m_VAO(VertexArray::Create()) {
//        Init();
//    }
//
//    void Mesh::Init() {
//        m_VBO->SetLayout({
//                                 {0, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec3, "in_Position"},
//                                 {1, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec3, "in_Normal"},
//                                 {2, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
//                         });
//
//        m_VAO->AddVertexBuffer(m_VBO);
//        m_VAO->AddIndexBuffer(m_EBO);
//    }
//
//    void Mesh::Draw([[maybe_unused]]const Shader& shader) {
//        unsigned int diffuseNr = 1;
//        unsigned int specularNr = 1;
//        for (unsigned int i = 0; i < m_textures.size(); i++) {
//            m_textures[i]->Activate(static_cast<uint8_t>(GL_TEXTURE0 + i));
//            std::string number;
//            std::string name = m_textures[i]->type;
//            if (name == "texture_diffuse")
//                number = std::to_string(diffuseNr++);
//            else if (name == "texture_specular")
//                number = std::to_string(specularNr++);
//
//            shader.SetUniform1f((( "material." + name ).append(number)).c_str(), static_cast<float>(i));
//            m_textures[i]->Bind();
//        }
//        glActiveTexture(GL_TEXTURE0);
//        m_VAO->Bind();
//        glDrawElements(GL_TRIANGLES, static_cast<int>(m_indices.size()), GL_UNSIGNED_INT, 0);
//        m_VAO->Unbind();
//    }
}