#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include </Users/PremBhatia1/stdc.h>

using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed);

class Car
{
public:
    double pos;
    double time_dest;
    int speed;

    Car(double position, int pace, int target)
    {
        this->pos = position;
        this->speed = pace;
        this->time_dest = double((target - this->pos) / (this->speed));
    }
};

bool willMeet(Car *front, Car *back, int target)
{
    cout << "Front~ " << front->pos << ", " << front->speed << endl;
    cout << "Back~ " << back->pos << ", " << back->speed << endl;
    double t_front = double((target - front->pos) / (front->speed));
    double t_back = double((target - back->pos) / (back->speed));

    cout << "Front~ ~ ~ ~ ~ " << t_front << endl;
    cout << "Back~ ~ ~ ~ ~ " << t_back << endl;

    if (t_back <= t_front)
    {
        cout << "front meets back :)" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

Car *merge(Car *front, Car *back)
{
    cout << "Front~ " << front->pos << ", " << front->speed << endl;
    cout << "Back~ " << back->pos << ", " << back->speed << endl;
    int rspeed = back->speed - front->speed;
    double lapsed = double((front->pos - back->pos) / rspeed);
    double pos_fleet = double((front->speed * lapsed) + front->pos);
    Car *cnew = new Car(pos_fleet, front->speed, 12);
    cout << "-- merged as.." << endl;
    cout << "-- pos" << cnew->pos << endl;
    cout << "-- speed" << cnew->speed << endl;
    return cnew;
}

bool cmp(Car *A, Car *B)
{
    if (A->pos == B->pos)
    {
        return (A->speed < B->speed);
    }
    return (A->pos > B->pos);
}

int main(int argc, char const *argv[])
{
    int target = 31;
    vector<int> position = {5, 26, 18, 25, 29, 21, 22, 12, 19, 6};
    vector<int> speed = {7, 6, 6, 4, 3, 4, 1, 7, 6, 4};
    int fleets = carFleet(target, position, speed);
    cout << fleets << endl;
    return 0;
}

int o_carFleet(int target, vector<int> &position, vector<int> &speed)
{
    if (position.size() == 0)
    {
        return 0;
    }

    vector<Car *> cars;

    for (int i = 0; i < position.size(); i++)
    {
        Car *c = new Car(position[i], speed[i], target);
        cars.push_back(c);
    }

    sort(cars.begin(), cars.end(), cmp);

    for (int i = 0; i < position.size(); i++)
    {
        cout << i << ". " << cars[i]->pos << ", " << cars[i]->speed << endl;
    }

    stack<Car *> fleets;
    fleets.push(cars[0]);

    for (int i = 1; i < cars.size(); i++)
    {
        if (willMeet(fleets.top(), cars[i], target))
        {
            //Car *cnew = merge(cars[i], fleets.top());
            Car *cnew = merge(fleets.top(), cars[i]);
            fleets.pop();
            fleets.push(cnew);
        }
        else
        {
            fleets.push(cars[i]);
        }
    }

    return fleets.size();
}

// Start for dest nearest car
// Get timeu for reaching dest
// If timei for the second car to reach dest < timeu
// then do nothing
// otherwise update timeu as timei, fleets++
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    double last_time = -1;
    int fleet = 1;

    if (position.size() == 0)
    {
        return 0;
    }

    vector<Car *> cars;

    for (int i = 0; i < position.size(); i++)
    {
        Car *c = new Car(position[i], speed[i], target);
        cars.push_back(c);
    }

    sort(cars.begin(), cars.end(), cmp);

    for (int i = 0; i < position.size(); i++)
    {
        cout << i << ". " << cars[i]->pos << ", " << cars[i]->speed << ", " << cars[i]->time_dest << endl;
    }

    stack<Car *> fleets;
    fleets.push(cars[0]);
    last_time = cars[0]->time_dest;

    /*
    for (int i = 1; i < cars.size(); i++)
    {
        double last_car_reach_time = fleets.top()->time_dest;
        cout << "last car reach time: " << last_car_reach_time << endl;
        double curr_reach_time = cars[i]->time_dest;
        cout << "curr car reach time: " << curr_reach_time << endl;
        if (curr_reach_time > last_car_reach_time)
        {
            fleet++;
            fleets.push(cars[i]);
        }
    }

    return fleet;
    */

    for (int i = 1; i < cars.size(); i++)
    {
        if (cars[i]->time_dest > last_time)
        {
            fleet++;
            last_time = cars[i]->time_dest;
            cout << "last time is " << last_time << endl;
        }
    }

    return fleet;
}