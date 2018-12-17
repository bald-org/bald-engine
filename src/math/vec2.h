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
         * @fn Vec2
         * @brief copy constructor
         * @param [const Vec2&] other vector
        */
        Vec2(const Vec2& other)
                :m_x(other.m_x), m_y(other.m_y){}


        /*
         * @fn GetX
         * @brief returns m_x variable
        */
        [[nodiscard]] constexpr inline float GetX()const noexcept{return m_x;}
        /*
         * @fn GetY
         * @brief returns m_y variable
        */
        [[nodiscard]] constexpr inline float GetY()const noexcept{return m_y;}

        /*
         * @fn Print
         * @brief prints vec
        */
        inline void Print()const{std::cout << "[" << m_x << ", " << m_y << "]" << std::endl;}



                 // OPERATORS

        /*
         * @fn operator<<
         * @brief prints the vec2
         * @param [std::ostream&] output stream
         * @param [const Vec2&] vector object to be printed
        */
        [[nodiscard]] friend std::ostream& operator<<(std::ostream& out, const Vec2& vec)noexcept ;

        /*
         * @fn operator+
         * @brief adds another vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] Vec2 operator+(const Vec2& other)const noexcept;

        /*
         * @fn operator*
         * @brief multiplies current vector by the passed multiplier
         * @param [float] multiplier
        */
        [[nodiscard]] Vec2 operator*(float multiplier) const noexcept;

        /*
         * @fn operator=
         * @brief copies the values of other Vec2 to current Vec2
         * @param [const Vec&] other Vec2
        */
        [[nodiscard]] Vec2& operator=(const Vec2& other)noexcept;

        /*
         * @fn operator==
         * @brief checks if the two vectors are the same
         * @param [const Vec&] other Vec2
        */
        [[nodiscard]] bool operator==(const Vec2& other) const noexcept;


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
