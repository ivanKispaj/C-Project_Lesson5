//
//  main.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include <iostream>
#include "VendingMachine/Slot/Slot.h"
#include "VendingMachine/VendingMachine.h"


int main(int argc, const char * argv[]) {

    setlocale(LC_ALL, ""); 
    Snack *snikers = new Snack("Snikers", 80) ;
    Snack *bounty = new Snack("Bounty", 76.5);
    Snack *twix = new Snack("Twix", 110);
    Slot *slot = new Slot(10); // Создание слота динамически
    Slot *slot_1 = new Slot(5);
    slot_1->addSnack(twix);

    slot->addSnack(snikers);
    slot->addSnack(bounty);
    VendingMachine *machine = new VendingMachine(5); // Create VendingMachine with 5 slots
    std::cout << "Свободное место в слоте 1: " << slot->getFreeSpace() << std::endl; // вывод свободного места в слоте

    machine->addSlot(slot); 
    machine->addSlot(slot_1);
    
    std::cout << *machine << std::endl; 
    machine->icreasePriceByPercent(30, 1);
    std::cout << *machine << std::endl; 
    slot->deleteSnack();
    std::cout << *machine << std::endl; 
    std::cout << "Free space machine: " << machine->getFreeSpace() << std::endl;

    std::cout << "Deleting mashine\n";
    delete machine;  // удаление динамической переменной
    std::cout << "Deleting slot\n";
    delete slot;
    delete slot_1;
    std::cout << "Deleting snack\n";
    delete snikers;
    delete bounty;
    delete twix;
    return 0; // завершение программы
}