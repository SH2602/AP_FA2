#pragma once

#include<iostream>
#include<array>
#include "include/pallet.hpp"
#include"include/icontainer.hpp"

class Shelf:public IContainer{
    public:
        std::array<Pallet,4> pallets;

        Shelf();
        std::array<bool, 4> getSlotStatus();
        bool removePallet(int slot);
        bool insertPallet(int slot, Pallet pallet);
        bool isEmpty()override;
        bool isFull()override;
};