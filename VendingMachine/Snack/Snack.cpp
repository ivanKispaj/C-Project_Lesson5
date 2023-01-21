//
//  Snack.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Snack.h"
#include "SnackType.h"

Snack::Snack()
{
    this->snackName = Empty;
}

Snack::Snack(SnackType snackType)
{
    this->snackName = snackType;
}

SnackType Snack::getSnackName() const
{
    return this->snackName;
}

