// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BCEX_STRENCODINGS_H
#define BCEX_STRENCODINGS_H

#include <cstdint>
#include <iterator>
#include <string>
#include <vector>

// Used by SanitizeString()
enum SafeChars
{
    SAFE_CHARS_DEFAULT,     //!< The full set of allowed chars
    SAFE_CHARS_UA_COMMENT,  //!< BIP-0014 subset
    SAFE_CHARS_FILENAME,    //!< Chars allowed in filenames
    SAFE_CHARS_URI,         //!< Chars allowed in URIs (RFC 3986)
};

std::string SanitizeString(const std::string& str,int rule = SAFE_CHARS_DEFAULT);
std::vector<unsigned char> ParseHex(const char* psz);
std::vector<unsigned char> ParseHex(const std::string& str);
signed char HexDigit(char c);

bool IsHex(const std::string& str);

bool IsHexNumber(const std::string& str);

std::vector<unsigned char> DecodeBase64(const char* p,bool* pf_invalid = nullptr);
std::string DecodeBase64(const std::string& str,bool* pf_invalid = nullptr);
std::string EncodeBase64(const unsigned char* pch,size_t len);
std::string EncodeBase64(const std::string& str);

std::vector<unsigned char> DecodeBase32(const char* p, bool* pf_invalid = nullptr);
std::string DecodeBase32(const std::string& str, bool* pf_invalid = nullptr);
std::string EncodeBase32(const unsigned char* pch, size_t len);
std::string EncodeBase32(const std::string& str);

void SplitHostPort(std::string in,int &portOut,std::string &hostOut);

std::string i64toStr(int64_t n);
std::string itoStr(int n);
int64_t atoi64(const char* psz);
int64_t atoi64(const std::string& str);
int atoi(const std::string& str);

// 是否是数字
constexpr bool IsDigit(char c)
{
    return c >= '0' && c <= '9';
}

// 判断空格
constexpr inline bool IsSpace(char c) noexcept
{
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

bool ParseInt32(const std::string& str,int32_t *out);
bool ParseInt64(const std::string& str,int64_t *out);
bool ParseUInt32(const std::string& str, uint32_t *out);
bool ParseUInt64(const std::string& str, uint64_t *out);
bool ParseDouble(const std::string& str, double *out);

template<typename T>
std::string HexStr(const T itbegin, const T itend)
{
    std::string rv;
    static const char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    rv.reserve(std::distance(itbegin, itend) * 2);
    for(T it = itbegin; it < itend; ++it)
    {
        unsigned char val = (unsigned char)(*it);
        rv.push_back(hexmap[val>>4]);
        rv.push_back(hexmap[val&15]);
    }
    return rv;
}

template<typename T>
inline std::string HexStr(const T& vch)
{
    return HexStr(vch.begin(), vch.end());
}

std::string FormatParagraph(const std::string& in, size_t width = 79, size_t indent = 0);


template <typename T>
bool TimingResistantEqual(const T& a, const T& b)
{
    if (b.size() == 0) return a.size() == 0;
    size_t accumulator = a.size() ^ b.size();
    for (size_t i = 0; i < a.size(); i++)
        accumulator |= a[i] ^ b[i%b.size()];
    return accumulator == 0;
}

bool ParseFixedPoint(const std::string &val, int decimals, int64_t *amount_out);

template<int frombits, int tobits, bool pad, typename O, typename I>
bool ConvertBits(const O& outfn, I it, I end) {
    size_t acc = 0;
    size_t bits = 0;
    constexpr size_t maxv = (1 << tobits) - 1;
    constexpr size_t max_acc = (1 << (frombits + tobits - 1)) - 1;
    while (it != end) {
        acc = ((acc << frombits) | *it) & max_acc;
        bits += frombits;
        while (bits >= tobits) {
            bits -= tobits;
            outfn((acc >> bits) & maxv);
        }
        ++it;
    }
    if (pad) {
        if (bits) outfn((acc << (tobits - bits)) & maxv);
    } else if (bits >= frombits || ((acc << (tobits - bits)) & maxv)) {
        return false;
    }
    return true;
}

constexpr char ToLower(char c)
{
    return (c >= 'A' && c <= 'Z' ? (c - 'A') + 'a' : c);
}

constexpr char ToUpper(char c)
{
    return (c >= 'a' && c <= 'z' ? (c - 'a') + 'A' : c);
}

void Downcase(std::string& str);

std::string Capitalize(std::string str);


#endif // BCEX_STRENCODINGS_H
