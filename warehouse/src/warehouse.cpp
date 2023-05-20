#include "include/warehouse.hpp"
#include <algorithm>

// Warehouse constructor
Warehouse::Warehouse() {};


// Warehouse functions
void Warehouse::addEmployee(Employee employee) {
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    Shelves.push_back(shelf);
}

// bool Warehouse::rearrangeShelf(Shelf& shelf) {

//     std::sort(std::begin(shelf.pallets), std::end(shelf.pallets), [](Pallet product1, Pallet product2) {
//         return product1.getItemCount() < product2.getItemCount();
//     });
// }

// bool Warehouse::pickItems(std::string itemName, int itemCount) {
//     Shelves.
// }
