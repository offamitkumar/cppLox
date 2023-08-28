//
// Created by Amit Kumar on 4/08/23.
//

#include "header/value.h"
#include "iomanip"

void printValue(Value value) {
    std::cout << std::setprecision(15) << std::fixed << value;
}