//
//  VendingMachine.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "VendingMachine.h"

// init
VendingMachine::VendingMachine(int slotCount) : _slots(new Slot* [slotCount]), _size(slotCount), _currentSlot(0)
{
}

// deinit
VendingMachine::~VendingMachine()
{
    delete[] _slots;
}

// Added new slot to vending machine
void VendingMachine::addSlot(Slot *newSlot)
{
    if (_currentSlot < _size) {
        _slots[_currentSlot] = newSlot;
        _currentSlot++;
    } else {
        std::cout << "There is no free space for slots!";
    }
}

void VendingMachine::deleteSlot()
{
    if (_currentSlot != 0) {
        _currentSlot--;
        _slots[_currentSlot] = nullptr;
    } else {
        std::cout << "Machine is emty! No slots"
    }
}

// get free space
int VendingMachine::getFreeSpace() const
{
    return _size - (_currentSlot);
}

// //Increases the price of all snacks in all slots
void VendingMachine::icreasePriceByPercent(int percent)
{
    for (int i = 0; i < _size; i++) {
        if (_slots[i] != nullptr) {
            
            _slots[i]->icreasePriceByPercent(percent);
            
        }
      
    }
}

// //Increases the price of all snacks in slotNumber
void VendingMachine::icreasePriceByPercent(int percent, int slotNumber) 
{
    if ((slotNumber > 0 && slotNumber <= _size) && _slots[slotNumber - 1] != nullptr) {
        _slots[slotNumber - 1]->icreasePriceByPercent(percent);
    } else {
        std::cout << "Error! Wrong slot number!\n";
    }
   
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const VendingMachine &m ) 
{
       output << "Vending machine....\n" << "Slot count: " << m._size << std::endl;
       for (int i = 0; i < m._size; i++)
       {
        if (m._slots[i] != nullptr) {
            output << "Current slot: " << i + 1 << std::endl 
            << *m._slots[i] << std::endl;
        } else {
            output << "Current slot: " << i + 1 
            << "-> free space!\n";
        }
       
       }
       return output;
}