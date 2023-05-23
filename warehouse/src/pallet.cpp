#include "include/pallet.hpp"


// Pallet constructor
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {
    if (itemCount > itemCapacity) {
        std::__throw_invalid_argument("You are loading the pallet with too many items for its capacity.");
    }
}

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
    if (isEmpty()) {
        itemName = itemName;
        itemCapacity = itemCapacity;
        return true;
    }   else {
        return false;
    }
}

bool Pallet::takeOne() {
    if (itemCount > 0) {
        itemCount --;
        return true;
    } else {
        return false;
    }
}

bool Pallet::putOne() {
    if (itemCount < itemCapacity) {
        itemCount ++;
        return true;
    } else {
        return false;
    }
}

bool Pallet::isEmpty() const {
    return itemCount == 0;
}

bool Pallet::isFull() const {
    return itemCount == itemCapacity;
}
