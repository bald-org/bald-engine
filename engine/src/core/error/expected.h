//
// Created by grzegorz on 18.09.19.
//

#pragma once

#include <utility>
#include "unexpected.h"
#include "bald_assert.h"


namespace Bald {
    template<typename E, typename U>
    class expected {
    public:
        constexpr expected() { new(&m_Valid) E(); }

        constexpr expected(const E& rhs) { new(&m_Valid) E(rhs); }

        constexpr expected(const unexpected<U>& rhs) :
                _isOk(false) { new(&m_Invalid) U(rhs.value); }

        constexpr expected(E&& rhs) { new(&m_Valid) E(std::move(rhs)); }

        constexpr expected(unexpected<U>&& rhs) :
                _isOk(false) { new(&m_Invalid) U(std::move(rhs.value)); }

        constexpr expected(const expected<E, U>& rhs) :
                _isOk(rhs._isOk) {
            if (_isOk) new(&m_Valid) E(rhs.m_Valid);
            else new(&m_Invalid) U(rhs.m_Invalid);
        }

        constexpr expected(expected<E, U>&& rhs) noexcept :
                _isOk(rhs._isOk) {
            if (_isOk) new(&m_Valid) E(std::move(rhs.m_Valid));
            else new(&m_Invalid) U(std::move(rhs.m_Invalid));
        }

        constexpr expected<E, U>& operator=(const expected<E, U>& rhs) {
            dtor();
            _isOk = rhs._isOk;
            if (_isOk) new(&m_Valid) E(rhs.m_Valid);
            else new(&m_Invalid) U(rhs.m_Invalid);
            return *this;
        }

        constexpr expected<E, U>& operator=(expected<E, U>&& rhs) noexcept {
            dtor();
            _isOk = rhs._isOk;
            if (_isOk) new(&m_Valid) E(std::move(rhs.m_Valid));
            else new(&m_Invalid) U(std::move(rhs.m_Invalid));
            return *this;
        }

        ~expected() {
            dtor();
        }

        [[nodiscard]] constexpr bool isValid() const noexcept { return _isOk; }

        constexpr operator bool() const noexcept { return _isOk; }

        [[nodiscard]] constexpr U& error() const& {
            BALD_ASSERT(!_isOk, "expected", "attempt to access invalid value after success", _isOk);
            return m_Invalid;
        }

        [[nodiscard]] U& error()& {
            BALD_ASSERT(!_isOk, "expected", "attempt to access invalid value after success", _isOk);
            return m_Invalid;
        }

        [[nodiscard]] U&& error()&& {
            BALD_ASSERT(!_isOk, "expected", "attempt to access invalid value after success", _isOk);
            return std::move(m_Invalid);
        }

        [[nodiscard]] constexpr E& value() const& {
            BALD_ASSERT(_isOk, "expected", "attempt to access valid value after failure", _isOk);
            return m_Valid;
        }

        [[nodiscard]] E& value()& {
            BALD_ASSERT(_isOk, "expected", "attempt to access valid value after failure", _isOk);
            return m_Valid;
        }

        [[nodiscard]] E&& value()&& {
            BALD_ASSERT(_isOk, "expected", "attempt to access valid value after failure", _isOk);
            return std::move(m_Valid);
        }

    private:
        void dtor() const noexcept {
            if (_isOk) m_Valid.~E();
            else m_Invalid.~U();
        }

    private:
        union {
            E m_Valid;
            U m_Invalid;
        };
        bool _isOk = true;
    };
}

