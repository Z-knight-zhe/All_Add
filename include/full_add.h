#include "systemc.h"
#include "half_add.h"

SC_MODULE(full_add) {
    sc_in<bool> a, b, c_i;
    sc_out<bool> sum, carry;

    //链接模块的中间量
    sc_signal<bool> c1, s1, c2;

    void prc_or();

    half_add *half1_ptr, *half2_ptr;

    SC_CTOR(full_add) {
        half1_ptr = new half_add("half1");
        // 链接半加器模块端口和全加器模块端口
        half1_ptr->a(a);
        half1_ptr->b(b);
        half1_ptr->sum(s1);
        half1_ptr->carry(c1);

        half2_ptr = new half_add("half2");
        half2_ptr->a(s1);
        half2_ptr->b(c_i);
        half2_ptr->sum(sum);
        half2_ptr->carry(c2);

        SC_METHOD(prc_or);
        sensitive << c1 << c2;
    }

    ~full_add() {
        delete half1_ptr;
        delete half2_ptr;
    }
};