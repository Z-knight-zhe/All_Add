#include "driver.h"

void driver::prc_driver() {
    sc_uint<3> pattern;
    pattern = 0;
    
    while(1) {
#ifdef USE_CLK
        wait(clk.posedge_event());
#endif
        d_a = pattern[0];
        d_b = pattern[1];
        d_cin = pattern[2];

#ifndef USE_CLK
        wait(5, SC_NS);
#endif

        pattern++;
    }
}