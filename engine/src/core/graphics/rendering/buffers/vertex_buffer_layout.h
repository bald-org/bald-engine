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

    constexpr uint32_t CalculateFloatOffset(uint32_t x) { return x * static_cast<uint32_t>(Utils::BuiltInTypeSize::Float); }
    constexpr uint32_t CalculateIntOffset(uint32_t x) { return x * static_cast<uint32_t>(Utils::BuiltInTypeSize::Int); }

    enum class ShaderBuiltInType : uint32_t {
        Unknown = 0,
        Float = GL_FLOAT,
        Int = GL_INT
    };

    // TODO: Examine differences in int vs float sizes in bytes on GPU
    enum class ShaderBuiltInTypeSize : uint32_t {
        Unknown = 0,
        Vec1 = CalculateFloatOffset(1),
        Vec2 = CalculateFloatOffset(2),
        Vec3 = CalculateFloatOffset(3),
        Vec4 = CalculateFloatOffset(4)
    };

    class VertexBufferLayoutElement {
    public:
        VertexBufferLayoutElement() = delete;

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
        inline void SetOffset(uint32_t offset) noexcept { m_Offset = offset; }

        [[nodiscard]] inline uint8_t IsNormalized() const noexcept { return m_IsNormalized; }

        [[nodiscard]] inline uint8_t GetShaderLayoutLocation() const noexcept { return m_ShaderLayoutLocation; }

        [[nodiscard]] inline uint32_t GetComponentCount() const noexcept { return m_ComponentCount; }

        [[nodiscard]] inline uint32_t GetStride() const noexcept { return m_Stride; }

        [[nodiscard]] inline uint32_t GetOffset() const noexcept { return m_Offset; }

        [[nodiscard]] inline uint32_t GetOpenGLType() const noexcept { return static_cast<uint32_t>(m_Type); }

    private:
        [[nodiscard]] uint32_t CalculateComponentCount() const noexcept {
            switch(m_Type) {
                case ShaderBuiltInType::Float : return static_cast<uint32_t>(m_TypeSize) / static_cast<uint32_t>(Bald::Utils::BuiltInTypeSize::Float);
                case ShaderBuiltInType::Int   : return static_cast<uint32_t>(m_TypeSize) / static_cast<uint32_t>(Bald::Utils::BuiltInTypeSize::Int);
                default: BALD_ASSERT(static_cast<bool>(m_Type), "VertexBufferLayoutElement",
                                    "Shader built-in type is unknown", static_cast<uint8_t>(m_Type));
            }
            return 0;
        }

    private:
        uint8_t m_IsNormalized;
        uint8_t m_ShaderLayoutLocation;
        ShaderBuiltInType m_Type;
        ShaderBuiltInTypeSize m_TypeSize;
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

        [[nodiscard]] std::vector<VertexBufferLayoutElement>::iterator begin() { return m_Layout.begin(); }
        [[nodiscard]] std::vector<VertexBufferLayoutElement>::iterator end() { return m_Layout.end(); }
        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator begin() const { return m_Layout.cbegin(); }
        [[nodiscard]] std::vector<VertexBufferLayoutElement>::const_iterator end() const { return m_Layout.cend(); }

    private:
        std::vector<VertexBufferLayoutElement> m_Layout;
        uint32_t m_Stride = 0;

    }; // END OF CLASS VertexBufferLayout

} // END OF NAMESPACE Bald::Graphics
