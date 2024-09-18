//
// Created by Deralive (10235101526) on 2024/03/28.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "MyQueue.cpp"

enum Runway_activity {
    idle,
    land,
    takeoffs,
};


class Runway {

public:

    Runway(int limit); // 初始化跑道，Limit 值指的是

    Error_code can_land(const Plane &current);  //  判断一架飞机是否能够降落

    Error_code can_depart(const Plane &current);    // 判断一架飞机是否能够离开跑道

    Runway_activity activity(int time, Plane &moving);  //  描述改时间刻在跑道上飞机的活动情况

    void shut_down(int time) const; //  关闭跑道的服务


private:

    MyQueue landing;

    MyQueue takeoff;

    int queue_limit;

    int num_land_requests;        //  number of planes asking to land

    int num_takeoff_requests;     //  number of planes asking to take off

    int num_landings;             //  number of planes that have landed

    int num_takeoffs;             //  number of planes that have taken off

    int num_land_accepted;        //  number of planes queued to land

    int num_takeoff_accepted;     //  number of planes queued to take off

    int num_land_refused;         //  number of landing planes refused

    int num_takeoff_refused;      //  number of departing planes refused

    int land_wait;                //  total time of planes waiting to land

    int takeoff_wait;             //  total time of planes waiting to take off

    int idle_time;                //  total time runway is idle

};

