//
// Created by blinku on 16.02.2020.
//

#pragma once

#include "debug/bald_assert.hpp"
#include "event.hpp"
#include "pch.hpp"

namespace Bald::Events {

class EventBus {
  template <typename EventType>
  using Callback = std::function<void(const EventType &)>;

  template <typename EventType>
  using CallbackContainer = std::vector<Callback<EventType>>;

public:
  EventBus() = delete;

  EventBus(const EventBus &) = delete;

  EventBus(EventBus &&) = delete;

  EventBus &operator=(const EventBus &) = delete;

  EventBus &operator=(EventBus &&) = delete;

  template <typename EventType>
  static void Subscribe(Callback<EventType> callback) {
    m_Callbacks<EventType>.push_back(std::move(callback));
  }

  template <typename EventType, typename Function, typename... Args>
  static void Subscribe(Function &&callback, Args &&... args) {
    BALD_STATIC_ASSERT(std::is_base_of_v<Event, EventType>,
                       "EventType must be derived from Event!");
    if constexpr (std::is_member_function_pointer_v<Function>) {
      Unpack<EventType>(std::forward<Function>(callback),
                        std::forward<Args>(args)...);
    } else {
      auto callbackWrapper = [=](const EventType &e) {
        std::invoke(callback, e, args...);
      };
      m_Callbacks<EventType>.push_back(std::move(callbackWrapper));
    }
  }

  template <typename EventType> static void Emit(const EventType &e) {
    Dispatch<EventType>(e);
  }

  template <typename EventType, typename... Args>
  static void Emit(Args &&... args) {
    Dispatch<EventType>(EventType{args...});
  }

private:
  template <typename EventType> static void Dispatch(const EventType &e) {
    const auto &callbacks = m_Callbacks<EventType>;
    for (auto &callback : callbacks) {
      std::invoke(callback, e);
    }
  }

  template <typename EventType, typename Function, typename Object,
            typename... Args>
  static void Unpack(Function &&callback, Object &&object, Args &&... args) {
    auto callbackWrapper = [callback = std::forward<Function>(callback),
                            object = std::forward<Object>(object),
                            args...](const EventType &e) {
      std::invoke(callback, object, e, args...);
    };
    m_Callbacks<EventType>.push_back(std::move(callbackWrapper));
  }

  template <typename EventType> static CallbackContainer<EventType> m_Callbacks;

}; // END OF CLASS EventBus

template <typename EventType>
EventBus::CallbackContainer<EventType> EventBus::m_Callbacks = {};

} // END OF NAMESPACE Bald::Events
