#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"

TEST_CASE("Test case if function calculates available items", "calculateAvailableItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };    
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.calculateAvailableItems("Books") == 10);
    REQUIRE(warehouse.calculateAvailableItems("Boxes") == 150);
}

TEST_CASE("Test case if function pickItems returns true and changes the itemCount from Pallet", "pickItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };    
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(Employee("David", true));

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.pickItems("Books", 10) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
}

TEST_CASE("Test case if function pickItems returns false and itemCount doesn't change from Pallet", "pickItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };    
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(Employee("David", true));

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.pickItems("Books", 11) == false);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
}

TEST_CASE("Test case if function pickItems returns true and empties the Shelf", "pickItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };    
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(Employee("David", true));

    REQUIRE(warehouse.shelves[0].isFull() == true);
    REQUIRE(warehouse.shelves[0].isEmpty() == false);
    REQUIRE(warehouse.pickItems("Boxes", 200) == true);
    REQUIRE(warehouse.shelves[0].isEmpty() == true);
    REQUIRE(warehouse.shelves[0].isFull() == false);
}

TEST_CASE("", "pickItems(), from warehouse") {
    Warehouse warehouse;

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50), 
        Pallet("Boxes", 50, 50)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    REQUIRE(warehouse.shelves[0].isFull() == true);
    REQUIRE(warehouse.shelves[0].isEmpty() == false);
    REQUIRE(warehouse.shelves[1].isFull() == true);
    REQUIRE(warehouse.shelves[1].isEmpty() == false);

    warehouse.addEmployee(Employee("Rianne", true));
    REQUIRE(warehouse.pickItems("Boxes", 400) == true);

    REQUIRE(warehouse.shelves[0].isEmpty() == true);
    REQUIRE(warehouse.shelves[0].isFull() == false);
    REQUIRE(warehouse.shelves[1].isEmpty() == true);
    REQUIRE(warehouse.shelves[1].isFull() == false);
}
