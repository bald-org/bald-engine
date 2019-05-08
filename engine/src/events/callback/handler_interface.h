//
// Created by grzegorz on 08.05.19.
//

#pragma once

namespace Bald {
    class Event;
    class HandlerInterface {
    public:
        explicit HandlerInterface(): m_ID(0) {
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
        }
        virtual ~HandlerInterface() {
            m_TakenID[m_ID - 1] = false;
        }

        [[nodiscard]] inline unsigned GetID() const noexcept { return m_ID; }

        inline bool operator==(const unsigned& other) const {
            return m_ID == other;
        }

        virtual void Run(const Event& ev) const = 0;

       // virtual auto operator=(const HandlerInterface& ) -> decltype(*this) = default;

    protected:
        static std::vector<bool> m_TakenID; /**< Vector of currently used IDs. We use IDs to differentiate functions and
                                                     for ex. remove one of such from some type of queue */
        unsigned m_ID; /**< This instance's id. When this value is 0 it means that handler is not used. */
    };
}




