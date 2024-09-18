//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

enum Plane_status {
    null,
    arriving,
    departing,
};


class Plane {

public:

    Plane();

    Plane(int flt, int time, Plane_status status);  // 构造函数，初始化飞机的航班号、起飞时间和状态。

    void refuse() const;    // 拒绝飞机的降落操作

    void land(int time) const;  // 接受飞机的降落操作

    void fly(int time) const;   // 让飞机起飞

    int started() const;    // 用于返回clock_start （时钟起始时间）


private:
    int flt_num;
    int clock_start;
    Plane_status state;

};