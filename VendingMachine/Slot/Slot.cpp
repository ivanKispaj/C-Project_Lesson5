//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Slot.h"

// Default public init
Slot::Slot()
{
    this->currentPoint = 0;
    this->snack = new Snack();
}
// public init with dinamic snack array size
Slot::Slot(int size)
{
    this->size = size;
    this->currentPoint = 0;
    snack = new Snack[size];
}

//public deinit
Slot::~Slot()
{
    delete[] snack;
}

// Returns the number of free cells in the slot
int Slot::getFreeSpace() const 
{
    return size - (currentPoint);
}

// Add a snack to the slot cell
void Slot::addSnack(Snack *newSnack)
{
      if (currentPoint == size) {
        std::cout << "Слот заполнен полностью\n";
      } else {
        snack[currentPoint] = *newSnack;
        this->currentPoint++;
      }

    
}

// Returns the last added snack from the slot cell,
// with its removal from the slot.
// if the slot is empty, returns a snack with the type: Empty!
void Slot::deleteSnack()
{
    if (this->currentPoint == 0) {
        std::cout << "Слот полностью пуст!\n";
    } else {
        Snack empty = Snack();
        this->currentPoint--;
        this->snack[currentPoint] = empty;
    }
}

// 
void Slot::icreasePriceByPercent(int percent)
{
    for (int i = 0; i < this->size; i++) {
        this->snack[i].price *= 1 + (double(percent) / 100);
    }
}
// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Slot &m)
{
    output << "Slot .....\n" << "Свободное место в слоте: " << m.getFreeSpace() << std::endl 
    << "Количество ячеек в слоте: " << m.size << std::endl << "\nСнеки в слоте:" << std::endl;
            for (int i = 0; i < m.size; i++) {
                output  << m.snack[i] << std::endl;
            }
    return output;
}
