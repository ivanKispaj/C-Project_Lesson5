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
    Snack *snack; // dinamic snack array
    int size; // array size

    //init
    public:
    Slot() = default;
    Slot(int size);
    ~Slot();

    // public Methods
    public:
    int getFreeSpace() const;
    void addSnack(Snack *snack);
    Snack getSnake();
    friend std::ostream &operator<<(std::ostream &output, const Slot &m);
};
