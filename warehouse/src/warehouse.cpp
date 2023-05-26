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
            for(int i =0; i<shelf.pallets.size()-1; ++i){
                for (int j = 0;  j< shelf.pallets.size()-i-1; ++j){
                    Pallet& pallet1 = shelf.pallets[j];
                    Pallet& pallet2 = shelf.pallets[j+1];
                    if(pallet1.getItemCount() > pallet2.getItemCount()){
                        shelf.swapPallet(j, j+1);
                    }
                }
            }
            employee.setBusy(true);
            return true;
        }        
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