#include "systemc.h"
#include "half_add.h"

SC_MODULE(driver) {
    sc_out<bool> d_a, d_b, d_cin;
#ifdef USE_CLK
    sc_in<bool> clk;
#endif
    void prc_driver();

    SC_CTOR(driver) {
        SC_THREAD(prc_driver);
    }
};