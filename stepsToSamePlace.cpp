#include </Users/PremBhatia1/stdc.h>

using namespace std;

/* 
int ways(int coins[], int n, int sum, int steps, int arrlen)
{
    cout << "sum: " << sum << ", n: " << n << ", steps: " << steps << ", arrlen: " << arrlen << endl;

    if (sum == 0 && steps == 0 && arrlen >= 0 && arrlen < 2)
    {
        return 1;
    }

    if (steps < 0 || arrlen < 0 || arrlen >= 2)
    {
        return 0;
    }

    if (sum < 0)
    {
        return 0;
    }

    if (n <= 0)
    {
        return 0;
    }

    cout << "-------- at " << arrlen << endl;
    cout << "-------- taking step " << coins[n - 1] << endl;

    int a = ways(coins, n, sum - coins[n - 1], steps - 1, arrlen - coins[n - 1]);

    //arrlen = arrlen + coins[n - 1];
    cout << "-------- at " << arrlen << endl;

    int b = ways(coins, n - 1, sum, steps - 1, arrlen);

    return a + b;
}
*/

int ways(int index, int steps, int range, int stepsTotal)
{
    cout << "index: " << index << ", steps: " << steps << endl;
    if (index == 0 && steps == stepsTotal)
    {
        return 1;
    }
    if (index < 0 || index > range - 1) // range - 1
    {
        return 0;
    }
    if (steps > stepsTotal)
    {
        return 0;
    }
    int a = ways(index + 1, steps + 1, range, stepsTotal);
    int b = ways(index - 1, steps + 1, range, stepsTotal);
    int c = ways(index, steps + 1, range, stepsTotal);

    //cout << "a = " << a << endl;
    //cout << "b = " << b << endl;
    //cout << "c = " << c << endl;

    return a + b + c;
}

int dpways(int index, int steps, int range, int stepsTotal, vector<vector<int>> &dp)
{
    cout << "index: " << index << ", steps: " << steps << endl;
    if (index < 0 || index >= range)
    {
        return 0;
    }
    if (steps < 0)
    {
        return 0;
    }

    if (dp[index][steps] != -1)
    {
        return dp[index][steps];
    }

    dp[index][steps] = dpways(index + 1, steps - 1, range, stepsTotal, dp) + dpways(index - 1, steps - 1, range, stepsTotal, dp) + dpways(index, steps - 1, range, stepsTotal, dp);

    return dp[index][steps];
}

int main(int argc, char const *argv[])
{
    int index = 0;
    int stepsTotal = 4;
    int steps = 0;
    int range = 2;

    // +1 RIGHT
    // -1 LEFT
    // 0 STAY

    //cout << ways(index, steps, range, stepsTotal) << endl;

    vector<vector<int>> dp(range, vector<int>(stepsTotal + 1, -1));
    dp[0][0] = 1;

    int stepsd = stepsTotal;
    index = 0;

    cout << dpways(index, stepsd, range, stepsTotal, dp) << endl;

    cout << dp[index][stepsd] << endl;

    return 0;
}

// DP based
// dp[n][m]
// n = range (2), m = steps (4) : dp[0, 1][0, 1, 2, 3, 4]
// dp[0][0] = 0
// do steps -> steps - 1 in recursive call