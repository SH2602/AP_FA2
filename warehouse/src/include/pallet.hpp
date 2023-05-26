#pragma once
#include<iostream>
#include"icontainer.hpp"

class Pallet:public IContainer{
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;
        
    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
        std::string getItemName();
        int getItemCount();
        /// returns space left on pallet
        int getRemainingSpace();
        /// assigns itemName and itemCapacity to pallet
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        /// takes one item from pallet.
        bool takeOne();
        /// places one item on pallet.
        bool putOne();
        bool isEmpty()override;
        bool isFull()override;
};