//
// Created by blinku on 08.08.2019.
//

#include "asset_manager.h"

extern "C" unsigned char* stbi_load(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
extern "C" void stbi_image_free(void* retval_from_stbi_load);
extern "C" void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

namespace Bald::Utils {

    u_char* AssetManager::LoadTexture(const std::string& path, int32_t* width, int32_t* height, int32_t* nrChannels) {
        stbi_set_flip_vertically_on_load(true);
        return stbi_load(path.c_str(), width, height, nrChannels, 0);
    }

    void AssetManager::FreeTexture(u_char* textureData) {
        stbi_image_free(textureData);
    }

} // END OF NAMESPACE Bald::Utils
