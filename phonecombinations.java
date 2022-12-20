import java.util.*;
import java.io.*;

public class phonecombinations {

    public static void combinations(String str, int i, HashMap<Integer, String[]> map, int maxInteger,
            ArrayList<String> answers, ArrayList<Integer> input) {

        if (i > (input.size() - 1)) {
            answers.add(str);
            return;
        }

        String org = str;
        String[] chars = map.get(input.get(i));

        for (String c : chars) {
            str = str + c;
            combinations(str, i + 1, map, maxInteger, answers, input);
            //answers.add(str);
	    str = org;
        }
    }

    public static void main(String[] args) {
        ArrayList<String> answers = new ArrayList<String>();
        HashMap<Integer, String[]> map = new HashMap<>();
        ArrayList<Integer> input = new ArrayList<Integer>();

        Scanner sc = new Scanner(System.in);

        /*
	while (sc.nextInt() != -1) {
            input.add(sc.nextInt());
            System.out.println(sc.hasNext());
        }
	*/

	input.add(1);
	input.add(2);
	input.add(3);

        sc.close();

        String[] arr = { "A", "B", "Z" };
        String[] arr1 = { "W", "E" };
        String[] arr2 = { "C", "D" };

        map.put(1, arr);
        map.put(2, arr1);
        map.put(3, arr2);

        combinations("", 0, map, input.size(), answers, input);

        for (String i : answers) {
            System.out.println(i);
        }

        return;
    }
}
