//
// Created by grzegorz on 19.09.19.
//

#include "model.h"

//#include "assimp/Importer.hpp"
//#include "assimp/scene.h"
//#include "assimp/postprocess.h"
//
//#include "glm/glm.hpp"
//
//#include "logger/log_manager.h"

namespace Bald::Graphics {


//    void Model::Draw(const Shader& shader) {
//        for (auto elem : meshes) {
//            elem.Draw(shader);
//        }
//    }
//
//    void Model::loadModel(const std::string& path) {
//        Assimp::Importer import;
//        const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
//
//        if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
//            CORE_LOG_ERROR(std::string("[MODEL] Error::Assimp:: ").append(import.GetErrorString()));
//            return;
//        }
//
//        directory = path.substr(0, path.find_last_of('/'));
//        processNode(scene->mRootNode, scene);
//    }
//
//    void Model::processNode(aiNode* node, const aiScene* scene) {
//        for (uint32_t i = 0; i < node->mNumMeshes; i++) {
//            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
//            meshes.push_back(processMesh(mesh, scene));
//        }
//
//        for (uint32_t i = 0; i < node->mNumChildren; i++) {
//            processNode(node->mChildren[i], scene);
//        }
//    }
//
//    Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
//        std::vector<Mesh::Vertex> vertices;
//        std::vector<unsigned int> indices;
//        std::vector<std::shared_ptr<Texture>> textures;
//
//        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
//            Mesh::Vertex vertex;
//            glm::vec3 vector;
//            vector.x = mesh->mVertices[i].x;
//            vector.y = mesh->mVertices[i].y;
//            vector.z = mesh->mVertices[i].z;
//            vertex.Pos = vector;
//            vector.x = mesh->mNormals[i].x;
//            vector.y = mesh->mNormals[i].y;
//            vector.z = mesh->mNormals[i].z;
//            vertex.Normal = vector;
//            if (mesh->mTextureCoords[0]) {
//                glm::vec2 vec;
//                vec.x = mesh->mTextureCoords[0][i].x;
//                vec.y = mesh->mTextureCoords[0][i].y;
//                vertex.TexCoords = vec;
//            } else {
//                vertex.TexCoords = glm::vec2(0.0f, 0.0f);
//            }
//            vertices.push_back(vertex);
//        }
//
//        if (mesh->mMaterialIndex > 0) {
//            for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
//                aiFace face = mesh->mFaces[i];
//                for (unsigned int j = 0; j < face.mNumIndices; j++)
//                    indices.push_back(face.mIndices[j]);
//            }
//        }
//
//        if (mesh->mMaterialIndex > 0) {
//            aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
//            auto diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
//            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
//            auto specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
//            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
//        }
//
//        return Mesh(std::move(vertices), std::move(indices), std::move(textures));
//    }
//
//    std::vector<std::shared_ptr<Texture>> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string& typeName) {
//        std::vector<std::shared_ptr<Texture>> textures;
//        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
//            aiString str;
//            mat->GetTexture(type, i, &str);
//            bool skip = false;
//            for (unsigned int j = 0; j < textures.size(); j++) {
//                if (textures[j]->GetFilePath() == str.C_Str()) {
//                    textures.emplace_back(textures[j]); //TODO: probably will have to define copy constructor for texture and image
//                    skip = true;
//                    break;
//                }
//            }
//            if (!skip) {
//                auto texture = Texture::Create(str.C_Str());
//                texture->type = typeName;
//                textures.push_back(texture);
//            }
//        }
//        return textures;
//    }
}