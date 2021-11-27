#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "2\n"
                "3 4\n"
                "3\n"
                "1 2 3"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "3 3"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "2\n"
            "4 5\n"
            "3\n"
            "1 2 3"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "4 3"
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "5\n"
            "1 2 3 4 5\n"
            "5\n"
            "1 2 3 4 5"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1 1"
    );
}
