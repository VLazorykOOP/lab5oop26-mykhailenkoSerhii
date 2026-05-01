#include <iostream>

#include "Lab5Exmaple.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

int main()
{
    std::cout << " Lab #5  !\n";

    std::cout << "Choose what task to activate -" << std::endl;
    std::cout << "Task 1 - Pair -> Fraction inheritence" << std::endl;
    std::cout << "Task 2 - Wheel -> Car -> Truck composition" << std::endl;
    std::cout << "Task 3 - Move, Copy constructors and operators with inheritence" << std::endl;
    std::cout << "Write 0 to stop the execution of this program" << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == 0)
        return 0;

    if (choice == 1)
        task1();
    else if (choice == 2)
        task2();
    else if (choice == 3)
        task3();

    return 0;
}
