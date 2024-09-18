//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Plane.h"
#include<iostream>

using namespace std;

/*
* Pre : end_time, queue_limit, arrival_rate, departure_rate are initialized.
* Post:  The Plane data members flt_num, clock_start,
* and state are set to the values of the parameters flt, time and status, respectively.
*/
Plane::Plane(int flt, int time, Plane_status status) {
    flt_num = flt;
    clock_start = time;
    state = status;
    cout << "Plane number " << flt << " ready to ";
    if (status == arriving)
        cout << "land." << endl;
    else
        cout << "take off." << endl;
}

/*
* Pre : None.
* Post: The Plane data members flt_num, clock_start, state are set to illegal default values.
*/
Plane::Plane() {
    flt_num = -1;
    clock_start = -1;
    state = null;
}

/*
* Pre: None.
* Post: Processes a Plane wanting to use Runway, when the Queue is full.
*/
void Plane::refuse() const {
    cout << "Plane number " << flt_num;
    if (state == arriving)
        cout << " directed to another airport" << endl;
    else
        cout << " told to try to takeoff again later" << endl;
}

/*
* Pre : end_time, queue_limit, arrival_rate, departure_rate are initialized.
* Post: Processes a Plane that is landing at the specified time.
*/
void Plane::land(int time) const {
    int wait = time - clock_start;
    cout << "\n" << time << ": Plane number " << flt_num << " landed after "
         << wait << " time unit" << ((wait == 1) ? "" : "s")
         << " in the landing queue. \n" << endl;
}

/*
* Pre : end_time, queue_limit, arrival_rate, departure_rate are initialized.
* Post: Process a Plane that is taking off at the specified time.
*/
void Plane::fly(int time) const {
    int wait = time - clock_start;
    cout << "\n" << time << ": Plane number " << flt_num << " took off after "
         << wait << " time unit" << ((wait == 1) ? "" : "s")
         << " in the takeoff queue. \n" << endl;
}

/*
* Pre : The Class Plane is initialized.
* Post: Return the time that the Plane entered the airport system.
*/
int Plane::started() const {
    return clock_start;
}
