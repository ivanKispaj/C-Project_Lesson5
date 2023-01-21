//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#pragma once

#include "SnackType.h"

struct Snack
{
   private:
   SnackType snackName;
   public:
   Snack();
   Snack(SnackType snackType);
   SnackType getSnackName() const;
};