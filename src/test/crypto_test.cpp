#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "crypto/sha1.h"
#include "util/strencodings.h"

TEST(crypto_test,sha1)
{
    std::string str = "hello sha1";

    CSHA1 sha1;
    sha1.Write((unsigned char*)str.c_str(),str.length());

    unsigned char buf[CSHA1::OUTPUT_SIZE];
    memset(buf,0,CSHA1::OUTPUT_SIZE);

    sha1.Finalize(buf);

    EXPECT_EQ(HexStr(buf,buf+CSHA1::OUTPUT_SIZE),"64faca92dec81be17500f67d521fbd32bb3a6968");
}
