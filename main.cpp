//
//  main.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include <iostream>
#include "VendingMachine/Slot/Slot.h"
#include "VendingMachine/VendingMachine.h"

int main(int argc, const char *argv[])
{

    setlocale(LC_ALL, "");
    // Create snack
    Snack *snikers = new Snack("Snikers", 80);
    Snack *bounty = new Snack("Bounty", 76.5);
    Snack *twix = new Snack("Twix", 110);
    // Create Slots
    Slot *slot = new Slot(10); // Создание слота динамически
    Slot *slot_1 = new Slot(5);
    // added snack in to slots
    slot_1->addSnack(twix);
    slot->addSnack(snikers);
    slot->addSnack(bounty);
    // Create VendingMachine with 5 slots
    VendingMachine *machine = new VendingMachine(5); 
    // Print free space in slot
    std::cout << "Свободное место в слоте 1: " << slot->getFreeSpace() << std::endl;
    // Added slots to machine
    machine->addSlot(slot);
    machine->addSlot(slot_1);
    // Print machine
    std::cout << *machine << std::endl;
    // increase price by 30 percent in first slot
    machine->icreasePriceByPercent(30, 1);
    // Print machine
    std::cout << *machine << std::endl;
    // Removing the snack from the slot
    slot->deleteSnack();
    // Print machine
    std::cout << *machine << std::endl;
    // Print free space in machine
    std::cout << "Free space machine: " << machine->getFreeSpace() << std::endl;
    // Freeing up memory
    std::cout << "Deleting mashine\n";
    delete machine; // удаление динамической переменной
    std::cout << "Deleting slot\n";
    delete slot;
    delete slot_1;
    std::cout << "Deleting snack\n";
    delete snikers;
    delete bounty;
    delete twix;
    return 0; // завершение программы
}