// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// Merge sorted arrays

#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>

int platforms(int *arr, int *dep, int trains);

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1020, 1130, 1900, 2000};

    cout << platforms(arr, dep, sizeof(arr) / sizeof(arr[0])) << endl;

    return 0;
}

int platforms(int *arr, int *dep, int trains)
{

    sort(arr, arr + trains); // if sorting is not applied, we get ans 3 which is wrong
    sort(dep, dep + trains); // reason: 950 waali train if leaves 10:20, we get max plats as 2!

    vector<int> merge_sorted;
    int p = 0, i = 0, j = 0, palts = 0, mplats = INT16_MIN;

    while (i < trains && j < trains)
    {
        if (arr[i] < dep[j])
        {
            i++;
            mplats = (++palts) > mplats ? palts : mplats;

            cout << "#train " << i << " arrives at " << arr[i - 1] << endl;
            merge_sorted.push_back(arr[i - 1]);
        }
        if (dep[j] <= arr[i])
        {
            j++;
            palts--;

            cout << "#train " << j << " leaves at " << dep[j - 1] << endl;
            merge_sorted.push_back(dep[j - 1]);
        }
    }

    if (i < trains)
    {
        while (i < trains)
        {
            merge_sorted.push_back(arr[i]);
            i++;
        }
    }
    else
    {
        while (j < trains)
        {
            merge_sorted.push_back(dep[j]);
            j++;
        }
    }

    for (auto i : merge_sorted)
    {
        cout << "# " << i << endl;
    }

    return mplats;
}
