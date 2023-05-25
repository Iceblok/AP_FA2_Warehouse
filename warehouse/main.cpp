#include <iostream>
#include "src/include/employee.hpp"
#include "src/include/pallet.hpp"
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"


int main(void) {
    std::cout << "Welcome to our warehouse!" << std::endl;
    
    // Showcasing that our warehouse is empty
    Warehouse warehouse;
    std::cout << warehouse << std::endl;

    // Filling up our warehouse
    Pallet p("Books", 100, 100);
    std::cout << "Showcase of our first pallet:" << std::endl << p << std::endl;
    std::cout << std::endl;

    Pallet p1("Books", 100, 0);
    Pallet p2("Boxes", 50, 50);
    Pallet p3("Boxes", 50, 0);

    Shelf s;
    s.pallets = {p, p1, p2, p3};
    std::cout << "Showcase of our first shelf:" << std::endl << s << std::endl;

    Pallet p4("Books", 100, 100);
    Pallet p5("Books", 100, 0);
    Pallet p6("Boxes", 50, 50);
    Pallet p7("Boxes", 50, 0);

    Shelf s1;
    s1.pallets = {p4, p5, p6, p7};

    Employee e("David", true);
    std::cout << "Showcase of our first employee:" << std::endl;
    std::cout << e << std::endl;
    std::cout << std::endl;

    warehouse.shelves.push_back(s);
    warehouse.shelves.push_back(s1);
    warehouse.employees.push_back(e);

    // Showing results
    std::cout << "Showcasing that our warehouse is filled up" << std::endl;
    std::cout << warehouse;

    if (warehouse.pickItems("Books", 200)) {
        std::cout << "All 200 Books are picked up" << std::endl;
    } else {
        std::cout << "Picking up all 200 Books failed" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Showcasing that all pallets with Book are now empty" << std::endl;
    std::cout << warehouse;

    if (warehouse.putItems("Books", 400)) {
        std::cout << "All 400 Books are put on pallets" << std::endl;
    } else {
        std::cout << "Putting all 400 Books on pallets failed" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Showcasing that all pallets with Book are now full" << std::endl;
    std::cout << warehouse;

}
