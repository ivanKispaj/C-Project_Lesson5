//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Slot.h"
#include "../Snack/Snack.h"
#include <iostream>

// public init with dinamic snack array size
Slot::Slot(int size)
{
    this->size = size;
    this->freeSpace = size;
    snack = new Snack[size];
}


//public deinit
Slot::~Slot()
{
   if (!this->isLastObject) {
    // если это не последний объект
            delete[] snack;
   } 
    
  
     std::cout << "Deleting a slot in the destructor : Slot\n" << std::endl;
}

//  Sets selectobject to truefor the subsequent deletion of the object in main
void Slot::deleteLast()
{
    this->isLastObject = true;
}

// Returns the number of free cells in the slot
int Slot::getFreeSpace() const 
{
    return freeSpace;
}

// Add a snack to the slot cell
void Slot::addSnack(Snack *snack)
{
    if (this->freeSpace > 0) {
        if ((snack->getSnackName()) != "" ) {
            this->snack[this->freeSpace - 1] = *snack;
            this->freeSpace--;  
        } 
    
    } else {
        std::cout << "Все слоты заняты\n";
    }
    
}

// Returns the last added snack from the slot cell,
// with its removal from the slot.
// if the slot is empty, returns a snack with the type: Empty!
Snack Slot::getSnake()
{
    if (freeSpace == size) {
        return Snack("");
    } else {
        this->freeSpace++;
        Snack snack = Snack("");
        Snack returnSnake = this->snack[this->freeSpace - 1];
        this->snack[this->freeSpace - 1] = snack;
        std::cout << returnSnake << " удален\n";
        return returnSnake;
    }
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Slot &m)
{
    output << "Slot .....\n" << "Свободное место в слоте: " << m.freeSpace << std::endl
            << "Количество ячеек в слоте: " << m.size << std::endl
            << "\nСнеки в слоте:" << std::endl;
            for (int i = m.size - 1; i > m.freeSpace - 1; i--) {
                output  << m.snack[i];
            }
    return output;
}

