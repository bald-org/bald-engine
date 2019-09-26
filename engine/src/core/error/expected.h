//
// Created by grzegorz on 18.09.19.
//

#pragma once

#include <utility>
#include "unexpected.h"


namespace Bald {
    template<typename E, typename U>
    class expected {
        union {
            E valid;
            U invalid;
        };
        bool _isOk = true;
    public:
        constexpr expected() { new(&valid) E(); }

        constexpr expected(const E& rhs) { new(&valid) E(rhs); }

        constexpr expected(const unexpected<U>& rhs) :
                _isOk(false) { new(&invalid) U(rhs.value); }

        constexpr expected(E&& rhs) { new(&valid) E(std::forward<E>(rhs)); }

        constexpr expected(unexpected<U>&& rhs) :
                _isOk(false) { new(&invalid) U(std::forward<U>(rhs.value)); }

        constexpr expected(const expected<E, U>& rhs) :
                _isOk(rhs._isOk) {
            if (rhs._isOk) new(&valid) E(rhs.valid);
            else new(&invalid) U(rhs.invalid);
        }

        constexpr expected(expected<E, U>&& rhs) noexcept :
                _isOk(rhs._isOk) {
            if (rhs._isOk) new(&valid) E(std::move(rhs.valid));
            else new(&invalid) U(std::move(rhs.invalid));
        }

        constexpr expected<E, U>& operator=(const expected<E, U>& other) {
            dtor();
            _isOk = other._isOk;
            if (_isOk) new(&valid) E(other.valid);
            else new(&invalid) U(other.invalid);
            return *this;
        }

        constexpr expected<E, U>& operator=(expected<E, U>&& other) noexcept {
            dtor();
            _isOk = other._isOk;
            if (_isOk) new(&valid) E(std::move(other.valid));
            else new(&invalid) U(std::move(other.invalid));
            return *this;
        }

        ~expected() {
            dtor();
        }

        [[nodiscard]] constexpr bool has_value() const noexcept { return _isOk; }

        [[nodiscard]] constexpr bool isOk() const noexcept { return _isOk; }

        constexpr operator bool() const noexcept { return _isOk; }

        [[nodiscard]] constexpr U& error() const& { return invalid; }

        [[nodiscard]] U& error()& { return invalid; }

        [[nodiscard]] U&& error()&& { return std::move(invalid); }

        [[nodiscard]] constexpr E& value() const& { return valid; }

        [[nodiscard]] E& value()& { return valid; }

        [[nodiscard]] E&& value()&& { return std::move(valid); }

    private:
        void dtor() const {
            if (_isOk) valid.~E();
            else invalid.~U();
        }
    };
}

