#include </Users/PremBhatia1/stdc.h>

using namespace std;

int searchElem(vector<int> &nums, int left, int right, int target)
{
    cout << "left = " << left << ", "
         << " right = " << right << endl;

    if (nums[left] == target)
    {
        return left;
    }
    if (nums[right] == target)
    {
        return right;
    }

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if ((nums[left] == nums[mid]) && (nums[mid] == nums[right]))
        {
            cout << "C 1" << endl;
            left++;
            right--;
            return searchElem(nums, left, right, target);
        }
        else if (nums[left] > nums[mid])
        {
            cout << "C 2" << endl;
            // second half sorted
            if (target >= nums[mid + 1] && target <= nums[right])
            {
                cout << "C 3" << endl;
                return searchElem(nums, mid + 1, right, target);
            }
            else
            {
                cout << "C 4" << endl;
                return searchElem(nums, left, mid, target);
            }
        }
        else
        {
            cout << "C 5" << endl;
            // first half sorted
            if (target >= nums[left] && target <= nums[mid])
            {
                cout << "C 6" << endl;
                return searchElem(nums, left, mid, target);
            }
            else
            {
                cout << "C 7" << endl;
                return searchElem(nums, mid + 1, right, target);
            }
        }
    }
    return -1;
}

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return searchElem(nums, 0, nums.size() - 1, target);
    }
};

int main(int argc, char const *argv[])
{
    //vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};

    Solution *sln = new Solution();

    int target;

    target = 2;
    int x = sln->search(nums, target);
    cout << x << endl;
    return 0;
}
