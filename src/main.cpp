#include <iostream>
#include <istream>
#include <string>

#include "crypto/sha1.h"
#include "util/strencodings.h"

int main()
{
    std::cout << "Hello BCEX!" << std::endl;

    std::string str = "hello sha1";

    CSHA1 sha1;
    sha1.Write((unsigned char*)str.c_str(),str.length());

    unsigned char buf[CSHA1::OUTPUT_SIZE];
    memset(buf,0,CSHA1::OUTPUT_SIZE);

    sha1.Finalize(buf);

    std::cout << HexStr(buf,buf+CSHA1::OUTPUT_SIZE) << std::endl;

    std::string cmd = "";

    std::cin >> cmd;





    return 0;
}
