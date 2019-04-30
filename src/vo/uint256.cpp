// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "vo/uint256.h"
#include "util/strencodings.h"

template<uint32_t BITS>
UintBase<BITS>::UintBase(const std::vector<uint8_t>& vch)
{
    assert(vch.size() == sizeof(data));
    memcpy(data,vch.data(),sizeof(data));
}

template<uint32_t BITS>
std::string UintBase<BITS>::getHex() const
{
    // 反向迭代器
    return HexStr(std::reverse_iterator<const uint8_t*>(data + sizeof(data)), std::reverse_iterator<const uint8_t*>(data));
}

template<uint32_t BITS>
void UintBase<BITS>::setHex(const char* psz)
{
    memset(data,0,sizeof(data));

    // skip leading spaces
    while(IsSpace(*psz))
        psz++;

    // skip 0x
    if(psz[0] == '0' && ToLower(psz[1]) == 'x')
        psz += 2;

    // hex string to uint
    const char* pbegin = psz;

    while(::HexDigit(*psz) != -1)
        psz++;
    psz--;

    uint8_t* p1 = (uint8_t*)data;
    uint8_t* pend = p1 + WIDTH;
    while(psz >= pbegin && p1 < pend)
    {
        *p1 = ::HexDigit(*psz--);
        if(psz >= pbegin)
        {
            *p1 |= ((uint8_t)::HexDigit(*psz--) << 4);
            p1++;
        }
    }
}

template <uint32_t BITS>
void UintBase<BITS>::setHex(const std::string& str)
{
    setHex(str.c_str());
}

template <uint32_t BITS>
std::string UintBase<BITS>::toString() const
{
    return (getHex());
}


// Explicit instantiations for UintBase<160>
template UintBase<160>::UintBase(const std::vector<unsigned char>&);
template std::string UintBase<160>::getHex() const;
template std::string UintBase<160>::toString() const;
template void UintBase<160>::setHex(const char*);
template void UintBase<160>::setHex(const std::string&);

// Explicit instantiations for UintBase<256>
template UintBase<256>::UintBase(const std::vector<unsigned char>&);
template std::string UintBase<256>::getHex() const;
template std::string UintBase<256>::toString() const;
template void UintBase<256>::setHex(const char*);
template void UintBase<256>::setHex(const std::string&);