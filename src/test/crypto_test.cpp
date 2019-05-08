#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "util/strencodings.h"

static void TestSHA1(const std::string& in,const std::string& out)
{
    CSHA1 sha1;
    sha1.Write((unsigned char*)(in.c_str()),in.length());

    EXPECT_EQ(sha1.ToString(),out);
}


TEST(crypto_test,sha1)
{
    TestSHA1("hello sha1","64faca92dec81be17500f67d521fbd32bb3a6968");  
}

TEST(crypto_test,sha256)
{
  
}
