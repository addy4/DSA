import java.io.*;
import java.lang.*;
import java.math.*;

/*
Problem : Window String
Run : javac WinString.java ; java GetMinSizeWindow
*/

class GetMinSizeWindow {

    public String window(String str, String pat) {

        System.out.println("Task : Find minimum sized window having all occurences of '" + pat + "' in '" + str + "'");

        int[] hashstring = new int[256];
        int[] hashpattern = new int[256];
        int count = 0, start = 0, start_index = -1, window_length = -1, min_length = Integer.MAX_VALUE;

        for (int i = 0; i < pat.length(); i++) {
            hashpattern[pat.charAt(i)]++;
        }

        for (int j = 0; j < str.length(); j++) {

            hashstring[str.charAt(j)]++;

            if (hashstring[str.charAt(j)] <= hashpattern[str.charAt(j)]) {
                count++;
            }

            if (count == pat.length()) {
                while (hashstring[str.charAt(start)] > hashpattern[str.charAt(start)]) {
                    hashstring[str.charAt(start)]--;
                    start++;
                }

                window_length = j - start + 1;
                if (window_length < min_length) {
                    start_index = start;
                    min_length = window_length;
                }
            }
        }

        return str.substring(start_index, start_index + min_length);
    }

    public static void main(String[] args) {
        GetMinSizeWindow solve = new GetMinSizeWindow();
        System.out.println("minimum window ~ " + solve.window("alalalalaaaabaaalaaalab", "bal"));
    }

};
