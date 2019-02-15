//
// Created by ajer on 15.02.19.
//

#include "Window.h"
#include <iostream>

using namespace Bald;
using namespace Graphics;

int main() {

    Window test("Test window!", 900, 650);

    test.WindowSetVSync(true);

    while (!test.ShouldClose()) {

        // do stuff

        test.Update();
        test.Clear();

    }


    return 0;
}