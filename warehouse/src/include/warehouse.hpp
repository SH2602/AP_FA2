#pragma once

#include<iostream>
#include<vector>

#include"employee.hpp"
#include"shelf.hpp"


class Warehouse{
    public:
        std::vector<Employee> Employees;
        std::vector<Shelf> Shelves;

        Warehouse();
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        /// Sort pallets on shelf fromm low to high based on itemCount.
        bool rearrangeShelf(Shelf& shelf);
        /// Take items from shelf.
        bool pickItems(std::string itemName, int itemCount);
};