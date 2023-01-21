
#pragma once
#include "Slot/Slot.h"

struct VendingMachine
{
    private:
    short int slotCount;
    short int currentSlot;
    Slot *slot; // dinamic array

    public:
    VendingMachine(int slotCount); // init
    ~VendingMachine(); // deinit
    void addSlot(Slot *slot);
    int getFreeSpace();
   friend std::ostream &operator<<(std::ostream &output, const VendingMachine &m );
};
