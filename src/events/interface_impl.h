//
// Created by grzegorz on 07.05.19.
//

#pragma once

#include "function_handler.h"
#include "async_function_handler.h"


namespace Bald {

    enum class HandleType {
        SYNC, ASYNC
    };

    template<class E>
    void run(const E& event) {
        //static_assert(std::is_base_of<Event, E>::value, "Event is not the base of T");
        for (const auto& callback : E::callbacks) {
            callback.Run(event);
        }

        for (const auto& callback : E::async_callbacks) {
            callback.Run(event);
        }
    }

//    template<>
//    void run<Event>([[maybe_unused]]const Event& event) {
//        assert(false); //TODO: log some info
//    }

    template <class E>
    void Subscribe(const FunctionHandler < E>& ev ){
        //static_assert(std::is_base_of<Event, E>::value, "Event is not the base of T");
        E::callbacks.push_back(ev);
    }

    template <class E>
    void Subscribe(const AsyncFunctionHandler <E>& ev ){
        //static_assert(std::is_base_of<Event, E>::value, "Event is not the base of T");
        E::async_callbacks.push_back(ev);
    }

//    template <>
//    void Subscribe<Event>([[maybe_unused]]const FunctionHandler <Event>& ev ){
//        assert(false);
//    }

//    template <>
//    void Subscribe<Event>([[maybe_unused]]const AsyncFunctionHandler <Event>& ev ){
//        assert(false);
//    }

    template <class E>
    void Unsubscibe(HandleType type, unsigned int id){
        //static_assert(std::is_base_of<Event, E>::value, "Event is not the base of T");
        if (type == HandleType::SYNC) {
            for(auto i = E::callbacks.begin(); i != E::callbacks.end(); i++){
                if(i == id){
                    E::callbacks.erase(i);
                    return;
                }
            }
        } else {
            for(auto i = E::async_callbacks.begin(); i != E::async_callbacks.end(); i++){
                if(i == id){
                    E::async_callbacks.erase(i);
                    return;
                }
            }
        }

    }

//    template <>
//    void Unsubscibe<Event>([[maybe_unused]]HandleType type, [[maybe_unused]]unsigned int id){
//        assert(false);
//    }
}
