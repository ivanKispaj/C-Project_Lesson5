//
//  main.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include <iostream>
#include "VendingMachine/Slot/Slot.h"

int main(int argc, const char * argv[]) {
  
    Snack snack;
    Slot slot = Slot(10);
    snack = Snikers;
    slot.getSnake() == Empty? std::cout << "Пустой слот\n" : std::cout << "Error not Empty\n";
    slot.addSnack(snack); //
    snack = Snack(Twix);
    slot.addSnack(snack); //
    slot.getSnake() == Twix ? std::cout << "Twix\n" : std::cout << "Error not Bounty\n";
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    slot.addSnack(snack);
    std::cout << slot.getSnake() << std::endl;
    
    std::cout << "Свободно: " << slot.getFreeSpace() << " ячеек\n";
    std::cout << "Содержимое ячеек:\n";
    slot.printSlot();
    return 0;
}