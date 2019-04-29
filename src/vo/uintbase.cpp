﻿// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uintbase.h"
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
