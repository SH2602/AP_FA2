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
    for (Employee& employee : Employees){   // check in list of employee if:
        if (employee.getBusy()==false && employee.getForkliftCertificate()==true){  //check if employee is available and forkliftcertified
            for(int i =0; i<shelf.pallets.size()-1; ++i){   //loop through shelves
                for (int j = 0;  j< shelf.pallets.size()-i-1; ++j){ //loop through pallets on shelf
                    Pallet& pallet1 = shelf.pallets[j];
                    Pallet& pallet2 = shelf.pallets[j+1];
                    if(pallet1.getItemCount() > pallet2.getItemCount()){    // if second pallet has higher itemcount, swap pallets
                        shelf.swapPallet(j, j+1);
                    }
                }
            }
            employee.setBusy(true); // while swapping pallets, chosen emoloyee is busy
            return true;
        }        
    }
    return false;
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    int itemAmount = 0;
    for (Shelf& shelf : Shelves){
        for(Pallet& pallet : shelf.pallets){
            if (pallet.getItemName() == itemName){  //check for right itemname
                itemAmount += pallet.getItemCount();    // check how many items are available on shelves
            }
        }
    }

    if(itemAmount >= itemCount){    //if available itemscount is higher or equal to required items:
        int remainingItems = itemCount;
        for (Shelf& shelf : Shelves){
            for (Pallet& pallet : shelf.pallets){
                if (pallet.getItemName()== itemName){
                    while (remainingItems > 0 && pallet.isEmpty()==false){
                        if(pallet.takeOne()){   // take one item from pallet
                            remainingItems-=1;  //update remainingItems by -1
                        }
                    }
                }
            if (remainingItems== 0 ){   // loop until remainingItems == 0, no more needed.
                return true;
                }
            }
        }
    
    return false;
    }
}