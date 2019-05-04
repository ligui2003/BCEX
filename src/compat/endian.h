// Copyright (c) 2014-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BCEX_ENDIAN_H
#define BCEX_ENDIAN_H

#include "config/bcex_config.h"
#include "compat/byteswap.h"

#include <stdint.h>

    // 判断是否是大字节序
    #if defined(WORDS_BIGENDIAN)  
    /// ----------------  BIG ENDIAN ---------------------

        inline uint16_t htobe16(uint16_t host_16bits)
        {
            return host_16bits;
        }

        inline uint16_t htole16(uint16_t host_16bits)
        {
            return bswap_16(host_16bits);
        }

        inline uint16_t be16toh(uint16_t big_endian_16bits)
        {
            return big_endian_16bits;
        }

        inline uint16_t le16toh(uint16_t little_endian_16bits)
        {
            return bswap_16(little_endian_16bits);
        }

        inline uint32_t htobe32(uint32_t host_32bits)
        {
            return host_32bits;
        }

        inline uint32_t htole32(uint32_t host_32bits)
        {
            return bswap_32(host_32bits);
        }

        inline uint32_t be32toh(uint32_t big_endian_32bits)
        {
            return big_endian_32bits;
        }

        inline uint32_t le32toh(uint32_t little_endian_32bits)
        {
            return bswap_32(little_endian_32bits);
        }

        inline uint64_t htobe64(uint64_t host_64bits)
        {
            return host_64bits;
        }

        inline uint64_t htole64(uint64_t host_64bits)
        {
            return bswap_64(host_64bits);
        }

        inline uint64_t be64toh(uint64_t big_endian_64bits)
        {
            return big_endian_64bits;
        }

        inline uint64_t le64toh(uint64_t little_endian_64bits)
        {
            return bswap_64(little_endian_64bits);
        }

    #else       // WORDS_BIGENDIAN
    /// ----------------  LITTLE ENDIAN ---------------------
        inline uint16_t htobe16(uint16_t host_16bits)
        {
            return bswap_16(host_16bits);
        }

        inline uint16_t htole16(uint16_t host_16bits)
        {
            return host_16bits;
        }

        inline uint16_t be16toh(uint16_t big_endian_16bits)
        {
            return bswap_16(big_endian_16bits);
        }

        inline uint16_t le16toh(uint16_t little_endian_16bits)
        {
            return little_endian_16bits;
        }

        inline uint32_t htobe32(uint32_t host_32bits)
        {
            return bswap_32(host_32bits);
        }

        inline uint32_t htole32(uint32_t host_32bits)
        {
            return host_32bits;
        }

        inline uint32_t be32toh(uint32_t big_endian_32bits)
        {
            return bswap_32(big_endian_32bits);
        }

        inline uint32_t le32toh(uint32_t little_endian_32bits)
        {
            return little_endian_32bits;
        }

        inline uint64_t htobe64(uint64_t host_64bits)
        {
            return bswap_64(host_64bits);
        }

        inline uint64_t htole64(uint64_t host_64bits)
        {
            return host_64bits;
        }

        inline uint64_t be64toh(uint64_t big_endian_64bits)
        {
            return bswap_64(big_endian_64bits);
        }

        inline uint64_t le64toh(uint64_t little_endian_64bits)
        {
            return little_endian_64bits;
        }

    #endif      // WORDS_BIGENDIAN

#endif      // BCEX_ENDIAN_H
