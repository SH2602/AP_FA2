#include"include/warehouse.hpp"
#include"include/shelf.hpp"
#include<iostream>


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
    //true wanneer itemCount van itemName aanwezig zijn verdeeld over alle pallets
    //en dus ook alle shelves.

}