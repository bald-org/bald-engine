//
// Created by blinku on 24.07.19.
//

#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

#include "debug/bald_assert.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    enum class ShaderBuiltInType : uint8_t {
        Unknown = 0, Vec1f, Vec2f, Vec3f, Vec4f, Vec1i, Vec2i, Vec3i, Vec4i
    };

    class VertexBufferLayoutElement {
    public:
        VertexBufferLayoutElement() = delete;

        VertexBufferLayoutElement(uint8_t shaderLayoutLocation, ShaderBuiltInType type, std::string name,
                                  bool isNormalized = false)
            : m_IsNormalized(isNormalized),
              m_ShaderLayoutLocation(shaderLayoutLocation),
              m_Type(type),
              m_Name(std::move(name)),
              m_ComponentCount(CalculateComponentCount()),
              m_Stride(CalculateStride()) {}

    public:
        inline void SetOffset(uint32_t offset) noexcept { m_Offset = offset; }

        [[nodiscard]] inline bool IsNormalized() const noexcept { return m_IsNormalized; }

        [[nodiscard]] inline uint8_t GetShaderLayoutLocation() const noexcept { return m_ShaderLayoutLocation; }

        [[nodiscard]] inline uint32_t GetComponentCount() const noexcept { return m_ComponentCount; }

        [[nodiscard]] inline uint32_t GetStride() const noexcept { return m_Stride; }

        [[nodiscard]] inline uint32_t GetOffset() const noexcept { return m_Offset; }

        [[nodiscard]] uint32_t GetOpenGLType() const noexcept {
            switch(m_Type) {
                case ShaderBuiltInType::Vec1f : return GL_FLOAT;
                case ShaderBuiltInType::Vec2f : return GL_FLOAT;
                case ShaderBuiltInType::Vec3f : return GL_FLOAT;
                case ShaderBuiltInType::Vec4f : return GL_FLOAT;
                case ShaderBuiltInType::Vec1i : return GL_INT;
                case ShaderBuiltInType::Vec2i : return GL_INT;
                case ShaderBuiltInType::Vec3i : return GL_INT;
                case ShaderBuiltInType::Vec4i : return GL_INT;
                default:
                    BALD_ASSERT(static_cast<uint8_t>(m_Type), "VertexBufferLayoutElement",
                                "Shader built-in type is unknown", static_cast<uint8_t>(m_Type));
            }
            return 0;
        }

    private:
        [[nodiscard]] uint32_t CalculateComponentCount() const noexcept {
            switch(m_Type) {
                case ShaderBuiltInType::Vec1f : return 1;
                case ShaderBuiltInType::Vec2f : return 2;
                case ShaderBuiltInType::Vec3f : return 3;
                case ShaderBuiltInType::Vec4f : return 4;
                case ShaderBuiltInType::Vec1i : return 1;
                case ShaderBuiltInType::Vec2i : return 2;
                case ShaderBuiltInType::Vec3i : return 3;
                case ShaderBuiltInType::Vec4i : return 4;
                default: BALD_ASSERT(static_cast<uint8_t>(m_Type), "VertexBufferLayoutElement",
                                     "Shader built-in type is unknown", static_cast<uint8_t>(m_Type));
            }
            return 0;
        }

        [[nodiscard]] uint32_t CalculateStride() const noexcept {
            switch(m_Type) {
                case ShaderBuiltInType::Vec1f : return 1 * sizeof(float);
                case ShaderBuiltInType::Vec2f : return 2 * sizeof(float);
                case ShaderBuiltInType::Vec3f : return 3 * sizeof(float);
                case ShaderBuiltInType::Vec4f : return 4 * sizeof(float);
                case ShaderBuiltInType::Vec1i : return 1 * sizeof(uint32_t);
                case ShaderBuiltInType::Vec2i : return 2 * sizeof(uint32_t);
                case ShaderBuiltInType::Vec3i : return 3 * sizeof(uint32_t);
                case ShaderBuiltInType::Vec4i : return 4 * sizeof(uint32_t);
                default: BALD_ASSERT(static_cast<uint8_t>(m_Type), "VertexBufferLayoutElement",
                                     "Shader built-in type is unknown", static_cast<uint8_t>(m_Type));
            }
            return 0;
        }

    private:
        bool m_IsNormalized;
        uint8_t m_ShaderLayoutLocation = 0;
        ShaderBuiltInType m_Type = ShaderBuiltInType::Unknown;
        std::string m_Name;
        uint32_t m_ComponentCount;
        uint32_t m_Stride;
        uint32_t m_Offset = 0;
    }; // END OF CLASS VertexBufferLayoutElement

    class VertexBufferLayout {
    public:
        VertexBufferLayout() = default;

        VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> layout) : m_Layout(layout) {
            for(auto& x : *this) {
                m_Stride += x.GetStride();
            }
        }

        [[nodiscard]] inline uint32_t GetStride() const noexcept { return m_Stride; }

        std::vector<VertexBufferLayoutElement>::iterator begin() { return m_Layout.begin(); }

        std::vector<VertexBufferLayoutElement>::iterator end() { return m_Layout.end(); }

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator begin() const { return m_Layout.begin(); }

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator end() const { return m_Layout.end(); }

    private:
        std::vector<VertexBufferLayoutElement> m_Layout;
        uint32_t m_Stride = 0;
        
    }; // END OF CLASS VertexBufferLayout

} // END OF NAMESPACE Bald::Graphics
