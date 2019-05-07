//
// Created by blinku on 06.05.19.
//

#pragma once

#ifdef LINUX

int main() {

    auto* application = Bald::Application::Create();

    application->Run();

    delete application;
}

#endif