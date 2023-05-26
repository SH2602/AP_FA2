#include"include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount):
    itemName(itemName),
    itemCapacity(itemCapacity),
    itemCount(itemCount)
{}


Pallet::Pallet():
    itemName(""),
    itemCapacity(0),
    itemCount(0)
{}

std::string Pallet::getItemName(){
    return this->itemName;
}

int Pallet::getItemCount(){
    return this->itemCount;
}

int Pallet::getRemainingSpace(){
    int remainingSpace = itemCapacity - itemCount;
    if(remainingSpace>0 && remainingSpace< itemCapacity){   // checks if remaining space is valid
        return remainingSpace;
    }
    remainingSpace = 0;
    return remainingSpace;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if(isEmpty()){
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne(){
    if(!isEmpty()){
        this->itemCount -=1;    // takes 1 item from pallet
        return true;
    }
    return false;
}

bool Pallet::putOne(){
    if(!isFull()){
        this->itemCount += 1;   // adds 1 item to pallet
        return true;
    }
    return false;
}

bool Pallet::isEmpty(){
    if(itemCount == 0){
        return true;
    }
    return false;
}

bool Pallet::isFull(){
    if(itemCount == itemCapacity){
        return true;
    }
    return false;
}