#pragma once
#include <string>

class Pallet {

    private:

        // Pallet variables
        std::string itemName;
        int itemCapacity;
        int itemCount;

    public:

        // Pallet constructor
        Pallet(std::string itemName, int itemCapacity, int itemCount);

        // Default Pallet
        Pallet();

        // Pallet functions
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        
};