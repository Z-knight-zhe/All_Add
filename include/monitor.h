#include "systemc.h"
#include "half_add.h"

SC_MODULE(monitor) {
    sc_in<bool> m_a, m_b, m_cin, m_sum, m_cout;
#ifdef USE_CLK
    sc_in<bool> clk;
#endif
    void prc_monitor();

    SC_CTOR(monitor) {
        SC_METHOD(prc_monitor);
#ifdef USE_CLK
        sensitive << clk.pos();
        dont_initialize();
#else
        sensitive << m_a << m_b << m_cin << m_sum << m_cout;
#endif
    }
};