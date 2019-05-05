cmake_minimum_required(VERSION 3.0)

project(bcex)

include_directories(
                    ${PROJECT_SOURCE_DIR}
                    "${PROJECT_SOURCE_DIR}/../include/"
                   )

link_directories("${PROJECT_SOURCE_DIR}/../libs/")

configure_file(
    "${PROJECT_SOURCE_DIR}/config/bcex_config.h.in"
    "${PROJECT_SOURCE_DIR}/config/bcex_config.h"
    )


IF( WIN32 )
    message( STATUS "bcex on Windows" )

    include_directories("C:/code/include/")
    link_directories("C:/code/libs")

    link_libraries(libsecp256k1)
ELSE(WIN32)
    link_libraries(secp256k1)

    if( APPLE )
      # Apple Specific Options Here
      message( STATUS "bcex on OS X" )

    else( APPLE )
      # Linux Specific Options Here
      message( STATUS "bcex on Linux" )

    endif( APPLE )

ENDIF(WIN32)


add_executable(${PROJECT_NAME} "main.cpp"
                "vo/uint256.cpp"             
                "util/strencodings.cpp"
                "crypto/sha1.h"
                "crypto/common.h"
                "compat/byteswap.h"
                "compat/endian.h"
                "test/crypto_test.hpp"

                "config/bcex_config.h"


                "vo/uint256.h"              
                "util/strencodings.h"
                "crypto/sha1.cpp"

                "../include/secp256k1/secp256k1.h"
    )

IF( WIN32 )
    target_link_libraries(${PROJECT_NAME} libsecp256k1)
ELSE(WIN32)
    target_link_libraries(${PROJECT_NAME} secp256k1)

    if( APPLE )


    else( APPLE )

      message( STATUS "bcex on Linux" )

    endif( APPLE )

ENDIF(WIN32)


