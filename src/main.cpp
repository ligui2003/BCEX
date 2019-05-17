#include <iostream>
#include <istream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "util/url.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}
