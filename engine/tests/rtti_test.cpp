//
// Created by grzegorz on 17.05.19.
//

#include "pch.h"
#include "gtest/gtest.h"

#include "utils/type_id.h"
#include "event.h"
#include "key_events.h"



TEST(RTTI, RTTI_test){
    using namespace Bald;
    int i = 0;
    EXPECT_TRUE(get_type_id<int>() == get_type_id<int>());
    EXPECT_FALSE(get_type_id<int>() == get_type_id<double >());
    EXPECT_FALSE(get_type_id<Event>() == get_type_id<KeyEvent>());
    EXPECT_TRUE(get_type_id<int>() == get_type_id(i));
    EXPECT_FALSE(get_type_id(i) == get_type_id<double >());
}