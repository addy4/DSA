import java.util.*;
import java.io.*;
import java.math.*;

public class maxHouseRobberyDP {
    public static void main(String[] args) {
        int[] houses = new int[] { 5, 3, 4, 11, 2, 1, 4 };
        System.out.println(maxStolenValueDP(houses));
    }

    public static int maxStolenValueDP(int[] houses) {
        int[] dpval = new int[houses.length];

        if (houses.length == 0) {
            return 0;
        }

        if (houses.length == 1) {
            return houses[0];
        }

        if (houses.length == 2) {
            return houses[0] > houses[1] ? houses[0] : houses[1];
        }

        dpval[0] = houses[0];
        dpval[1] = (houses[0] > houses[1] ? houses[0] : houses[1]);

        for (int i = 2; i < houses.length; i++) {
            dpval[i] = ((houses[i] + dpval[i - 2]) > dpval[i - 1]) ? (houses[i] + dpval[i - 2]) : dpval[i - 1];
        }
        return dpval[houses.length - 1];
    }
}
