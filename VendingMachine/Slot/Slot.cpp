//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Slot.h"

// public init with dinamic snack array size
Slot::Slot(const int size) : _snacks(new Snack *[size]), _size(size), _currentPoint(0)
{
}

// public deinit
Slot::~Slot()
{
  delete[] _snacks;
}

// Returns the number of free cells in the slot
int Slot::getFreeSpace() const
{
  return _size - _currentPoint;
}

// Add a snack to the slot cell
void Slot::addSnack(Snack *newSnack)
{
  if (_currentPoint == _size)
  {
    std::cout << "Слот заполнен полностью\n";
  }
  else
  {
    _snacks[_currentPoint] = newSnack;
    _currentPoint++;
  }
}

// Removes the last added snow from the slot
void Slot::deleteSnack()
{
  if (_currentPoint == 0)
  {
    std::cout << "Слот полностью пуст!\n";
  }
  else
  {
    _currentPoint--;
    _snacks[_currentPoint] = nullptr;
  }
}

// increase price all snack from slot at pecent
void Slot::icreasePriceByPercent(int percent)
{
  for (int i = 0; i < _size; i++)
  {
    if (_snacks[i] != nullptr)
    {
      double newPrice = (_snacks[i]->getPrice() * (1 + (double(percent) / 100)));
      _snacks[i]->setPrice(newPrice);
    }
  }
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Slot &m)
{
  output << "\nSlot .....\n"
         << "Свободное место в слоте: " << m.getFreeSpace() << std::endl
         << "Количество ячеек в слоте: " << m._size << std::endl
         << "Снеки в слоте: " << std::endl;
  for (int i = 0; i < m._size; i++)
  {
    if (m._snacks[i] != nullptr)
    {
      output << *m._snacks[i] << std::endl;
    }
    else
    {
      output << "Free space\n";
    }
  }
  return output;
}
