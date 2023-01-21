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
  
    Snack snikers1 = Snack("Mars"); // Создание снека на стеке ( удалится по завершении main())
    Snack *snikers = new Snack("Snikers"); // Создание снека динамически
    Snack *bounty = new Snack("Bounty"); // Создание снека динамически
    Snack *twix = new Snack("Twix"); // Создание снека динамически
    Slot *slot = new Slot(10); // Создание слота динамически
    VendingMachine *mashine = new VendingMachine(5);
  
    slot->addSnack(twix);
    slot->addSnack(bounty); // добавляем динамический snack
    slot->addSnack(snikers); // добавляем динамический snack
    std::cout << "Свободное место в слоте: " << slot->getFreeSpace() << std::endl; // вывод свободного места в слоте
    slot->addSnack(&snikers1); // добавлен в слот snack из стека
    snikers1 = Snack("Trash"); // меняем значение переменной из стека
    slot->addSnack(&snikers1); // добавлен в слот snack из стека
     std::cout << "Свободное место в слоте: " << slot->getFreeSpace() << std::endl;  // вывод свободного места в слоте
    std::cout << slot->getSnake() << std::endl; // Получение снека из слота с удалением его из него
    mashine->addSlot(slot);
    std::cout << *mashine << std::endl;
    std::cout << *slot << std::endl;
    delete snikers; // удаление динамической переменной
    delete bounty; // удаление динамической переменной
    delete slot; // удаление динамической переменной
    delete twix;  // удаление динамической переменной
    delete mashine;  // удаление динамической переменной
    
    return 0; // завершение программы
}