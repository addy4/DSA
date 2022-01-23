import java.io.*;
import java.util.*;
import java.math.*;

// https://www.geeksforgeeks.org/word-break-problem-dp-32/ recursive soln

public class wordBreakDP32 {
    public static void main(String[] args) {
        System.out.println("Find if the given word can be broken into one or more words present in list of words");
        ArrayList<String> B = new ArrayList<String>(Arrays.asList("i", "ol", "skeysight"));
        String A = "iolskeysight";
        if (wordBreakDynamicProg32(A, B)) {
            System.out.println("\n\nFOUND");
        } else {
            System.out.println("\n\nNOT FOUND");
        }
    }

    public static boolean wordBreakDynamicProg32(String A, ArrayList<String> B) {
        if (A.length() == 0) {
            return true;
        }
        for (int i = 0; i < A.length(); i++) {
            boolean prefixcheck = checkPrefixInWord(i, A, B);
            System.out.println("prefix = " + prefixcheck);
            String suffixWord = getSuffixWord(A, i, A.length());
            if (prefixcheck && wordBreakDynamicProg32(suffixWord, B)) {
                return true;
            }
        }
        return false;
    }

    public static boolean checkPrefixInWord(int i, String A, ArrayList<String> B) {
        System.out.println("\nA = " + A);
        System.out.println("A.size = " + A.length());
        System.out.println("i = " + i);
        String pref = "";
        for (int j = -1; j < i; j++) {
            pref = pref + A.charAt(j + 1);
        }
        System.out.println("prefix word = " + pref);
        System.out.println("B.contains = " + B.contains(pref));
        return B.contains(pref);
    }

    public static String getSuffixWord(String A, int i, int N) {
        String suffix = "";
        for (int j = i + 1; j < A.length(); j++) {
            suffix = suffix + A.charAt(j);
        }
        System.out.println("suffix end word = " + suffix);
        return suffix;
    }
}