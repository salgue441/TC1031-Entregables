// =================================================================
//
// File: test1.cpp
// Author: Pedro Perez
// Description: This file contains the test cases for the functions
//				of this activity have to pass. IMPORTANT: this file
//				should not be modified.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "activity.h"

TEST_CASE("Testing suma_iterativa", "[suma_iterativa]")
{
    REQUIRE(suma_iterativa(1) == 1);
    REQUIRE(suma_iterativa(10) == 55);
    REQUIRE(suma_iterativa(50) == 1275);
    REQUIRE(suma_iterativa(100) == 5050);
    REQUIRE(suma_iterativa(500) == 125250);
}

TEST_CASE("Testing suma_recursiva", "[suma_recursiva]")
{
    REQUIRE(suma_recursiva(1) == 1);
    REQUIRE(suma_recursiva(10) == 55);
    REQUIRE(suma_recursiva(50) == 1275);
    REQUIRE(suma_recursiva(100) == 5050);
    REQUIRE(suma_recursiva(500) == 125250);
}

TEST_CASE("Testing suma_directa", "[suma_directa]")
{
    REQUIRE(suma_directa(1) == 1);
    REQUIRE(suma_directa(10) == 55);
    REQUIRE(suma_directa(50) == 1275);
    REQUIRE(suma_directa(100) == 5050);
    REQUIRE(suma_directa(500) == 125250);
}