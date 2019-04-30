// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UINTBASE_H
#define UINTBASE_H

#include <assert.h>
#include <string>
#include <cstring>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

// Template base class for big number
template<uint32_t BITS>
class UintBase
{
protected:
    static constexpr int    WIDTH = BITS / 8;          // size of uint_8
    uint8_t                 data[WIDTH];

public:
    UintBase() { memset(data,0,sizeof(data)); }

    explicit UintBase(const std::vector<uint8_t>& vch);

    bool isNull() const
    {
        for(int i = 0;i < WIDTH;++i)
        {
            if(data[i] != 0)
                return false;
        }

        return true;
    }

    void            setNull() { memset(data,0,sizeof(data)); }

    inline int      compare(const UintBase& other) const { return memcmp(data,other.data,sizeof(data)); }

    friend inline bool operator==(const UintBase& a,const UintBase& b) { return a.compare(b) == 0;}
    friend inline bool operator!=(const UintBase& a,const UintBase& b) { return a.compare(b) != 0;}
    friend inline bool operator<(const UintBase&a, const UintBase& b) { return a.compare(b) < 0;}

    std::string     getHex() const;
    void            setHex(const char* psz);
    void            setHex(const std::string& str);
    std::string     toString() const;

    uint8_t*        begin() { return &data[0]; }
    uint8_t*        end()   { return &data[WIDTH]; }
    const uint8_t*  begin() const { return &data[0]; }
    const uint8_t*  end() const { return &data[WIDTH]; }
    uint32_t        size() const { return sizeof(data); }

    uint64_t getUint64(int pos) const
    {
        const uint8_t* ptr = data + pos * 8;
        return  ((uint64_t)ptr[0]) | \
                ((uint64_t)ptr[1] << 8) | \
                ((uint64_t)ptr[2] << 16) | \
                ((uint64_t)ptr[3] << 24) | \
                ((uint64_t)ptr[4] << 32) | \
                ((uint64_t)ptr[5] << 40) | \
                ((uint64_t)ptr[6] << 48) | \
                ((uint64_t)ptr[7] << 56);
    }

    template<typename Stream>
    void serialize(Stream& s) const { s.write((char*)data,sizeof(data)); }

    template<typename Stream>
    void unSerialize(Stream& s) { s.read((char*)data,sizeof(data)); }
};

/** 160-bit opaque blob.
 * @note This type is called uint160 for historical reasons only. It is an opaque
 * blob of 160 bits and has no integer operations.
 */
class Uint160 : public UintBase<160> {
public:
    Uint160() {}
    explicit Uint160(const std::vector<unsigned char>& vch) : UintBase<160>(vch) {}
};

/** 256-bit opaque blob.
 * @note This type is called uint256 for historical reasons only. It is an
 * opaque blob of 256 bits and has no integer operations. Use arith_uint256 if
 * those are required.
 */
class Uint256 : public UintBase<256> {
public:
    Uint256() {}
    explicit Uint256(const std::vector<unsigned char>& vch) : UintBase<256>(vch) {}
};

/* uint256 from const char *.
 * This is a separate function because the constructor uint256(const char*) can result
 * in dangerously catching uint256(0).
 */
inline Uint256 uint256S(const char *str)
{
    Uint256 rv;
    rv.setHex(str);
    return rv;
}
/* uint256 from std::string.
 * This is a separate function because the constructor uint256(const std::string &str) can result
 * in dangerously catching uint256(0) via std::string(const char*).
 */
inline Uint256 uint256S(const std::string& str)
{
    Uint256 rv;
    rv.setHex(str);
    return rv;
}

#endif // UINTBASE_H






































