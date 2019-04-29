// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef STRENCODINGS_H
#define STRENCODINGS_H

#include <cstdint>
#include <iterator>
#include <string>
#include <vector>

template<typename T>
std::string HexStr(const T itbegin,const T itend)
{
    std::string rv;
    static const char hexmap[16] = { '0','1','2','3','4','5','6','7',
                                     '8','9','a','b','c','d','e','f' };
    rv.reserve(std::distance(itbegin,itend) * 2);

    for(T it = itbegin;it < itend; ++it)
    {
        uint8_t val = static_cast<uint8_t>(*it);
        rv.push_back(hexmap[val >> 4]);
        rv.push_back(hexmap[val&15]);
    }

    return rv;
}

template<typename T>
inline std::string HexStr(const T& vch)
{
    return HexStr(vch.begin(),vch.end());
}




#endif // STRENCODINGS_H
