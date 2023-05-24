#pragma once
#include <string>
#include "icontainer.hpp"


class Pallet : public IContainer {

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
        bool isEmpty() const override;
        bool isFull() const override;
        friend std::ostream &operator<<(std::ostream& os, Pallet& p);
        
};
