cmake_minimum_required(VERSION 3.0)

project(bcex)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_REQUIRED_FLAGS -std=c++17)

include_directories(
                    ${PROJECT_SOURCE_DIR}
                    "${PROJECT_SOURCE_DIR}/../include/"
                   )

link_directories("${PROJECT_SOURCE_DIR}/../libs/debug/")

configure_file(
    "${PROJECT_SOURCE_DIR}/config/bcex_config.h.in"
    "${PROJECT_SOURCE_DIR}/config/bcex_config.h"
    )


IF( WIN32 )
    message( STATUS "bcex on Windows" )

    include_directories("C:/code/include/")
    link_directories("C:/code/libs"
        "C:/code/libs/x64/debug")

    set(DEBUG_LIB libsecp256k1 gmockd gtestd event  ws2_32)
    set(RELEASE_LIB libsecp256k1 gmock gtest event ws2_32)

    link_libraries(${DEBUG_LIB})
ELSE(WIN32)
    link_libraries(secp256k1)

    if( APPLE )
      # Apple Specific Options Here
      message( STATUS "bcex on OS X" )

    else( APPLE )
      # Linux Specific Options Here
      message( STATUS "bcex on Linux" )
      include_directories("/usr/local/include/")
      link_directories("/usr/local/lib")

      link_libraries( secp256k1
                      gmock
                      gtest)

    endif( APPLE )

ENDIF(WIN32)


add_executable(${PROJECT_NAME} "main.cpp"
                "vo/uint256.cpp"             
                "util/strencodings.cpp"
                "util/url.cpp"
                "util/bip32.cpp"
                "crypto/sha1.cpp"
                "crypto/sha256.cpp"
                "crypto/sha512.cpp"
                "crypto/sha256_avx2.cpp"
                "crypto/sha256_shani.cpp"
                "crypto/sha256_sse4.cpp"
                "crypto/sha256_sse41.cpp"
                "crypto/hmac_sha256.cpp"
                "crypto/siphash.cpp"
                "crypto/ctaes/ctaes.c"
                "crypto/aes.cpp"
                "crypto/chacha20.cpp"
                "crypto/hmac_sha512.cpp"
                "crypto/ripemd160.cpp"
                "test/crypto_test.cpp"
    
                "config/bcex_config.h"


                "vo/uint256.h"              
                "util/strencodings.h"
                "util/url.h"
                "util/tinyformat.h"
                "util/memory.h"
                "util/bip32.h"
                "util/attributes.h"
                "crypto/ctaes/ctaes.h"
                "crypto/sha1.h"
                "crypto/sha256.h"
                "crypto/sha512.h"
                "crypto/siphash.h"
                "crypto/aes.h"
                "crypto/hmac_sha256.h"
                "crypto/common.h"
                "crypto/chacha20.h"
                "crypto/hmac_sha512.h"
                "crypto/ripemd160.h"
                "compat/byteswap.h"
                "compat/endian.h"
    )

IF( WIN32 )
    target_link_libraries(${PROJECT_NAME} ${DEBUG_LIB})
ELSE(WIN32)
    target_link_libraries(${PROJECT_NAME} secp256k1 gmock gtest)

    if( APPLE )


    else( APPLE )

      message( STATUS "bcex on Linux" )

    endif( APPLE )

ENDIF(WIN32)


