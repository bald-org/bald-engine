//
// Created by Piotr Moszkowicz on 2019-02-10.
//

#pragma once

namespace Bald::Events {
    /**
     * @struct                              Event
     * @brief                               Basic Event structure
     */
    class Event {
    public:
        /**
         * @fn                              getId
         * @brief                           Virtual function, which gets eventId
         * @return [unsigned int]           eventId
         */
        virtual unsigned int getId() = 0;
        /**
         * @fn                              ~Event
         * @brief                           Virtual destructor of Event class
         */
        virtual ~Event() = default;
    };
}