//
//  VendingMachine.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "VendingMachine.h"

// init
VendingMachine::VendingMachine(int slotCount)
{
    slot = new Slot[slotCount];
    this->slotCount = slotCount;
    this->currentSlot = 0;
}

// deinit
VendingMachine::~VendingMachine()
{
    delete[] slot;
}

// Added new slot to vending machine
void VendingMachine::addSlot(Slot *newSlot)
{
    if (currentSlot < slotCount) {
        this->slot[currentSlot].~Slot();
        this->slot[currentSlot] = *newSlot;
        this->currentSlot++;
    } else {
        std::cout << "Все доступное место под слоты занято!";
    }
}

// get free space
int VendingMachine::getFreeSpace() const
{
    return slotCount - (currentSlot - 1);
}

void VendingMachine::icreasePriceByPercent(int percent)
{
    for (int i = 0; i < this->slotCount; i++) {
        this->slot[i].icreasePriceByPercent(percent);
    }
}
void VendingMachine::icreasePriceByPercent(int percent, int slotNumber) 
{
   this->slot[slotNumber].icreasePriceByPercent(percent);
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const VendingMachine &m ) 
{
       output << "Vending machine....\n" << "Slot count: " << m.slotCount << std::endl;
       for (int i = 0; i < m.slotCount; i++)
       {
        output << "Current slot: " << i + 1 << std::endl 
        << m.slot[i] << std::endl;
       }
       return output;
}