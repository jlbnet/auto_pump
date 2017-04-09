# auto_pump
auto start pump when water full, and auto stop when water is empty. 

arduino nano 自动水泵。

读水位开关输入，高于最高水位时启动水泵，低于最低水位时停止。

A0端为模拟输入，接水位传感器（4线，红、蓝），并入10k电阻到+5V。

D5输出到继电器，驱动水泵。输出低时继电器闭合。

D6接LED，与D5反相，指示输出状态。启动水泵时led亮。

使用4线太阳能热水器的水位传感器，无水时电阻60k。

