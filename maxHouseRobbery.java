import java.util.*;
import java.io.*;
import java.math.*;

public class maxHouseRobbery {
    public static void main(String[] args) {
        ArrayList<Integer> values = new ArrayList<Integer>(Arrays.asList(5, 3, 4, 11, 2, 1, 4));
        int soln = maxVal(0, values.size(), values);
        System.out.println("Maximum possible stolen value for houses = " + soln);
    }

    public static int maxVal(int pos, int N, ArrayList<Integer> vals) {
        int left, right;
        if (pos < N) {
            left = vals.get(pos) + maxVal(pos + 2, N, vals);
        } else {
            left = 0;
        }
        if (pos + 1 < N) {
            right = vals.get(pos + 1) + maxVal(pos + 3, N, vals);
        } else {
            right = 0;
        }
        return left > right ? left : right;
    }
}
