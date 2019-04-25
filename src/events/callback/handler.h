//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include <vector>
#include <functional>
#include "Log.h"

/**
 * @class Callback
 * @brief Abstract class whose job is to provide a simple function-wrapper API
 */

namespace Bald {

    class Handler {
    public:

        /**
        * @fn                   Handler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit Handler(F&& fun, Args&& ... args);

        /**
        * @fn                   ~Handler
        * @brief                Virtual destructor
        */

        virtual ~Handler();

        /**
        * @fn                   GetID
        * @brief                ID getter
        * @return [unsigned]    Function's id
        */

        [[nodiscard]] inline unsigned GetID() const noexcept { return m_ID; }

        /**
        * @fn                   Run
        * @brief                Virtual method which provides an API for implementing function calls.
        *                       Right now we use it to provide option for synchronous and asynchronous function calls
        */

        virtual void Run() const = 0;

        /**
        * @fn                   operator==
        * @brief                This operator is used to compare two different instances of type Handler.
        */

        inline bool operator==(const unsigned& other) const;

    protected:
        static std::vector<bool> m_TakenID; /**< Vector of currently used IDs. We use IDs to differentiate functions and
                                                     for ex. remove one of such from some type of queue */

        std::function<void()> m_Function; /**< Function wrapper */
        unsigned m_ID; /**< This instance's id. When this value is 0 it means that handler is not used. */

    }; // END OF CLASS Handler

    template<class F, class... Args>
    Handler::Handler(F&& fun, Args&& ... args) : m_ID{0} {
        for(unsigned int i = 1; i < UINT32_MAX; ++i) {
            if(i <= m_TakenID.size() && m_TakenID[i - 1] == false) {
                m_TakenID[i - 1] = true;
                m_ID = i;
                break;
            } else if (i > m_TakenID.size()) {
                m_TakenID.push_back(true);
                m_ID = i;
                break;
            }
        }

        if(m_ID != 0) {
            m_Function = [=]() {
                fun(args...);
            };
        } else {
            CORE_LOG_WARN("[Handler] Could not create Handler object because maximum number of ID's was reached");
        }

    }

    bool Handler::operator==(const unsigned& other) const {
        return m_ID == other;
    }

} //END OF NAMESPACE Bald
