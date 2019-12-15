#pragma once
#include <ostream>

//credit: https://stackoverflow.com/questions/33326039/c-ansi-escape-codes-not-displaying-color-to-console

namespace ansi {
    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& reset(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[0m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_green(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[32m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_red(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[31m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_yellow(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[93m";
    }

    
}
