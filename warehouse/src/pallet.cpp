#include "include/pallet.hpp"


// Pallet constructor
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

// Default Pallet
Pallet::Pallet() : itemName(""), itemCapacity(0), itemCount(0) {}


// Pallet functions
std::string Pallet::getItemName() {
    return itemName;
}

int Pallet::getItemCount() {
    return itemCount;
}

int Pallet::getRemainingSpace() {
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (itemCount == 0) {
        itemName = itemName;
        itemCapacity = itemCapacity;
        return true;
    }   else {
        return false;
    }
}

bool Pallet::takeOne() {
    if (itemCount > 0) {
        itemCount -= 1;
        return true;
    } else {
        return false;
    }
}

bool Pallet::putOne() {
    if (itemCount < itemCapacity) {
        itemCount ++;
        itemCapacity --;
        return true;
    } else {
        return false;
    }
}

bool Pallet::isEmpty() const {
    return itemCount == 0;
}

bool Pallet::isFull() const {
    return itemCount >= itemCapacity;
}
