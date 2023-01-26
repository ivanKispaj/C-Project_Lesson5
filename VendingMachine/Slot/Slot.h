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
    short int currentPoint; 
    Snack *snack; // dinamic snack array
    int size; // array size

    //init
    public:
    Slot();
    Slot(int size);
    ~Slot();

    // public Methods
    public:
    int getFreeSpace() const;
    void addSnack(Snack *newSnack);
    void deleteSnack();
    void icreasePriceByPercent(int percent);
    friend std::ostream &operator<<(std::ostream &output, const Slot &m);
};