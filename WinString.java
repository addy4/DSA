import java.io.*;
import java.lang.*;
import java.math.*;

/*
javac WinString.java ; java GetMinSizeWindow
*/

class GetMinSizeWindow {

    public String window(String str, String pat) {

        System.out.println("Task : Find minimum sized window having all occurences of '" + pat + "' in '" + str + "'");

        int[] hashstring = new int[256];
        int[] hashpattern = new int[256];
        int count = 0, start = 0, start_index = -1, window_length = -1, min_length = Integer.MAX_VALUE;

	// get occurences of each alphabet in pat, hash map for no. of occurences of each char of pat
        for (int i = 0; i < pat.length(); i++) {
            hashpattern[pat.charAt(i)]++;
        }

	// iterate through str
        for (int j = 0; j < str.length(); j++) {

	    // populate hash map for str which is key-value mapping for char to no. of occurences for that char
            hashstring[str.charAt(j)]++;

	    // count will increase when for a particular char 'x' of string, number of occurences of 'x' in pattern exceed no. of occurences of 'x' in str
	    // this means one char of pattern i.e. 'x' get covered in string
	    // if this is false, it means string has more occurences of 'x' compared to pattern, which should not increase count because...
	    // because already char 'x' of pattern gets covered in string (or this means that there's no char 'x' in pattern)
            // so now count will increase when some other char 'y' of pattern is seen in string such that no. of occurences(x) in str <= no. occurences(x) in pat
            if (hashstring[str.charAt(j)] <= hashpattern[str.charAt(j)]) {
                count++;
            }

            // all chars of pattern are now seen in str
            if (count == pat.length()) {

		// move start point (initially 0) of sliding window towards right such that occurences of str[start] exceed no. of occurences of pattern[start]
		// start increase start = 0,1,2 ... as long as above condition is satisfied
		// this makes sure that all chars of pattern are still covered in str but start point of window moves more right
		// moving start point right ~ decreases length of window
                while (hashstring[str.charAt(start)] > hashpattern[str.charAt(start)]) {
                    hashstring[str.charAt(start)]--;
                    start++;
                }

		// updating windowlen every time after count == pat.length once
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
        System.out.println("minimum window ~ " + solve.window("thistisateststring", "tist"));
    }

};
