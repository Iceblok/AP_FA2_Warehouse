#include "include/warehouse.hpp"
#include <algorithm>
#include <iostream>

// Warehouse constructor
Warehouse::Warehouse() {};


// Warehouse functions
void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {

    bool availableEmployee = false;
    unsigned int index = 0;

    while (!availableEmployee && index < employees.size()) {
        if (!employees[index].getBusy() && employees[index].getForkliftCertificate()) {
            availableEmployee = true;

        } else {
            index++;
        }
    }

    bool shelfSorted = false;
    int lengthOfShelf = sizeof(shelf.pallets) / sizeof(shelf.pallets[0]);


    if (availableEmployee) {
        while (!shelfSorted) {
            shelfSorted = true;
            for (int i = 0; i < lengthOfShelf - 1; i++) {

                if (shelf.pallets[i].getItemCount() > shelf.pallets[i+1].getItemCount()) {
                    shelf.swapPallet(i, i+1);
                    shelfSorted = false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

// bool Warehouse::pickItems(std::string itemName, int itemCount) {
//     Shelves.
// }
