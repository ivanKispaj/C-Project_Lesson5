//
//  Slot.h
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#pragma once
#include "../Snack/Snack.h"

struct Slot
{
    private:
    short int freeSpace;
    Snack *snack;
    int size;

    //init
    public:
    Slot(int size);
    // public Methods
    public:
    int getFreeSpace() const;
    void addSnack(Snack snack);
    void printSlot();
    SnackType getSnake() const;
};
