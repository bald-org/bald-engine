//
// Created by blinku on 08.08.2019.
//

#pragma once

#include <string>

namespace Bald::Utils {

    class Image {
    public:
        explicit Image(std::string filepath);
        ~Image();

        [[nodiscard]] inline const std::string& GetFilepath() const noexcept { return m_Filepath; }

        [[nodiscard]] inline int32_t GetWidth() const noexcept { return m_Width; }

        [[nodiscard]] inline int32_t GetHeight() const noexcept { return m_Height; }

        [[nodiscard]] inline int32_t GetNrChannels() const noexcept { return m_NrChannels; }

        [[nodiscard]] inline const u_char* GetData() const noexcept { return m_Data; }

    private:
        [[nodiscard]] static u_char* LoadImage(const std::string& path, int32_t* width, int32_t* height, int32_t* nrChannels);
        static void FreeImage(u_char* textureData);

    private:
        const std::string m_Filepath;
        int32_t m_Width = 0;
        int32_t m_Height = 0;
        int32_t m_NrChannels = 0;
        u_char* m_Data = nullptr;

    }; // END OF CLASS Image

} // END OF NAMESPACE Bald::Utils
