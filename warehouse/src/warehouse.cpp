#include "include/warehouse.hpp"
#include <algorithm>
#include <iostream>

// Warehouse constructor
Warehouse::Warehouse() : employees({}), shelves({}) {}


// Warehouse functions
void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::getAvailableEmployee() {
    bool availableEmployee = false;
    unsigned int index = 0;

    while (!availableEmployee && index < employees.size()) {
        if (!employees[index].getBusy() && employees[index].getForkliftCertificate()) {
            availableEmployee = true;

        } else {
            index++;
        }
    }
    return availableEmployee;
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    bool availableEmployee = getAvailableEmployee();
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

int Warehouse::calculateAvailableItems(std::string itemName) {
    int availableItems = 0;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                availableItems += pallet.getItemCount();
            }            
        }
    }

    return availableItems;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int availableItems = calculateAvailableItems(itemName);

    if (availableItems < itemCount) {
        return false;
    } else if (availableItems >= itemCount) {
        int pickedItems = 0;
        
        for (Shelf& shelf : shelves) {
            for (Pallet& pallet : shelf.pallets) {
                if (itemName == pallet.getItemName()) {
                    const int end = pallet.getItemCount();
                    for (int i=0; i < end; i++) {
                        if (pickedItems == itemCount) {
                            return true;
                        } else if (pallet.takeOne()) {
                            pickedItems++;
                        }
                    }  
                }
            }
        }
    }
    return true;
}

int Warehouse::calculateRemainingSpaceOnPallets(std::string itemName) {
    int spaceAvailableOnPallets = 0;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                spaceAvailableOnPallets += pallet.getRemainingSpace();
            }            
        }
    }

    return spaceAvailableOnPallets;
}

bool Warehouse::putItems(std::string itemName, int itemCount) {
    int remainingSpaceOnPallets = calculateRemainingSpaceOnPallets(itemName);

    if (remainingSpaceOnPallets < itemCount) {
        return false;
    } else if (remainingSpaceOnPallets >= itemCount) {
        int placedItems = 0;

        for (Shelf& shelf : shelves) {
            for (Pallet& pallet : shelf.pallets) {
                if (itemName == pallet.getItemName()) {
                    const int end = pallet.getRemainingSpace();
                    for (int i=0; i < end; i++) {
                        if (placedItems == itemCount) {
                            return true;
                        } else if (pallet.putOne()) {
                            placedItems++;
                        }
                    }  
                }
            }
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream& os, Warehouse& w) {
    os << "Employees: " << std::endl;
    for (Employee& employee : w.employees) {
        os << employee << std::endl;
    }

    os << std::endl << "Shelves: " << std::endl;
    for (Shelf& shelf : w.shelves) {
        os << shelf << std::endl;
    }

    return os;
}
