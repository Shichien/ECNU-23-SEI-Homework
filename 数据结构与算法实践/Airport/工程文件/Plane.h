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

    Plane(int flt, int time, Plane_status status);  // ���캯������ʼ���ɻ��ĺ���š����ʱ���״̬��

    void refuse() const;    // �ܾ��ɻ��Ľ������

    void land(int time) const;  // ���ܷɻ��Ľ������

    void fly(int time) const;   // �÷ɻ����

    int started() const;    // ���ڷ���clock_start ��ʱ����ʼʱ�䣩


private:
    int flt_num;
    int clock_start;
    Plane_status state;

};