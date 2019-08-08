//
// Created by blinku on 08.08.2019.
//

#pragma once

#include <string>

namespace Bald::Utils {

    class Image {
    public:

        /**
        * @fn Image
        * @brief Explicit constructor.
        * @param std::string Filepath.
        */

        explicit Image(std::string filepath);

        /**
        * @fn ~Image
        * @brief Destructor.
        */

        ~Image();

        /**
        * @fn GetFilepath
        * @brief Filepath getter.
        */

        [[nodiscard]] inline const std::string& GetFilepath() const noexcept { return m_Filepath; }

        /**
        * @fn GetWidth
        * @brief Width getter.
        */

        [[nodiscard]] inline int32_t GetWidth() const noexcept { return m_Width; }

        /**
        * @fn GetHeight
        * @brief Height getter.
        */

        [[nodiscard]] inline int32_t GetHeight() const noexcept { return m_Height; }

        /**
        * @fn GetNrChannels
        * @brief Number of channels getter.
        */

        [[nodiscard]] inline int32_t GetNrChannels() const noexcept { return m_NrChannels; }

        /**
        * @fn GetData
        * @brief Data getter. Use with caution!
        */

        [[nodiscard]] inline const u_char* GetData() const noexcept { return m_Data; }

    private:

        /**
        * @fn LoadImage
        * @brief Loads the raw image data using third party library.
        */

        [[nodiscard]] u_char* LoadImage();

        /**
        * @fn FreeImage
        * @brief Frees the raw image data using third party library.
        */

        void FreeImage();

        /**
         * @fn Init
         * @brief Attempts to initialize the image and returns success result (true/false).
         * @return [bool] true -> image was initialized successfully.
         *                false -> image wasn't initialized successfully.
         */

        [[nodiscard]] bool Init() noexcept;

        /**
         * @fn Shutdown
         * @brief Destroys the image.
         */

        void Shutdown();

    private:
        const std::string m_Filepath; /**< Filepath. >*/
        int32_t m_Width = 0; /**< Width of the image. >*/
        int32_t m_Height = 0; /**< Height of the image. >*/
        int32_t m_NrChannels = 0; /**< Number of channels of the image. >*/
        u_char* m_Data = nullptr; /**< Raw data of the image. >*/

    }; // END OF CLASS Image

} // END OF NAMESPACE Bald::Utils
