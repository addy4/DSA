import java.util.*;
import java.io.*;
import java.math.*;

// Look and Say Sequence @sked in Facebook!

public class lookSay {
    public static void main(String[] args) {
        createSequence(Integer.parseInt(args[0]));
    }

    public static void createSequence(int n) {
        String s = "1";
        int nums = 0;
        char image;
        int counter = 0;
        int j;
        String newS = "";
        while (true) {
            // System.out.println("In While!");
            if (nums > n) {
                break;
            }
            for (int i = 0; i < s.length(); i++) {
                // System.out.println("In For!");
                image = s.charAt(i);
                counter++;
                j = i + 1;
                // System.out.print("counter = " + counter + ", image = " + image);
                while (j < s.length() && image == s.charAt(j)) {
                    // System.out.println("In second While!");
                    counter++;
                    j++;
                }
                i = j - 1;
                // System.out.print("\nFinal counter = " + counter + ", final image = " +
                // image);
                newS = newS + Integer.toString(counter);
                newS = newS + image;
                counter = 0;
            }
            s = newS;
            newS = "";
            System.out.print(s + ", ");
            nums++;
        }
    }
}