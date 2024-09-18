//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

class Random {
public:
    Random(bool pseudo = true); // �ù��캯��ʹ�� Pseudo ������Ĭ�ϸ�ֵΪ�棬��ʾʹ�����������

    double random_real();   //  �������˫���ȸ���ʵ��

    int random_integer(int low, int high);  //  ���������Int���͵�ʵ��

    int poisson(double mean);   //  ���ɷ��ϲ��ɷֲ��������

private:
    int reseed();   // ʹ�����Խṹ�����µ�����������ӣ�

    int seed, multiplier, add_on;   // multiplier ����б�ʣ�add_on ����ؾ࣬Seed Ϊ������ɵ����ӡ�
};