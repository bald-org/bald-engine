//
// Created by ajer on 16.12.18.
//

#pragma once
#include <cmath>
#include <iostream>

namespace Bald::Math{

    class Vec2{
    public:
        /*
         * @fn Vec2
         * @brief constructor
         * @param [float] x
         * @param [float] y
        */
        Vec2(float x = 0.0f, float y = 0.0f)
                :m_x(x), m_y(y){}


        /*
         * @fn MakeUnitVec
         * @brief creates unit vector with the length of 1.0f
         * @param [const Vec2&] vec -> current vector
         * @return [Vec2] unit long vector
         * */
        [[nodiscard]] static Vec2 MakeUnitVec(const Vec2& vec)noexcept;


        /*
         * @fn Normalize
         * @brief normalizes the vector to the length of 1.0f
         * @return [Vec2&] unit long vector
         * */
        [[nodiscard]] Vec2& Normalize()noexcept;


        /*
         * @fn GetX
         * @brief returns m_x variable
         * @return [float] m_x
        */
        [[nodiscard]] constexpr inline float GetX()const noexcept{return m_x;}


        /*
         * @fn GetY
         * @brief returns m_y variable
         * @return [float] m_y
        */
        [[nodiscard]] constexpr inline float GetY()const noexcept{return m_y;}


        /*
        * @fn Reverse
        * @brief reverts vector
        * @return [Vec2&] reversed vector
        */
        [[nodiscard]] Vec2 Reverse()const noexcept;

                 // OPERATORS

        /*
         * @fn operator<<
         * @brief prints the vec2
         * @param [std::ostream&] output stream
         * @param [const Vec2&] vector object to be printed
        */
        [[nodiscard]] friend std::ostream& operator<<(std::ostream& out, const Vec2& vec)noexcept;


        /*
         * @fn operator+
         * @brief adds another vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2 operator+(const Vec2& other)const noexcept;


        /*
         * @fn operator-
         * @brief adds another vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2 operator-(const Vec2& other)const noexcept;


        /*
         * @fn operator*
         * @brief multiplies current vector by the passed multiplier
         * @param [float] multiplier
        */
        [[nodiscard]] Vec2 operator*(float multiplier) const noexcept;


        /*
         * @fn operator+=
         * @brief adds another vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2& operator+=(const Vec2& other)noexcept;


        /*
         * @fn operator-=
         * @brief adds reversed other vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2& operator-=(const Vec2& other)noexcept;


        /*
         * @fn operator*=
         * @brief multiplies current vector by the passed multiplier
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2& operator*=(float multiplier)noexcept;


        /*
         * @fn operator==
         * @brief checks if the two vectors are the same
         * @param [const Vec&] other Vec2
        */
        [[nodiscard]] bool operator==(const Vec2& other) const noexcept;


        /*
         * @fn operator!=
         * @brief checks if the two vectors are the same
         * @param [const Vec&] other Vec2
        */
        [[nodiscard]] bool operator!=(const Vec2& other) const noexcept;

        // END OF OPERATORS

        /*
         * @fn AngleBetween
         * @brief returns angle between two vectors
         * @param [const Vec&] other Vec2
         * @return [float] angle
        */
        [[nodiscard]] float AngleBetween(const Vec2& other)const noexcept;


        /*
         * @fn Len
         * @brief returns length of the vector
         * @return [float] length
        */
        [[nodiscard]] float Len()const noexcept;


        /*
         * @fn DotProduct
         * @brief returns scalar product
         * @param [const Vec2&] other
         * @return [float] scalar product
        */
        [[nodiscard]] float DotProduct(const Vec2& other)const noexcept;



    private:
        float m_x;
        float m_y;
    };
    // END OF CLASS Vec2





}
// END OF NAMESPACE Bald::Math



//BALD_ENGINE_VEC2_H
