//
// Created by grzegorz on 18.09.19.
//

#pragma once

#include <utility>
#include "unexpected.h"


namespace Bald {
    template <typename E, typename U>
    class expected {
        union {
            E valid;
            U invalid;
        };
        bool _isOk = true;
    public:
        constexpr expected() { new (&valid) E(); }
        constexpr expected(const E& rhs) { new (&valid) E(rhs); }
        constexpr expected(const unexpected<U>& rhs) : _isOk(false) { new (&invalid) U(rhs.value); }
        constexpr expected(E&& rhs) { new (&valid) E(std::forward<E>(rhs)); }
        constexpr expected(unexpected<U>&& rhs): _isOk(false) { new (&invalid) U(std::forward<U>(rhs.value)); }

        ~expected() {
            if(_isOk) valid.~E();
            else invalid.~U();
        }

        constexpr expected(const expected<E, U>& rhs): _isOk(rhs._isOk) {
            if(rhs._isOk) new (&valid) E(rhs.valid);
            else new (&invalid) U(rhs.invalid);
        }
        constexpr expected(expected<E, U>&& rhs) noexcept : _isOk(rhs._isOk) {
            if(rhs._isOk) new (&valid) E(std::move(rhs.valid));
            else new (&invalid) U(std::move(rhs.invalid));
        }

        [[nodiscard]] constexpr bool has_value() const noexcept { return _isOk; }
        [[nodiscard]] constexpr bool isOk() const noexcept { return _isOk; }
        constexpr operator bool() const noexcept { return _isOk; }

        [[nodiscard]] constexpr U& error() const & { return invalid; }
        [[nodiscard]] U& error() & { return invalid; }
        [[nodiscard]] U&& error() && { return std::move(invalid); }

        [[nodiscard]] constexpr E& value() const & { return valid; }
        [[nodiscard]] E& value() & { return valid; }
        [[nodiscard]] E&& value() && { return std::move(valid); }
    };
}

