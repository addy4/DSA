#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <array>
#include <vector>

using namespace std;

int min_jumps(int index, int arr[], int arrlen, vector<int> *v)
{
    int min = 10000000;
    int min_index;
    int steps;

    if (index >= arrlen - 1)
    {
        return 0;
    }

    for (int j = 1; j <= arr[index]; j++)
    {
        steps = 1 + min_jumps(index + j, arr, arrlen, v);
        if (steps < min)
        {
            min = steps;
            min_index = index + j;
        }
    }

    return min;
}

int min_jumps_store(int index, int arr[], int arrlen, vector<int> *v, vector<vector<int>> *vstore)
{
    int min = 10000000;
    int min_index;
    int steps;

    cout << "now at " << index << endl;

    (*v).push_back(index);

    if (index >= arrlen - 1)
    {
        for (auto it = 0; it < (*v).size(); it++)
        {
            cout << "-> " << (*v)[it];
        }
        cout << endl;
        cout << "reached at " << index << endl;
        (*vstore).push_back(*v);
        cout << "popping back " << (*v)[(*v).size() - 1] << endl;
        (*v).pop_back();
        return 0;
    }

    for (int j = 1; j <= arr[index]; j++)
    {
        cout << "AT: " << index << " with j: " << j << endl;
        if (index + j == arrlen)
        {
            break;
        }
        cout << "... progressing to " << index + j << " and index = " << index << endl;
        steps = 1 + min_jumps_store(index + j, arr, arrlen, v, vstore);
    }

    cout << "popping back " << (*v)[(*v).size() - 1] << endl;
    (*v).pop_back();

    return min;
}

int main(int argc, char const *argv[])
{
    //int arr[] = {1, 15, 5, 6, 9, 2, 6, 7, 6, 8, 9, 1, 3, 5, 6, 9, 2, 6, 7, 6, 8, 9};
    int arr[] = {3, 1, 2, 4};
    vector<int> v;
    vector<vector<int>> vstore;

    cout << "Start MinJumps" << endl;

    cout << min_jumps_store(0, arr, sizeof(arr) / sizeof(arr[0]), &v, &vstore) << endl;
    //cout << min_jumps(0, arr, sizeof(arr) / sizeof(arr[0]), &v) << endl;

    //return -1;

    int len = INT32_MAX;
    auto k = vstore.begin();

    for (auto it = (vstore).begin(); it != (vstore).end(); ++it)
    {
        if ((*it).size() < len)
        {
            len = (*it).size();
            k = it;
        }
    }

    cout << len << endl;

    for (auto iter = (*k).begin(); iter != (*k).end(); ++iter)
        cout << '-' << *iter;
    cout << endl;

    return 0;
}

// if j is zero, we get seg fault coz we never move forward actually
// if min is set to MAXINT, we get wrong answer because 1 + MAXINT < 0
// if we do index == arrlen -1 instead of index >= arrlen - 1, we get fault as ..
