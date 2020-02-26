//
// Created by grzegorz on 17.05.19.
//

#include "core/pch.hpp"
#include "gtest/gtest.h"

#include "core/utils/rtti/type_id.hpp"
#include "event.hpp"
#include "key_events.hpp"

TEST(RTTI, RTTI_test){
    using namespace Bald;
    int i = 0;
    EXPECT_TRUE(Utils::get_type_id<int>() == Utils::get_type_id<int>());
    EXPECT_FALSE(Utils::get_type_id<int>() == Utils::get_type_id<double >());
    EXPECT_FALSE(Utils::get_type_id<Events::Event>() == Utils::get_type_id<Events::KeyEvent>());
    EXPECT_TRUE(Utils::get_type_id<int>() == Utils::get_type_id(i));
    EXPECT_FALSE(Utils::get_type_id(i) == Utils::get_type_id<double >());
}
