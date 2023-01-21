
#include "VendingMachine.h"
#include <iostream>

// init
VendingMachine::VendingMachine(int slotCount)
{
    this->slot = new Slot[slotCount];
    this->slotCount = slotCount;
    this->currentSlot = 0;
}

// deinit
VendingMachine::~VendingMachine()
{
    delete[] slot;
}

// Added new slot to vending machine
void VendingMachine::addSlot(Slot *slot)
{
    if (currentSlot != slotCount) {
        this->slot[currentSlot] = *slot;
        this->currentSlot++;
    } else {
        std::cout << "Все доступное место под слоты занято!";
    }
   
}

// get free space
int VendingMachine::getFreeSpace()
{
    return slotCount - currentSlot;
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const VendingMachine &m ) 
{
       output << "Vending machine....\n" << "Slot count: " << m.slotCount << std::endl
            << "Current slot: " << m.currentSlot << std::endl 
            << "Free space from slot: "  << m.slotCount - m.currentSlot << std::endl;       
       return output;
}