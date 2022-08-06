import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

class minimum_array_jumps {
    public static void main(String[] args) {
        int[] arr = { 1, 4, 8, 1, 1, 1, 1, 1 };
        long count_ = steps(0, arr);
        System.out.println("minimum number of jumps to reach " + arr[arr.length - 1] + " is "
                + (count_ == Integer.MAX_VALUE ? -1 : count_));
    }

    public static long steps(int index, int[] arr) {

        if (arr[index] >= arr.length - index - 1) {
            return 1;
        }

        long minVal = Integer.MAX_VALUE;

        for (int j = index + 1; j <= index + arr[index]; j++) {

            long _count = 1 + steps(j, arr);

            if (_count < minVal) {
                minVal = _count;
            }

        }

        return minVal;
    }

}
