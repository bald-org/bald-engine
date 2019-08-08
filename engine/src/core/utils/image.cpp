//
// Created by blinku on 08.08.2019.
//

#include "image.h"
#include "debug/bald_assert.h"

extern "C" unsigned char* stbi_load(char const* filename, int* x, int* y, int* channels_in_file, int desired_channels);
extern "C" void stbi_image_free(void* retval_from_stbi_load);
extern "C" void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

namespace Bald::Utils {

    Image::Image(std::string filepath)
        : m_Filepath(std::move(filepath)) {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "Image", "Failed to load image", state);
    }

    Image::~Image() {
        Shutdown();
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


