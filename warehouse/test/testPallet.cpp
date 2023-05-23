#include "include/catch.hpp"
#include "../src/include/pallet.hpp"


/**
 * Test cases for Pallet
*/
TEST_CASE("Test case for Pallet constructor. Check for values (string Books, int 10, 6)", "constructors, constructor Pallet") {
    Pallet p("Books", 10, 6);
    REQUIRE(p.getItemName() == "Books");
    REQUIRE(p.getRemainingSpace() + p.getItemCount() == 10);
    REQUIRE(p.getItemCount() == 6);
}

TEST_CASE("Test case for default Pallet. Check if values are ("", 0, 0)", "constructors, default Pallet") {
    Pallet p;
    REQUIRE(p.getItemName() == "");
    REQUIRE(p.getRemainingSpace() + p.getItemCount() == 0);
    REQUIRE(p.getItemCount() == 0);
}

TEST_CASE("Test if function returns Books", "getItemName()") {
    Pallet p("Books", 10, 6);
    REQUIRE(p.getItemName() == "Books");
}

TEST_CASE("Test if function returns 6", "getItemCount()") {
    Pallet p("Books", 10, 6);
    REQUIRE(p.getItemCount() == 6);
}

TEST_CASE("Test if function returns 4", "getRemainingSpace()") {
    Pallet p("Books", 10, 6);
    REQUIRE(p.getRemainingSpace() == 4);
}

TEST_CASE("Test if function reallocateEmptyPallet() returns true", "reallocateEmptyPallet()") {
    Pallet p("Books", 10, 0);
    REQUIRE(p.reallocateEmptyPallet("Books", 20) == true);
}

TEST_CASE("Test if function reallocateEmptyPallet() returns false", "reallocateEmptyPallet()") {
    Pallet p("Books", 10, 1);
    REQUIRE(p.reallocateEmptyPallet("Books", 20) == false);
}

TEST_CASE("Test if function takeOne() returns true and deducts from itemCount", "takeOne()") {
    Pallet p("Books", 10, 1);
    REQUIRE(p.takeOne() == true);
    REQUIRE(p.getItemCount() == 0);
}

TEST_CASE("Test if function takeOne() returns false", "takeOne()") {
    Pallet p("Books", 10, 0);
    REQUIRE(p.takeOne() == false);
}

TEST_CASE("Test if function putOne() returns true and added to itemCount", "putOne()") {
    Pallet p("Books", 10, 0);
    REQUIRE(p.putOne() == true);
    REQUIRE(p.getItemCount() == 1);
}

TEST_CASE("Test if function putOne() returns false", "putOne()") {
    Pallet p("Books", 10, 10);
    REQUIRE(p.putOne() == false);
}

TEST_CASE("Test if function isFull() for Pallet returns true", "isFull()") {
    Pallet p("Books", 10, 10);
    REQUIRE(p.isFull() == true);
}

TEST_CASE("Test if function isFull() for Pallet returns false", "isFull()") {
    Pallet p("Books", 10, 1);
    REQUIRE(p.isFull() == false);
}

TEST_CASE("Test if function isEmpty() for Pallet returns true", "isEmpty()") {
    Pallet p("Books", 10, 0);
    REQUIRE(p.isEmpty() == true);
}

TEST_CASE("Test if function isEmpty() for Pallet returns false", "isEmpty()") {
    Pallet p("Books", 10, 1);
    REQUIRE(p.isEmpty() == false);
}
