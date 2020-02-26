//
// Created by blinku on 06.05.19.
//

#pragma once

/**
 * This is the engine's entry point.
 */

int main() {
    Bald::Debug::LogManager::Init();

    auto* application = Bald::Application::Create();

    application->Run();

    delete application;
}

