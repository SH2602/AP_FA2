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
    if(remainingSpace>0 && remainingSpace< itemCapacity){
        return remainingSpace;
    }
    std::cout<<"There is no space left on the pallet."<<std::endl;
    remainingSpace = 0;
    return remainingSpace;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
//snap zo gauw niet wat deze moet doen...
}

bool Pallet::takeOne(){
    if(isEmpty == false){
        this->itemCount -=1;
        return true;
    }
    return false;
}

bool Pallet::putOne(){
    if(isFull==false){
        this->itemCount += 1;
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