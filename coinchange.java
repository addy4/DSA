// Recursive JAVA program for
// coin change problem.
import java.util.*;

//Problem Definition : https://www.geeksforgeeks.org/coin-change-dp-7/?ref=lbp

class GFG {

    // Returns the count of ways we can
    // sum S[0...m-1] coins to get sum n
    static int count(int S[], int m, int n, ArrayList<Integer> arrli, int include) {

        // System.out.println("Recursive Call... for m = " + m + ", n = " + n + ",
        // include = " + include);

        if (include == 1) {
            arrli.add(S[m - 1]);
        }

        // If n is 0 then there is 1 solution
        // (do not include any coin)
        if (n == 0) {
            for (int i = 0; i < arrli.size(); i++) {
                System.out.print(" - - - - - - - - - - " + arrli.get(i) + ", ");
            }
            // arrli.clear();
            System.out.println();
            return 1;
        }

        // If n is less than 0 then no
        // solution exists
        if (n < 0) {
            // if (arrli.size() > 0) {
            // arrli.remove(arrli.size() - 1);
            // }
            return 0;
        }

        // If there are no coins and n
        // is greater than 0, then no
        // solution exist
        if (m <= 0 && n >= 1) {
            // if (arrli.size() > 0) {
            // System.out.println("3. Removing " + arrli.get(arrli.size() - 1));
            // arrli.remove(arrli.size() - 1);
            // }
            return 0;
        }

        // count is sum of solutions (i)
        // including S[m-1] (ii) excluding S[m-1]
        int a = count(S, m - 1, n, arrli, 0);
        int b = count(S, m, n - S[m - 1], arrli, 1);

        if (arrli.size() > 0) {
            System.out.println("#Removing " + arrli.get(arrli.size() - 1));
            arrli.remove(arrli.size() - 1);
        }

        return a + b;
    }

    // Driver code
    public static void main(String args[]) {
        int arr[] = { 1, 2, 3 };
        int m = arr.length;

        ArrayList<Integer> arrli = new ArrayList<>();
        System.out.println(count(arr, m, 6, arrli, 0));
    }

}
