#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"


TEST_CASE("Test case if function calculates remaining space on Pallets", "calculateRemainingSpaceOnPallets(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 10, 0), 
        Pallet("Boxes", 10, 10), 
        Pallet("Boxes", 10, 10), 
        Pallet("Boxes", 10, 0)
    };    
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.calculateRemainingSpaceOnPallets("Books") == 10);
    REQUIRE(warehouse.calculateRemainingSpaceOnPallets("Boxes") == 10);
}

TEST_CASE("Test case if function putItems returns true and changes remaining space on Pallet", "putItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 10, 0), 
        Pallet("Books", 10, 10), 
        Pallet("Books", 10, 10), 
        Pallet("Books", 10, 10)
    };    
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.shelves[0].pallets[0].getRemainingSpace() == 10);
    REQUIRE(warehouse.putItems("Books", 10) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getRemainingSpace() == 0);
}

TEST_CASE("Test case if function putItems returns false and itemCount doesn't change from Pallet", "putItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 100), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };    
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 100);
    REQUIRE(warehouse.putItems("Books", 11) == false);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 100);
}

TEST_CASE("Test case if function putItems returns true and fills up the Shelf", "putItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0)
    };    
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.shelves[0].isFull() == false);
    REQUIRE(warehouse.shelves[0].isEmpty() == true);
    REQUIRE(warehouse.putItems("Boxes", 200) == true);
    REQUIRE(warehouse.shelves[0].isEmpty() == false);
    REQUIRE(warehouse.shelves[0].isFull() == true);
}

TEST_CASE("Test case if function putItems works on multiple shelves and pallets", "putItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0), 
        Pallet("Boxes", 50, 0)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    REQUIRE(warehouse.shelves[0].isFull() == false);
    REQUIRE(warehouse.shelves[0].isEmpty() == true);
    REQUIRE(warehouse.shelves[1].isFull() == false);
    REQUIRE(warehouse.shelves[1].isEmpty() == true);

    REQUIRE(warehouse.putItems("Boxes", 400) == true);
    
    REQUIRE(warehouse.shelves[0].isEmpty() == false);
    REQUIRE(warehouse.shelves[0].isFull() == true);
    REQUIRE(warehouse.shelves[1].isEmpty() == false);
    REQUIRE(warehouse.shelves[1].isFull() == true);
}
