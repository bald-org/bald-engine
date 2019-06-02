//
// Created by grzegorz on 08.05.19.
//

#pragma once

#include <vector>

#include "event.h"

namespace Bald {

    /**
     * @class EventHandlerInterface
     * @brief Class which gives us interface for specialized callbacks for events and deals with id's
     */

    class EventHandlerInterface {
    GENERATE_BODY(BASE)
    public:

        /**
         * @fn EventHandlerInterface()
         * @brief constructs Handler object and gives him unique id
         */

        EventHandlerInterface();

        /**
         * @fn ~EventHandlerInterface
         * @brief destroys Handler object and marks his id as free to use by new handlers
         */

        virtual ~EventHandlerInterface();

        /**
         * @fn GetID()
         * @brief getter for the id of a handler
         * @return
         */

        [[nodiscard]] inline unsigned GetID() const noexcept { return m_ID; }

        /**
         * @fn operator==
         * @brief operator == overloading for unsigned int type to simplify checking the id of a handler
         * @param other [unsigned ing] -> id that we want to check
         * @return [bool] -> true if a handler has the same id as other otherwise false
         */

        inline bool operator==(const unsigned& other) const noexcept { return m_ID == other; }

        /**
         * @fn Run
         * @brief the pure virtual function that is calling a function that we hold in a handler
         * @param ev [const Event&] -> an event that will be passed to a function
         */

        virtual void Run(const Event& ev) const = 0;

    protected:

        static std::vector<bool> m_TakenID; /**< Vector of currently used IDs. We use IDs to differentiate functions and
                                                     for ex. remove one of such from some type of queue */
        unsigned m_ID;                      /**< This instance's id. When this value is 0 it means that handler is not used. */
    };
}




