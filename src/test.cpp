#include "driver.h"
#include "monitor.h"
#include "full_add.h"

int sc_main(int argc, char **argv) {
    sc_signal<bool> t_a, t_b, t_cin, t_sum, t_cout;
#ifdef USE_CLK
    sc_clock clk("clk", 10, SC_NS);
#endif
    full_add f1("FullAddWithHalfAdd");
    f1.a(t_a);
    f1.b(t_b);
    f1.c_i(t_cin);
    f1.sum(t_sum);
    f1.carry(t_cout);

    driver d1("Generator");
    d1.d_a(t_a);
    d1.d_b(t_b);
    d1.d_cin(t_cin);
#ifdef USE_CLK
    d1.clk(clk);
#endif

    monitor mo1("Monitor");
    mo1.m_a(t_a);
    mo1.m_b(t_b);
    mo1.m_cin(t_cin);
    mo1.m_sum(t_sum);
    mo1.m_cout(t_cout);
#ifdef USE_CLK
    mo1.clk(clk);
#endif

    sc_start(100, SC_NS);
    return 0;
}