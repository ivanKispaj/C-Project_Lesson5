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
    Slot *_slot; // dinamic array
    short int _size; // count size in machine
    short int _currentSlot; // current empty slot
  

    public:
    VendingMachine() = default; // default init
    VendingMachine(int slotCount); // init
    ~VendingMachine(); // deinit
    void addSlot(Slot *newSlot); // added slot to machine
    int getFreeSpace() const; // return free space in machine
    void icreasePriceByPercent(int percent); // Increases the price of all snacks in all slots
    void icreasePriceByPercent(int percent, int slotNumber); //Increases the price of all snacks in slotNumber
   friend std::ostream &operator<<(std::ostream &output, const VendingMachine &m ); //
};