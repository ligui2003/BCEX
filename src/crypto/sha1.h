// Copyright (c) 2014-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BECX_SHA1_H
#define BECX_SHA1_H

#include <stdint.h>
#include <stdlib.h>
#include <string>

// A hasher class for SHA1.
class CSHA1
{
public:
    static const size_t OUTPUT_SIZE = 20;

    CSHA1();
    CSHA1&      Write(const unsigned char* data,size_t len);
    void        Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA1&      Reset();
    std::string ToString();
private:
    uint32_t        s[5];
    unsigned char   buf[64];
    uint64_t        bytes;
};

#endif // BECX_SHA1_H
