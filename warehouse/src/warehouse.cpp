#include"include/warehouse.hpp"
#include"include/shelf.hpp"
#include"include/pallet.hpp"
#include<iostream>
#include<algorithm>

Warehouse::Warehouse(){}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    //check if employee busy(false) and forkliftCertified(true)
    for (Employee& employee : Employees){
        if (employee.getBusy()==false && employee.getForkliftCertificate()==true){
            employee.setBusy(true);
            
            }
    }
    //sorteer de pallets oplopen op volgorde van itemCount
    //swapPallet om pallets te verwisselen
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    int remainingItems = itemCount;
    for (Shelf& shelf : Shelves){
        for (Pallet& pallet : shelf.pallets){
            if (pallet.getItemName()== itemName){
                while (remainingItems > 0 && pallet.isEmpty()==false){
                    if(pallet.takeOne()){
                        remainingItems-=1;
                    }
                }
            }
        if (remainingItems== 0 ){
            return true;
            }
        }
    }
    return false;
}