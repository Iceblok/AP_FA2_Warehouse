#include "include/shelf.hpp"
#include <array>
#include <iostream>


// Shelf constructor
Shelf::Shelf() : pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {};


// Shelf functions
bool Shelf::swapPallet(int slot, int slot2) {
    if (pallets[slot].getItemCount() > pallets[slot2].getItemCount()) {
        Pallet temp = pallets[slot];
        pallets[slot] = pallets[slot2];
        pallets[slot2] = temp;
        return true;
    } else {
        return false;
    }
}

bool Shelf::isEmpty() const {
    int numberOfEmptyPallets = 0;

    for (Pallet pallet : pallets) {
        if (pallet.isEmpty()) {
            numberOfEmptyPallets++;
        } else {
            // pass
        }
    }

    return numberOfEmptyPallets == 4;
}

bool Shelf::isFull() const {
    int numberOfFullPallets = 0;

    for (Pallet pallet : pallets) {
        if (pallet.isFull()) {
            numberOfFullPallets++;
        } else {
            // pass
        }
    }

    return numberOfFullPallets == 4;
}

std::ostream &operator<<(std::ostream& os, Shelf& s) {
    for (Pallet& pallet : s.pallets) {
        os << pallet << std::endl;
    }
    return os;
}
