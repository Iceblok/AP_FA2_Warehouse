#pragma once
#include <string>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"


class Warehouse {

    public:

        // Warehouse variables
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;

        // Warehouse constructor
        Warehouse();
        
        // Warehouse functions
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, int itemCount);
        bool putItems(std::string itemName, int itemCount);
        int calculateAvailableItems(std::string itemName);
        int calculateRemainingSpaceOnPallets(std::string itemName);
        
};
