//
// Created by ajer on 16.12.18.
//

#pragma once
#include "pch.h"
#include <cmath>

namespace Bald::Math{

    class Vec2{
    public:
        /*
         * @fn Vec2
         * @brief constructor
         * @param [int] x
         * @param [int] y
        */
        Vec2(double x = 0.0, double y = 0.0)
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
         * @brief returns member X variable
        */
        [[nodiscard]] constexpr inline double GetX()const noexcept{return m_x;}
        /*
         * @fn GetY
         * @brief returns member Y variable
        */
        [[nodiscard]] constexpr inline double GetY()const noexcept{return m_y;}

        /*
         * @fn Print
         * @brief prints vec
        */
        inline void Print()const  {
            std::cout << "[" << m_x << ", " << m_y << "]" << std::endl;
        }

        /*
         * @fn operator+
         * @brief adds another vector to the current vector
         * @param [const Vec2&] other vector
        */
        [[nodiscard]] constexpr Vec2& operator+(const Vec2& other)noexcept;

        /*
         * @fn operator*
         * @brief multiplies current vector by the passed multiplier
         * @param [double] multiplier
        */
        [[nodiscard]] constexpr Vec2& operator*(double multiplier)noexcept;


        /*
         * @fn Len
         * @brief returns length of the vector
         * @return [double] length
        */
        double Len()const;
        /*
         * @fn ScalarProduct
         * @brief returns scalar product
         * @param [const Vec2&] other
         * @return [double] scalar product
        */
        double ScalarProduct(const Vec2& other)const;



        // [[nodiscard]] constexpr Vec2 VectorProduct(const Vec2& other)noexcept;

    private:
        double m_x;
        double m_y;
    };





}



//BALD_ENGINE_VEC2_H
