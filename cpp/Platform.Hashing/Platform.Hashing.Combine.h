#pragma once

#ifndef PLATFORM_HASHING_COMBINE
#define PLATFORM_HASHING_COMBINE

#include <crc32c.h>

namespace Platform::Hashing
{
    template<typename T> void Combine(std::uint32_t &hashAccumulator, T &&value)
    {
        size_t size = sizeof(T);
        hashAccumulator = crc32c_append(hashAccumulator, reinterpret_cast<const uint8_t *>(&value), size);
    }
}

#endif
