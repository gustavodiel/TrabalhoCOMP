cmake_minimum_required(VERSION 3.12)
project(trabalho_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

FIND_PACKAGE(BISON REQUIRED)
SET(BisonOutput ${CMAKE_SOURCE_DIR}/gram.tab.c)
IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
            OUTPUT ${BisonOutput}
            COMMAND ${BISON_EXECUTABLE}
            -d
            --output=${BisonOutput}
            ${CMAKE_SOURCE_DIR}/gram.y
            COMMENT "BISON: Criando gram.tab.c"
    )
ENDIF()

FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ${CMAKE_SOURCE_DIR}/lex.yy.c)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
            --outfile=${FlexOutput}
            ${CMAKE_SOURCE_DIR}/gram.l
            COMMENT "FLEX: Criando lex.yy.c"
    )
ENDIF()

ADD_CUSTOM_TARGET(
        clearBisonAndFlex
        rm -f ${FlexOutput} ${BisonOutput}
        COMMENT "Cleaning Bison and Flex files"
)

ADD_LIBRARY(TrabalhoFinal ${BisonOutput} ${FlexOutput})

ADD_DEPENDENCIES(TrabalhoFinal clearBisonAndFlex)

ADD_EXECUTABLE(
        main
        Initializers.c Boolean.c Helpers.c gram.c gram.tab.c
)
