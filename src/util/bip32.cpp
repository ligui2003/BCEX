// Copyright (c) 2019 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <sstream>
#include <stdio.h>

#include "util/tinyformat.h"
#include "util/bip32.h"
#include "util/strencodings.h"


bool ParseHDKeypath(const std::string& keypath_str,std::vector<uint32_t>& keypath)
{
    std::stringstream ss(keypath_str);

    return true;
}
