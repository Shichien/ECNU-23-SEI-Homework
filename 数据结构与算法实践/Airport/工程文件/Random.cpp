//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "random.h"
#include<ctime>
#include<cmath>
#include<climits>

/*
* Pre : None.
* Post: The seed is replaced by a pseudorandom successor.
*/
int Random::reseed() {
    seed = seed * multiplier + add_on; // 使用线性关系再生成一个随机数
    return seed;
}

/*
* Pre : The values of seed, add_on, and multiplier are initialized.
* Post: The seed is initialized randomly only if pseudo == false.
*/
Random::Random(bool pseudo)

{
    if (pseudo) seed = 1; 
    else seed = time(NULL) % INT_MAX;
    multiplier = 2743;
    add_on = 5923;
}

/*
* Pre : None.
* Post: A random real number between 0 and 1 is returned.
*/
double Random::random_real() {

    double max = INT_MAX + 1.0;  //INT_MAX = (2)31 -1
    double temp = reseed();
    if (temp < 0) temp = temp + max;
    return temp / max;
}

/*
* Pre : None.
* Post: A random integer between low and high (inclusive) is returned.
*/
int Random::random_integer(int low, int high) {
    if (low > high) return random_integer(high, low);
    else return ((int) ((high - low + 1) * random_real())) + low;
}

/*
* Pre : None.
* Post: A random integer, reflecting a Poisson distribution with parameter mean, is returned.
*/
int Random::poisson(double mean) {
    double limit = exp(-mean);
    double product = random_real();
    int count = 0;
    while (product > limit) {
        count++;
        product *= random_real();
    }
    return count;
}

