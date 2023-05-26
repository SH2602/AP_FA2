#include <iostream>
#include"src/include/Employee.hpp"
#include"src/include/Pallet.hpp"
#include"src/include/Shelf.hpp"
#include"src/include/Warehouse.hpp"
// #include"test/testWarehouse.cpp"

int main(){
    //cfeate empty warehouse
    Warehouse warehouse = Warehouse();

    //create 3 employees
    Employee employee1 = Employee("Henk", true);
    Employee employee2 = Employee("Sander", false);
    Employee employee3 = Employee("Bianca", true);

    //create 3 shelves
    //one half-full shelf
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Books", 100, 55),
        Pallet(),
        Pallet()
    };

    //one full shelf
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 20),
        Pallet("TV's", 100, 40),
        Pallet("Cups", 100, 55),
        Pallet("Books", 100, 10)
    };

    //one empty shelf
    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet(),
        Pallet(),
        Pallet(),
        Pallet()
    };


    //add employees to the empty warehouse.
    warehouse.addEmployee(employee1);
    warehouse.addEmployee(employee2);
    warehouse.addEmployee(employee3);
    std::cout<<"added three employees: "<<employee1.getName()<<", "<<employee2.getName()<<", "<<employee3.getName()<<std::endl;

    //add shelves to the empty warehouse.
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);
    std::cout<<"Added three shelves!"<<std::endl;

    // rearrange shelf 2.
    warehouse.rearrangeShelf(shelf2);
    std::cout<<"Rearranged shelf 2!"<<std::endl;

    //pick items from books over multiple shelves.
    warehouse.pickItems("Books", 100);
    std::cout<<"picked 100 books from multiple shelves!"<<std::endl;
    return 0;
}
