//
// Created by grzegorz on 24.08.2019.
//
#pragma once
//#include <glm/glm.hpp>
//#include "../buffers/vertex_buffer_layout.h"
//#include "../buffers/vertex_array.h"
//#include "../buffers/vertex_buffer.h"
//#include "../buffers/index_buffer.h"
//#include "../textures/texture.h"



#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include "graphics/rendering/shaders/shader.h"


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <src/core/platform/opengl/textures/opengl_texture.h>

namespace Bald::Platform::Graphics {

    class Mesh {
    public:
        /*  Mesh Classes */
        struct Vertex {
            // position
            glm::vec3 Position;
            // normal
            glm::vec3 Normal;
            // texCoords
            glm::vec2 TexCoords;
            // tangent
            glm::vec3 Tangent;
            // bitangent
            glm::vec3 Bitangent;
        };

//        struct Texture {
//            unsigned int id;
//            std::string type;
//            std::string path;
//        };
        /*  Mesh Data  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<OpenGLTexture> textures;
        unsigned int VAO;

        /*  Functions  */
        // constructor
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<OpenGLTexture> textures)
         : vertices(std::move(vertices)), indices(std::move(indices)), textures(std::move(textures))
        {
            // now that we have all the required data, set the vertex buffers and its attribute pointers.
            setupMesh();
        }

        // render the mesh
        void Draw(Bald::Graphics::Shader& shader)
        {
            // bind appropriate textures
            unsigned int diffuseNr  = 1;
            unsigned int specularNr = 1;
            unsigned int normalNr   = 1;
            unsigned int heightNr   = 1;
            for(unsigned int i = 0; i < textures.size(); i++)
            {
                glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
                // retrieve texture number (the N in diffuse_textureN)
                std::string number;
                std::string name = textures[i].type;
                if(name == "texture_diffuse")
                    number = std::to_string(diffuseNr++);
                else if(name == "texture_specular")
                    number = std::to_string(specularNr++); // transfer unsigned int to stream
                else if(name == "texture_normal")
                    number = std::to_string(normalNr++); // transfer unsigned int to stream
                else if(name == "texture_height")
                    number = std::to_string(heightNr++); // transfer unsigned int to stream

                // now set the sampler to the correct texture unit
                glUniform1i(glGetUniformLocation(shader.GetID(), (name + number).c_str()), i);
                // and finally bind the texture
                glBindTexture(GL_TEXTURE_2D, textures[i].GetID());
            }

            // draw mesh
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, static_cast<int>(indices.size()), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            // always good practice to set everything back to defaults once configured.
            glActiveTexture(GL_TEXTURE0);
        }

    private:
        /*  Render data  */
        unsigned int VBO, EBO;

        /*  Functions    */
        // initializes all the buffer objects/arrays
        void setupMesh()
        {
            // create buffers/arrays
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glGenBuffers(1, &EBO);

            glBindVertexArray(VAO);
            // load data into vertex buffers
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            // A great thing about structs is that their memory layout is sequential for all its items.
            // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
            // again translates to 3/2 floats which translates to a byte array.
            glBufferData(GL_ARRAY_BUFFER, static_cast<long>(vertices.size() * sizeof(Vertex)), &vertices[0], GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<long>(indices.size() * sizeof(unsigned int)), &indices[0], GL_STATIC_DRAW);

            // set the vertex attribute pointers
            // vertex Positions
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
            // vertex normals
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
            // vertex texture coords
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
            // vertex tangent
            glEnableVertexAttribArray(3);
            glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
            // vertex bitangent
            glEnableVertexAttribArray(4);
            glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

            glBindVertexArray(0);
        }
    };

}


