//https://www.geeksforgeeks.org/minimum-number-of-towers-required-such-that-every-house-is-in-the-range-of-at-least-one-tower/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void net_towers(int *houses, int range, int size)
{
    // Locations
    vector<int> locations;

    // Assignments
    for (int i = 0; i < size; i++)
    {
        locations.push_back(houses[i]);
    }

    // Towers
    for (int i = 0; i < size; i++)
    {
        auto x = locations[0];
        if (i == size - 1 || (houses[i] - x <= range && houses[i + 1] - x > range))
        {
            cout << "Tower at " << houses[i] << endl;
            cout << "- - - - above tower covers " << locations[0] << endl;
            locations.erase(locations.begin());
            while (!locations.empty() && abs(locations[0] - houses[i]) <= range)
            {
                cout << "- - - - above tower covers " << locations[0] << endl;
                locations.erase(locations.begin());
            }
        }
        if (locations.empty())
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    // given elements

    //int house[] = {7, 2, 4, 6, 5, 9, 12, 11, 14, 17, 8, 24, 15, 29};
    //int house[] = {2, 4, 6};
    //int house[] = {3, 4, 9, 10, 19};
    //int house[] = {7, 2, 4, 6, 5, 9, 12, 11};

    int house[] = {2, 4, 5, 6, 7, 9, 11, 17, 24};
    int range = 4;
    int n = sizeof(house) / sizeof(house[0]);

    net_towers(house, range, n);

    return 0;
}
