#include "include/catch.hpp"
#include "../src/include/shelf.hpp"


TEST_CASE("Test case for default Shelf. Check if shelf has 4 empty (default) pallets", "default Shelf") {
    Shelf s;
    REQUIRE(s.pallets[3].getItemName() == "");
    REQUIRE(s.pallets[3].getItemCount() == 0);
    REQUIRE(s.pallets[3].getRemainingSpace() == 0);

    REQUIRE(s.pallets[3].getItemName() == "");
    REQUIRE(s.pallets[3].getItemCount() == 0);
    REQUIRE(s.pallets[3].getRemainingSpace() == 0);

    REQUIRE(s.pallets[3].getItemName() == "");
    REQUIRE(s.pallets[3].getItemCount() == 0);
    REQUIRE(s.pallets[3].getRemainingSpace() == 0);

    REQUIRE(s.pallets[3].getItemName() == "");
    REQUIRE(s.pallets[3].getItemCount() == 0);
    REQUIRE(s.pallets[3].getRemainingSpace() == 0);
}

TEST_CASE("Test case function swapPallet() returns true", "swapPallet()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 2), 
        Pallet("Books", 10, 1), 
        Pallet("Books", 10, 6), 
        Pallet("Books", 10, 8)
    };

    REQUIRE(s.swapPallet(0, 1) == true);
    REQUIRE(s.pallets[0].getItemCount() == 1);
    REQUIRE(s.pallets[1].getItemCount() == 2);
}

TEST_CASE("Test case function swapPallet() returns false", "swapPallet()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 2), 
        Pallet("Books", 10, 1), 
        Pallet("Books", 10, 6), 
        Pallet("Books", 10, 8)
    };

    REQUIRE(s.swapPallet(2, 3) == false);
    REQUIRE(s.pallets[2].getItemCount() == 6);
    REQUIRE(s.pallets[3].getItemCount() == 8);
}

TEST_CASE("Test if function isFull() for Shelf returns true", "isFull()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 10), 
        Pallet("Books", 10, 10), 
        Pallet("Books", 10, 10), 
        Pallet("Books", 10, 10)
    };
    REQUIRE(s.isFull() == true);
}

TEST_CASE("Test if function isFull() for Shelf returns false", "isFull()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 2), 
        Pallet("Books", 10, 1), 
        Pallet("Books", 10, 6), 
        Pallet("Books", 10, 8)
    };
    REQUIRE(s.isFull() == false);
}

TEST_CASE("Test if function isEmpty() for Shelf returns true", "isEmpty()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 0), 
        Pallet("Books", 10, 0), 
        Pallet("Books", 10, 0), 
        Pallet("Books", 10, 0)
    };
    REQUIRE(s.isEmpty() == true);
}

TEST_CASE("Test if function isEmpty() for Shelf returns false", "isEmpty()") {
    Shelf s;
    s.pallets = {
        Pallet("Books", 10, 2), 
        Pallet("Books", 10, 1), 
        Pallet("Books", 10, 6), 
        Pallet("Books", 10, 8)
    };
    REQUIRE(s.isEmpty() == false);
}
