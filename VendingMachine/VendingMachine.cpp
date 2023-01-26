//
//  VendingMachine.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "VendingMachine.h"

// init
VendingMachine::VendingMachine(int slotCount) : _slot(new Slot[slotCount]), _size(slotCount), _currentSlot(0)
{
}

// deinit
VendingMachine::~VendingMachine()
{
    delete[] _slot;
}

// Added new slot to vending machine
void VendingMachine::addSlot(Slot *newSlot)
{
    if (_currentSlot < _size) {
        _slot[_currentSlot].~Slot();
        _slot[_currentSlot] = *newSlot;
        _currentSlot++;
    } else {
        std::cout << "Все доступное место под слоты занято!";
    }
}

// get free space
int VendingMachine::getFreeSpace() const
{
    return _size - (_currentSlot - 1);
}

void VendingMachine::icreasePriceByPercent(int percent)
{
    for (int i = 0; i < _size; i++) {
        _slot[i].icreasePriceByPercent(percent);
    }
}
void VendingMachine::icreasePriceByPercent(int percent, int slotNumber) 
{
   _slot[slotNumber].icreasePriceByPercent(percent);
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const VendingMachine &m ) 
{
       output << "Vending machine....\n" << "Slot count: " << m._size << std::endl;
       for (int i = 0; i < m._size; i++)
       {
        output << "Current slot: " << i + 1 << std::endl 
        << m._slot[i] << std::endl;
       }
       return output;
}