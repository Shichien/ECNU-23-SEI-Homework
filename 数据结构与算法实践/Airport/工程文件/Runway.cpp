//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Runway.h"
#include <iostream>

using namespace std;

/*
* Pre : None.
* Post: The Runway data members are initialized.
*/
Runway::Runway(int limit) {
    queue_limit = limit;
    num_land_requests = num_takeoff_requests = 0;
    num_landings = num_takeoffs = 0;
    num_land_refused = num_takeoff_refused = 0;
    num_land_accepted = num_takeoff_accepted = 0;
    land_wait = takeoff_wait = idle_time = 0;
}

/*
* Pre : The Runway object is properly initialized with a landing queue and the 'current' Plane object is valid.
* Post: If possible, the Plane current is added to the landing Queue.
*/
Error_code Runway::can_land(const Plane &current) {
    Error_code result;
    if (landing.size() < queue_limit)
        result = landing.append(current);
    else
        result = fail;
    num_land_requests++;
    if (result != success)
        num_land_refused++;
    else
        num_land_accepted++;
    return result;
}

/*
* Pre : The Runway object is properly initialized with a takeoff queue and the 'current' Plane object is valid.
* Post: The Plane current is added to the takeoff queue.
*/
Error_code Runway::can_depart(const Plane &current) {
    Error_code result;
    if (takeoff.size() < queue_limit)
        result = takeoff.append(current);
    else
        result = fail;
    num_takeoff_requests++;
    if (result != success)
        num_takeoff_refused++;
    else
        num_takeoff_accepted++;
    return result;
}

/*
* Pre : The Runway object is properly initialized with landing and takeoff Queues.
* Post:  If the landing Queue has entries, its front Plane is copied to the parameter moving and a result and is returned. 
Otherwise, if the takeoff Queue has entries, its front Plane is copied to the parameter moving and a result takeoff is returned.
Otherwise, idle is returned. Runway statistics are updated.
*/
Runway_activity Runway::activity(int time, Plane &moving) {
    Runway_activity in_progress;
    if (!landing.empty()) {
        landing.retrieve(moving);
        land_wait += time - moving.started();
        num_landings++;
        in_progress = land;
        landing.serve();
    } else if (!takeoff.empty()) {
        takeoff.retrieve(moving);
        takeoff_wait += time - moving.started();
        num_takeoffs++;
        in_progress = takeoffs;
        takeoff.serve();
    } else {
        idle_time++;
        in_progress = idle;
    }
    return in_progress;
}

/*
* Pre : After completing the aircraft simulation operation.
* Post: Runway usage statistics are summarized and printed.
*/
void Runway::shut_down(int time) const {
    cout << "Simulation has concluded after " << time << " time units." << endl
         << "Total number of planes processed "
         << (num_land_requests + num_takeoff_requests) << endl
         << "Total number of planes asking to land "
         << num_land_requests << endl
         << "Total number of planes asking to take off "
         << num_takeoff_requests << endl
         << "Total number of planes accepted for landing "
         << num_land_accepted << endl
         << "Total number of planes accepted for takeoff "
         << num_takeoff_accepted << endl
         << "Total number of planes refused for landing "
         << num_land_refused << endl
         << "Total number of planes refused for takeoff "
         << num_takeoff_refused << endl
         << "Total number of planes that landed "
         << num_landings << endl
         << "Total number of planes that took off "
         << num_takeoffs << endl
         << "Total number of planes left in landing queue "
         << landing.size() << endl
         << "Total number of planes left in takeoff queue "
         << takeoff.size() << endl;
    cout << "Percentage of time runway idle "
         << 100.0 * ((float) idle_time) / ((float) time) << "%" << endl;
    if (num_landings)
        cout << "Average wait in landing queue "
             << ((float) land_wait) / ((float) num_landings) << " time units";
    else
        cout << "Average wait in landing queue 0 time units";
    if (num_takeoffs)
        cout << endl << "Average wait in takeoff queue "
             << ((float) takeoff_wait) / ((float) num_takeoffs) << " time units" << endl;
    else
        cout << "Average wait in takeoff queue 0 time units" << endl;
    cout << "Average observed rate of planes wanting to land "
         << ((float) num_land_requests) / ((float) time)
         << " per time unit" << endl;
    cout << "Average observed rate of planes wanting to take off "
         << ((float) num_takeoff_requests) / ((float) time)
         << " per time unit" << endl;
}
