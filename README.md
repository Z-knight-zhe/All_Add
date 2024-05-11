# All_Add
这是一个基于SystemC的全加器的例子

在include/half_add.h文件夹下，使用宏开关控制USE_CLK决定是否打开顶层的clk信号。
打开顶层clk信号时，只对于全加器的结果敏感
若不打开，则对，a,b,cin都敏感，此时当输入信号改变时也会打印，会出现sum,carry还未及时更新的情况。
因此引入USE_CLK宏开关以避免此情况。