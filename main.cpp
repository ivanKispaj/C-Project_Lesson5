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
  
    Snack *snikers = new Snack("Snikers", 80); // Создание снека динамически
    Snack *bounty = new Snack("Bounty",45.5); // Создание снека динамически
    Snack *twix = new Snack("Twix", 60.3); // Создание снека динамически
    Slot *slot1 = new Slot(10); // Создание слота динамически
    VendingMachine *machine = new VendingMachine(5); // Create VendingMachine with 5 slots
    Slot *slot2 = new Slot(15);

    // Added snacks to slot2
    slot2->addSnack(twix);
    slot2->addSnack(bounty); 
    slot2->addSnack(snikers);
    slot2->addSnack(bounty);
    slot2->addSnack(snikers);
    slot2->addSnack(bounty); 
    slot2->addSnack(twix);
    slot2->addSnack(bounty); 
    slot2->addSnack(snikers); 
    slot2->addSnack(bounty); 
    slot2->deleteSnack();
     // Added snacks to slot1
    slot1->addSnack(snikers);
    slot1->addSnack(twix);
    slot1->addSnack(bounty); 
    slot1->addSnack(snikers); 
    std::cout << "Свободное место в слоте 1: " << slot1->getFreeSpace() << std::endl; // вывод свободного места в слоте
    std::cout << "Свободное место в слоте 2: " << slot2->getFreeSpace() << std::endl << std::endl; // вывод свободного места в слоте
    machine->addSlot(slot1);
    machine->addSlot(slot2);
    machine->icreasePriceByPercent(20, 1);
    std::cout << *machine << std::endl; 
    std::cout << "Deleting snikers\n";
    delete snikers; // удаление динамической переменной
    std::cout << "Deleting bounty\n";
    delete bounty; // удаление динамической переменной 
    std::cout << "Deleting twix\n";
    delete twix;  // удаление динамической переменной
     std::cout << "Deleting slot 1\n";
    delete slot1; // удаление динамической переменной
     std::cout << "Deleting slot 2\n";
    delete slot2;
    std::cout << "Deleting mashine\n";
    delete machine;  // удаление динамической переменной
    return 0; // завершение программы
}