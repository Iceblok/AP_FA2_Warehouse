#pragma once
#include <string>
#include <array>
#include "pallet.hpp"

class Shelf {

    public:

        // Shelf variables
        std::array<Pallet, 4> pallets;

        // Shelf constructor
        Shelf();
        
        // Shelf functions
        bool swapPallet(int slot, int slot2);
        
};
