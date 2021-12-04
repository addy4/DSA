import java.util.*;
import java.io.*;
import java.math.*;

/*
Google Kick Start
Round B (yr. 2018)
Problem #2 : Sherlock and Bit Strings
*/

public class sherlock {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        ArrayList<ArrayList<Integer>> arrli = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            int P = sc.nextInt();
            int[][] constraints = new int[K][3];
            int[] answer = new int[N];
            for (int j = 0; j < K; j++) {
                constraints[j][0] = sc.nextInt();
                constraints[j][1] = sc.nextInt();
                constraints[j][2] = sc.nextInt();
            }
            arrli.add(new ArrayList<Integer>());
            getBitString(constraints, answer, N, K, P, arrli, i);
        }
        for (int t = 0; t < T; t++) {
            System.out.print("Case #" + (t + 1) + ": ");
            for (int ll = 0; ll < arrli.get(t).size(); ll++) {
                System.out.print(arrli.get(t).get(ll));
            }
            System.out.println();
        }
        sc.close();
    }

    public static void getBitString(int[][] constraints, int[] answer, int N, int K, int P,
            ArrayList<ArrayList<Integer>> arrli, int i) {
        ArrayList<Integer> blank = new ArrayList<Integer>();
        for (int l = 0; l < K; l++) {
            answer[constraints[l][0] - 1] = 1;
            arrli.get(i).add(1);
        }
        for (int n = 0; n < answer.length; n++) {
            if (answer[n] != 1) {
                answer[n] = -1;
                blank.add(n);
            }
        }
        int p = P - 1;
        for (int s = 0; s < blank.size(); s++) {
            answer[blank.get(s)] = p / (int) Math.pow(2, blank.size() - s - 1);
            arrli.get(i).add(blank.get(s), p / (int) Math.pow(2, blank.size() - s - 1));
            p = p - (p / (int) Math.pow(2, blank.size() - s - 1)) * (int) Math.pow(2, blank.size() - s - 1);
        }
    }
}