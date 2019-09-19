//
// Created by grzegorz on 19.09.19.
//

#pragma once

#include "../mesh/mesh.h"

#include "assimp/material.h"

struct aiNode;
struct aiScene;
struct aiMesh;
struct aiMaterial;


namespace Bald::Graphics {
    class Model {
    public:
        Model(char* path) {
            loadModel(path);
        }

        void Draw(const Shader& shader);

    private:
        std::vector<Mesh> meshes;
        std::string directory;

        void loadModel(const std::string& path);

        void processNode(aiNode* node, const aiScene* scene);

        Mesh processMesh(aiMesh* mesh, const aiScene* scene);

        std::vector<std::shared_ptr<Texture>> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                                                                   const std::string& typeName);
    };
}
