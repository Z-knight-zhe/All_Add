#ifndef HALF_ADD_H
#define HALF_ADD_H

#include "systemc.h"

//#define USE_CLK

SC_MODULE(half_add) {
    sc_in<bool> a, b;
    sc_out<bool> sum, carry;
    void prc_half_add();

    SC_CTOR(half_add) {
        SC_METHOD(prc_half_add);
        sensitive << a << b;
    }
};
#endif