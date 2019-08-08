//
// Created by blinku on 06.05.19.
//

#pragma once

/**
 * This is the engine's entry point.
 */

#ifdef LINUX

int main() {
    Bald::Debug::LogManager::Init();

    auto* application = Bald::Application::Create();

    application->Run();

    delete application;
}

#else

int main() {
    Bald::Logger::Init();

    auto* application = Bald::Application::Create();

    application->Run();

    delete application;
}

#endif