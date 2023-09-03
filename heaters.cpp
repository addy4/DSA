#include </Users/PremBhatia1/stdc.h>

using namespace std;

int radius(int[], int[], int, int);
int calculate(int heaters[], int start, int end, int room_loc, int size);

int main(int argc, char const *argv[])
{
    int rooms[] = {1, 4, 15, 24, 24, 24, 24, 26, 26, 26, 12, 2, 24};
    int heaters[] = {2, 12, 24, 26};
    int r = radius(rooms, heaters, sizeof(rooms) / sizeof(rooms[0]) - 1, sizeof(heaters) / sizeof(heaters[0]) - 1);
    //int x = calculate(heaters, 0, sizeof(heaters) / sizeof(heaters[0]), 10, sizeof(heaters) / sizeof(heaters[0]) - 1);
    cout << "-" << r << endl;
    return 0;
}

int radius(int rooms[], int heaters[], int room_num, int heaters_num)
{
    int radi = INT16_MIN;
    int calculated;
    for (int i = 0; i <= room_num; i++)
    {
        calculated = calculate(heaters, 0, heaters_num + 1, rooms[i], heaters_num);
        cout << calculated << endl;
        if (radi < calculated)
        {
            radi = calculated;
        }
    }
    return radi;
}

int calculate(int heaters[], int start, int end, int room_loc, int size)
{
    int ans;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (heaters[mid] == room_loc)
        {
            return 0;
        }
        else if (heaters[mid] > room_loc)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    if ((start - 1) < 0)
    {
        ans = abs(heaters[start] - room_loc);
    }
    else if (start > size)
    {
        ans = abs(heaters[start - 1] - room_loc);
    }
    else
    {
        ans = abs(heaters[start] - room_loc) > abs(heaters[start - 1] - room_loc) ? abs(heaters[start - 1] - room_loc) : abs(heaters[start] - room_loc);
    }
    //cout << ans << endl;
    return ans;
}
