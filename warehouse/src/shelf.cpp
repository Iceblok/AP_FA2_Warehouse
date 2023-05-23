#include "include/shelf.hpp"
#include <array>


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
