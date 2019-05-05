#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "util/strencodings.h"

TEST(crypto_test,sha1)
{
    std::string str;

    CSHA1 sha1,sha2;

    str = "hello sha1";
    sha1.Write((unsigned char*)(str.c_str()),str.length());

    str = "1111111111" \
          "2222222222" \
          "3333333333" \
          "4444444444" \
          "5555555555" \
          "6666666666" \
          "7777777777" \
          "8888888888" \
          "9999999999";
    sha2.Write((unsigned char*)str.c_str(),str.length());

    EXPECT_EQ(sha1.ToString(),"64faca92dec81be17500f67d521fbd32bb3a6968");
    EXPECT_EQ(sha2.ToString(),"ae8435712d9a8dc2b4cc4170a8586c1357a3cb9f");
}

TEST(crypto_test,sha256)
{
    std::string str;

    CSHA256 sha1,sha2;

    str = "hello sha256";
    sha1.Write((unsigned char*)(str.c_str()),str.length());

    str = "1111111111" \
          "2222222222" \
          "3333333333" \
          "4444444444" \
          "5555555555" \
          "6666666666" \
          "7777777777" \
          "8888888888" \
          "9999999999";
    sha2.Write((unsigned char*)str.c_str(),str.length());

    EXPECT_EQ(sha1.ToString(),"433855b7d2b96c23a6f60e70c655eb4305e8806b682a9596a200642f947259b1");
    EXPECT_EQ(sha2.ToString(),"c4580204e43a31ef166e3f60bd38bf2286363ca734251a42d3ed40520cd21c1d");
}
