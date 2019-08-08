//
// Created by blinku on 08.08.2019.
//

#pragma once

#include <cstdint>
#include <string>

namespace Bald::Utils {

    class AssetManager {
    public:
        AssetManager() = delete;
        ~AssetManager() = delete;

        static u_char* LoadTexture(const std::string& path, int32_t* width, int32_t* height, int32_t* nrChannels);
        static void FreeTexture(u_char* textureData);

    }; // END OF CLASS AssetManager

} // END OF NAMESPACE Bald::Utils
