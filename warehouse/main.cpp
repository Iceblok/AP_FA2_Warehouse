#include <iostream>
#include "src/include/employee.hpp"
#include "src/include/pallet.hpp"
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"


int main(void) {
    std::cout << "Hello world" << std::endl;
    
    Warehouse warehouse = Warehouse();

    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10), 
        Pallet("Boxes", 100, 0), 
        Pallet("Boxes", 100, 0), 
        Pallet("Boxes", 100, 100)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 0), 
        Pallet("Boxes", 100, 0), 
        Pallet("Boxes", 100, 100)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    warehouse.addEmployee(Employee("Yunus", true));


    for (Shelf shelf : warehouse.shelves) {
        for (Pallet pallet : shelf.pallets) {
            std::cout << pallet.getItemCount() << std::endl;
        }
    }

    if (warehouse.pickItems("Books", 15)) {
        std::cout << "done" << std::endl;
    } else {
        std::cout << "not done" << std::endl;
    }


    for (Shelf shelf : warehouse.shelves) {
        for (Pallet pallet : shelf.pallets) {
            std::cout << pallet.getItemCount() << std::endl;
        }
    }

}
