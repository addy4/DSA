import java.io.*;
import java.math.*;
import java.lang.*;

//Problem Definition : https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/

class smallest_sum_subarray {

    boolean check_sum(int[] numbers, int k, int mid) {

        int sum = 0, kcount = 0;

        for (int i = 0; i < numbers.length; i++) {

            if (numbers[i] > mid) {
                return false;
            }

            sum = sum + numbers[i];
            if (sum > mid) {
                sum = numbers[i];
                kcount++;
            }
        }
        kcount++;

        if (kcount > k) {
            return false;
        }
        return true;
    }

    int binary_search(int[] numbers, int k, int maxsum, int minsum) {

        System.out.println("maxsum = " + maxsum + ", minsum = " + minsum);

        if (maxsum == minsum) {
            return minsum;
        }

        int mid = (maxsum + minsum) / 2;

        if (check_sum(numbers, k, mid)) {
            maxsum = maxsum - 1;
            maxsum = mid;
            return binary_search(numbers, k, maxsum, minsum);
        } else {
            minsum = minsum + 1;
            minsum = mid + 1;
            // minsum = minsum + 1 -> longer time
            return binary_search(numbers, k, maxsum, minsum);
        }
    }

    void get_subarrays(int[] numbers, int k) {
        int minsum = 1, maxsum = 0;
        for (int i = 0; i < numbers.length; i++) {
            maxsum = maxsum + numbers[i];
        }
        int answer = binary_search(numbers, k, maxsum, minsum);
        System.out.println("Sum ~ " + answer);
    }

    public static void main(String[] args) {
        System.out.println("~ split array largest sum ~");
        smallest_sum_subarray solver = new smallest_sum_subarray();
        int[] numbers = { 1, 2, 3, 4 };
        int k = 1;
        solver.get_subarrays(numbers, k);
        // System.out.println(solver.check_sum(numbers, k, 9));
    }
}
