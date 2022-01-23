import java.util.*;
import java.io.*;
import java.math.*;

public class wordBreakDP32DP {
    public static void main(String[] args) {
        System.out.println("DP based soln for word break DP 32 GFG");
        ArrayList<String> B = new ArrayList<>(Arrays.asList("i", "ol", "io", "ls", "keysight"));
        String A = "iolskeysight";
        if (wordBreakDP(A, B)) {
            System.out.println("FOUND");
        } else {
            System.out.println("NOT FOUND");
        }
    }

    public static boolean wordBreakDP(String A, ArrayList<String> B) {
        boolean dpwordbreak[] = new boolean[A.length()];
        for (int i = 0; i < A.length(); i++) {
            if (dpwordbreak[i] == false && B.contains(prefix(0, i, A))) {
                dpwordbreak[i] = true;
            }
            if (i == A.length() - 1 && dpwordbreak[i] == true) {
                return true;
            }

            if (dpwordbreak[i] == true) {
                for (int j = i + 1; j < A.length(); j++) {
                    if (dpwordbreak[j] == false && B.contains(prefix(i + 1, j, A))) {
                        dpwordbreak[j] = true;
                    }
                    if (j == A.length() - 1 && dpwordbreak[j] == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static String prefix(int start, int end, String A) {
        String pref = "";
        for (int j = start; j <= end; j++) {
            pref = pref + A.charAt(j);
        }
        return pref;
    }
}