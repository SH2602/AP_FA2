#include"include/shelf.hpp"

Shelf::Shelf()
{}

bool Shelf::swapPallet(int slot, int slot2){
    Pallet pallet = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = pallet;
}

bool Shelf::isEmpty(){
    for (Pallet pallet : pallets){
        if (pallet.getItemCount()>0){   //if itemcount is positive, not empty
            return false;
        }
    }
    return true;
    }

bool Shelf::isFull(){
    for (Pallet pallet : pallets){
        if(pallet.getRemainingSpace()==0){  // no remaining space, is full.
            return true;
        }
    }
    return false;
}