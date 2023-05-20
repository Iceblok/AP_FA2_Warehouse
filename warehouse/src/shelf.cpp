#include "include/shelf.hpp"
#include <array>


// Shelf constructor
Shelf::Shelf() :  pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {};


// Shelf functions
bool Shelf::swapPallet(int slot, int slot2) {
    if (pallets[slot].getItemCount() > pallets[slot2].getItemCount()) {
        Pallet temp = pallets[slot];
        pallets[slot] = pallets[slot2];
        pallets[slot2] = temp;
        return true;
    }   else {
        return false;
    }
}
