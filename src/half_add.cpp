#include "half_add.h"

void half_add::prc_half_add() {
    sum = a ^ b;
    carry = a & b;
}