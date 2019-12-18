//
// Created by blinku on 08.08.2019.
//

#include "image.h"
#include "debug/bald_assert.h"

extern "C" unsigned char* stbi_load(char const* filename, int* x, int* y, int* channels_in_file, int desired_channels);
extern "C" void stbi_image_free(void* retval_from_stbi_load);
extern "C" void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

namespace Bald::Utils {

    Image::Image(const int32_t width, const int32_t height)
        : m_Filepath{""},
          m_Width{width},
          m_Height{height},
          m_NrChannels(4),
          m_Data{nullptr} {
        u_char whitePixel[4] = {0xFF, 0xFF, 0xFF, 0xFF};
        SetData(whitePixel, sizeof(uint32_t));
    }

    Image::Image(std::string filepath)
        : m_Filepath{std::move(filepath)} {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "Image", "Failed to load image", state);
    }

    Image::~Image() {
        Shutdown();
    }

    void Image::SetData(u_char* data, std::size_t size) noexcept {
        stbi_image_free(m_Data);
        const auto currentSize = m_Width * m_Height * m_NrChannels;

        BALD_ASSERT(size == static_cast<std::size_t>(currentSize),
            "Image",
            "Size of array passed to texture must be the same as the previous texture size",
            size == static_cast<std::size_t>(currentSize));

        m_Data = static_cast<u_char*>(malloc(size)); // Must be malloc, because we are using stbi that calls free on pointers.
        std::copy(data, data + size, m_Data);
    }

    u_char* Image::LoadImage() {
        stbi_set_flip_vertically_on_load(true);
        return stbi_load(m_Filepath.c_str(), &m_Width, &m_Height, &m_NrChannels, 0);
    }

    void Image::FreeImage() {
        stbi_image_free(m_Data);
    }

    bool Image::Init() noexcept {
        m_Data = LoadImage();
        return m_Data != nullptr;
    }

    void Image::Shutdown() {
        FreeImage();
    }

} // END OF NAMESPACE Bald::Utils


