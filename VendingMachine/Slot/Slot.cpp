//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Slot.h"

// Default public init
Slot::Slot() : _snack(new Snack()) , _size(0), _currentPoint(0)
{
}
// public init with dinamic snack array size
Slot::Slot(const int size) : _snack(new Snack[size]), _size(size), _currentPoint(0)
{
}

//public deinit
Slot::~Slot()
{
    delete[] _snack;
}

// Returns the number of free cells in the slot
int Slot::getFreeSpace() const 
{
    return _size - _currentPoint;
}

// Add a snack to the slot cell
void Slot::addSnack(Snack *newSnack)
{
      if (_currentPoint == _size) {
        std::cout << "Слот заполнен полностью\n";
      } else {
        _snack[_currentPoint] = *newSnack;
        _currentPoint++;
      }

    
}

// Removes the last added snow from the slot
void Slot::deleteSnack()
{
    if (_currentPoint == 0) {
        std::cout << "Слот полностью пуст!\n";
    } else {
        Snack empty = Snack();
        _currentPoint--;
        _snack[_currentPoint] = empty;
    }
}

// increase price all snack from slot at pecent
void Slot::icreasePriceByPercent(int percent)
{
    for (int i = 0; i < _size; i++) {
        _snack[i]._price *= 1 + (double(percent) / 100);
    }
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Slot &m)
{
    output << "Slot .....\n" << "Свободное место в слоте: " << m.getFreeSpace() << std::endl 
    << "Количество ячеек в слоте: " << m._size << std::endl << "\nСнеки в слоте:" << std::endl;
            for (int i = 0; i < m._size; i++) {
                output  << m._snack[i] << std::endl;
            }
    return output;
}
