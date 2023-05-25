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
    for (Employee& employee : Employees){
        if (employee.getBusy()==false && employee.getForkliftCertificate()==true){
            //employee.setBusy(true);
            for(int i =0; i<shelf.pallets.size()-1; i+=1){
                if(shelf.pallets[i].getItemCount()>shelf.pallets[i+1].getItemCount()){
                    shelf.swapPallet(i, i+1);
                }
            }
        }
        return true;
    }
    return false;
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