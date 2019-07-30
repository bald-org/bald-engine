//
// Created by blinku on 24.07.19.
//

#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>
#include "utils/types.h"
#include "debug/bald_assert.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    /**
     * @enum ShaderBuiltInType
     * @brief Strongly typed enum which helps with abstracting shader built in types.
     * @var [Float] Currently maps to GL_FLOAT.
     * @var [Int] Currently maps to GL_INT.
     */

    enum class ShaderBuiltInType : uint32_t {
        Unknown = 0,
        Float = GL_FLOAT,
        Int = GL_INT
    };

    /**
     * @enum ShaderBuiltInTypeSize
     * @brief Strongly typed enum which helps with abstracting shader built in type sizes.
     * @var [Unknown] Size of shader built in type is unknown.
     * @var [Vec1] Size of Vec1 type in bytes.
     * @var [Vec2] Size of Vec2 type in bytes.
     * @var [Vec3] Size of Vec3 type in bytes.
     * @var [Vec4] Size of Vec4 type in bytes.
     */

    // TODO: Examine differences in int vs float sizes in bytes on GPU
    enum class ShaderBuiltInTypeSize : uint32_t {
        Unknown = 0,
        Vec1 = Utils::CalculateFloatOffset(1),
        Vec2 = Utils::CalculateFloatOffset(2),
        Vec3 = Utils::CalculateFloatOffset(3),
        Vec4 = Utils::CalculateFloatOffset(4)
    };

    /**
     * @class VertexBufferLayoutElement
     * @brief Class that represents a single vertex buffer layout element.
     */

    class VertexBufferLayoutElement {
    public:

        /**
         * @fn VertexBufferLayoutElement
         * @brief Explicitly deleted constructor.
         */

        VertexBufferLayoutElement() = delete;

        /**
         * @fn VertexBufferLayoutElement
         * @brief Constructor.
         * @param shaderLayoutLocation Location to which this layout element will be applied inside a shader.
         * @param type Built in shader type as enum.
         * @param typeSize Size of shader type as enum.
         * @param name Name of the shader "in" variable.
         * @param isNormalized Information about whether or not data inside buffer is normalized.
         */

        VertexBufferLayoutElement(uint8_t shaderLayoutLocation, ShaderBuiltInType type, ShaderBuiltInTypeSize typeSize,
                                  std::string name,
                                  bool isNormalized = false)
            : m_IsNormalized(isNormalized),
              m_ShaderLayoutLocation(shaderLayoutLocation),
              m_Type(type),
              m_TypeSize(typeSize),
              m_Name(std::move(name)),
              m_ComponentCount(CalculateComponentCount()),
              m_Stride(static_cast<uint32_t>(m_TypeSize)) {}

    public:

        /**
        * @fn SetOffset
        * @brief Offset setter.
        * @param offset Value of the offset to be set.
        */

        inline void SetOffset(uint32_t offset) noexcept { m_Offset = offset; }

        /**
        * @fn IsNormalized
        * @brief Getter.
        */

        [[nodiscard]] inline uint8_t IsNormalized() const noexcept { return m_IsNormalized; }

        /**
        * @fn GetShaderLayoutLocation
        * @brief Getter.
        */

        [[nodiscard]] inline uint8_t GetShaderLayoutLocation() const noexcept { return m_ShaderLayoutLocation; }

        /**
        * @fn GetComponentCount
        * @brief Getter.
        */

        [[nodiscard]] inline uint32_t GetComponentCount() const noexcept { return m_ComponentCount; }

        /**
        * @fn GetStride
        * @brief Getter.
        */

        [[nodiscard]] inline uint32_t GetStride() const noexcept { return m_Stride; }

        /**
        * @fn GetOffset
        * @brief Getter.
        */

        [[nodiscard]] inline uint32_t GetOffset() const noexcept { return m_Offset; }

        /**
        * @fn GetOpenGLType
        * @brief Getter.
        */

        [[nodiscard]] inline uint32_t GetOpenGLType() const noexcept { return static_cast<uint32_t>(m_Type); }

    private:

        /**
        * @fn CalculateComponentCount
        * @brief This method is used to initialize m_ComponentCount variable.
        * @return Component count.
        */


        [[nodiscard]] uint32_t CalculateComponentCount() const noexcept {
            switch(m_Type) {
                case ShaderBuiltInType::Float :
                    return static_cast<uint32_t>(m_TypeSize) / static_cast<uint32_t>(Bald::Utils::BuiltInTypeSize::Float);
                case ShaderBuiltInType::Int   :
                    return static_cast<uint32_t>(m_TypeSize) / static_cast<uint32_t>(Bald::Utils::BuiltInTypeSize::Int);
                default:
                    BALD_ASSERT(static_cast<bool>(m_Type), "VertexBufferLayoutElement", "Shader built-in type is unknown", static_cast<uint8_t>(m_Type));
            }
            return 0;
        }

    private:
        uint8_t m_IsNormalized; /**< Information whether or not vertex buffer data is normalized. */
        uint8_t m_ShaderLayoutLocation; /**< Location inside shader to which this layout element will be applied. */
        ShaderBuiltInType m_Type; /**< Shader built in type. */
        ShaderBuiltInTypeSize m_TypeSize; /**< Shader built in type size */
        std::string m_Name; /**< Name of shader "in" variable. */
        uint32_t m_ComponentCount; /**< Component count. */
        uint32_t m_Stride; /**< Stride. */
        uint32_t m_Offset = 0; /**< Offset. */

    }; // END OF CLASS VertexBufferLayoutElement

    /**
     * @class VertexBufferLayout
     * @brief Class that represents a vertex buffer layout.
     */

    class VertexBufferLayout {
    public:

        /**
         * @fn VertexBufferLayout
         * @brief Default constructor. Defaulted because we want to keep objects of this class inside buffers that are not yet initialized.
         */

        VertexBufferLayout() = default;

        /**
         * @fn VertexBufferLayout
         * @brief Non-default constructor. Used to actually create a buffer layout. Also calculates the stride.
         * @param layout Initializer list of VertexBufferLayoutElement element. Used to simplify usage.
         */

        VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> layout) : m_Layout(layout) {
            for(auto& x : *this) {
                m_Stride += x.GetStride();
            }
        }

        /**
          * @fn GetStride
          * @brief Getter.
          * @return Stride.
          */

        [[nodiscard]] inline uint32_t GetStride() const noexcept { return m_Stride; }

        /**
          * @fn begin
          * @brief Forward iterator.
          * @return Iterator.
          */

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::iterator begin() { return m_Layout.begin(); }

        /**
          * @fn end
          * @brief Forward iterator.
          * @return Iterator.
          */

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::iterator end() { return m_Layout.end(); }

        /**
          * @fn begin
          * @brief Const forward iterator.
          * @return Const iterator.
          */

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator begin() const { return m_Layout.cbegin(); }

        /**
          * @fn end
          * @brief Const forward iterator.
          * @return Const iterator.
          */

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator end() const { return m_Layout.cend(); }

    private:
        std::vector<VertexBufferLayoutElement> m_Layout; /**< Container that represents the layout. */
        uint32_t m_Stride = 0; /**< Stride. */

    }; // END OF CLASS VertexBufferLayout

} // END OF NAMESPACE Bald::Graphics
