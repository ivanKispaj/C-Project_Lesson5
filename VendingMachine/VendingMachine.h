#pragma once
//
//  VendingMachine.h
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

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
    void addSlot(Slot *newSlot);
    int getFreeSpace() const;
    void icreasePriceByPercent(int percent);
    void icreasePriceByPercent(int percent, int slotNumber);
   friend std::ostream &operator<<(std::ostream &output, const VendingMachine &m );
};