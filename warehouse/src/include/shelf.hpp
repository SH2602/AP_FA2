#pragma once

#include<iostream>
#include<array>
#include"pallet.hpp"
#include"icontainer.hpp"

class Shelf:public IContainer{
    public:
        std::array<Pallet,4> pallets;

        Shelf();
        /// Swap two pallets where the pallet with smallest itemCount gets placed first.
        bool swapPallet(int slot, int slot2);
        bool isEmpty()override;
        bool isFull()override;
};