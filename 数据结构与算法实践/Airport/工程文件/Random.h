//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

class Random {
public:
    Random(bool pseudo = true); // 该构造函数使用 Pseudo 变量，默认赋值为真，表示使用随机数生成

    double random_real();   //  生成随机双精度浮点实数

    int random_integer(int low, int high);  //  生成随机的Int类型的实数

    int poisson(double mean);   //  生成符合泊松分布的随机数

private:
    int reseed();   // 使用线性结构生成新的随机数（种子）

    int seed, multiplier, add_on;   // multiplier 代表斜率，add_on 代表截距，Seed 为最初生成的种子。
};