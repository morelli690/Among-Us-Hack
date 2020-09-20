//  :copyright: (c) Copyright 2001-2004 Unicode, Inc.
//  :copyright: (c) 2016 The Regents of the University of California.
//  :license: Unicode, see LICENSE.md for more details.
/**
 *  \addtogroup Utf++
 *  \brief Convert Unicode code points between encodings.
 */

#include "utf.hpp"
#include <cstdlib>


namespace utf
{
    namespace detail
    {

        // HELPERS
        // -------


        /** \brief Replace illegal Unicode character if checkStrict is off.
         */
        uint32_t checkStrict(bool strict)
        {
            constexpr uint32_t replacement = 0x0000FFFD;
            if (strict)
            {
                throw IllegalCharacterError();
            }
            return replacement;
        }

    }   /* detail */

    // FUNCTIONS
    // ---------


    /** \brief STL wrapper for narrow to wide conversions.
     */
    template <typename C1, typename C2, typename Function>
    std::string toWide(const std::string& string,
        Function function)
    {
        // types
        constexpr size_t size1 = sizeof(C1);
        constexpr size_t size2 = sizeof(C2);

        // arguments
        const size_t srclen = string.size() / size1;
        const size_t dstlen = srclen;
        auto* src = reinterpret_cast<const C1*>(string.data());
        auto* srcEnd = src + srclen;
        auto* dst = reinterpret_cast<C2*>(malloc(dstlen * size2));
        auto* dstEnd = dst + dstlen;

        size_t out = function(src, srcEnd, dst, dstEnd, true);
        std::string output(reinterpret_cast<const char*>(dst), out * size2);
        free(dst);

        return output;
    }


    /** \brief STL wrapper for wide to narrow conversions.
     */
    template <typename C1, typename C2, typename Function>
    std::string toNarrow(const std::string& string,
        Function function)
    {
        // types
        constexpr size_t size1 = sizeof(C1);
        constexpr size_t size2 = sizeof(C2);

        // arguments
        const size_t srclen = string.size() / size1;
        const size_t dstlen = srclen * 4;
        auto* src = reinterpret_cast<const C1*>(string.data());
        auto* srcEnd = src + srclen;
        auto* dst = reinterpret_cast<C2*>(malloc(dstlen * size2));
        auto* dstEnd = dst + dstlen;

        size_t out = function(src, srcEnd, dst, dstEnd, true);
        std::string output(reinterpret_cast<const char*>(dst), out * size2);
        free(dst);

        return output;
    }


    /** \brief STL wrapper for utf8To16.
     */
    std::string utf8To16(const std::string& string)
    {
        // types
        using C1 = uint8_t;
        using C2 = uint16_t;
        using Function = decltype(detail::utf8To16<const C1*, C2*>);

        return toWide<C1, C2, Function>(string, detail::utf8To16);
    }

    /** \brief STL wrapper for utf8To32.
     */
    std::string utf8To32(const std::string& string)
    {
        // types
        using C1 = uint8_t;
        using C2 = uint32_t;
        using Function = decltype(detail::utf8To32<const C1*, C2*>);

        return toWide<C1, C2, Function>(string, detail::utf8To32);
    }


    /** \brief STL wrapper for utf16To32.
     */
    std::string utf16To32(const std::string& string)
    {
        // types
        using C1 = uint16_t;
        using C2 = uint32_t;
        using Function = decltype(detail::utf16To32<const C1*, C2*>);

        return toWide<C1, C2, Function>(string, detail::utf16To32);
    }


    /** \brief STL wrapper for utf16To8.
     */
    std::string utf16To8(const std::string& string)
    {
        // types
        using C1 = uint16_t;
        using C2 = uint8_t;
        using Function = decltype(detail::utf16To8<const C1*, C2*>);

        return toNarrow<C1, C2, Function>(string, detail::utf16To8);
    }


    /** \brief STL wrapper for utf32To8.
     */
    std::string utf32To8(const std::string& string)
    {
        // types
        using C1 = uint32_t;
        using C2 = uint8_t;
        using Function = decltype(detail::utf32To8<const C1*, C2*>);

        return toNarrow<C1, C2, Function>(string, detail::utf32To8);
    }


    /** \brief STL wrapper for utf32To16.
     */
    std::string utf32To16(const std::string& string)
    {
        // types
        using C1 = uint32_t;
        using C2 = uint16_t;
        using Function = decltype(detail::utf32To16<const C1*, C2*>);

        return toNarrow<C1, C2, Function>(string, detail::utf32To16);
    }

}   /* utf */