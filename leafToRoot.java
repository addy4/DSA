import java.util.*;
import java.io.*;

class Node {
    int val;
    int sumNode;
    Node left;
    Node right;

    Node() {
        this.val = 0;
        this.sumNode = 0;
        this.left = null;
        this.right = null;
    }

    Node(int val) {
        this.val = val;
        this.sumNode = 0;
        this.left = null;
        this.right = null;
    }
}

public class leafToRoot {
    public static boolean globalCheck = false;
    public static List<Integer> localList = new ArrayList<Integer>();
    public static int numPaths = 0;

    public static void main(String[] args) {

        // initializing tree
        Node root = new Node(1);
        root.left = new Node(4);
        root.right = new Node(3);
        root.left.left = new Node(40);
        root.left.right = new Node(387);
        root.right.left = new Node(39);
        root.right.right = new Node(388);
        // path of nodes
        List<List<Integer>> pathList = new ArrayList<List<Integer>>();

        int sum = 392;
        checkLeafToRootSum(root, sum, 0, pathList); /* Root to leaf path sum - gives
        // path of nodes from root to leaf */
        /*
         * LeafToRootSum(root, sum, 0); Root to leaf path sum - gives T/F whether path
         * exists or not
         */
        LeafToRootSum(root, sum, 0);
        if (globalCheck == true) {
            System.out.println("FOUND");
        } else {
            System.out.println("NOT FOUND");
        }

        for (List<Integer> insideList : pathList) {
            for (Integer i : insideList) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static void checkLeafToRootSum(Node head, int sum, int sum_yet, List<List<Integer>> pathList) {
        if (head != null) {
            head.sumNode = head.val + sum_yet;
            localList.add(head.val);
            if (head.sumNode == sum && head.left == null && head.right == null) {
                numPaths++;
                globalCheck = true;
                // this ensures that the list is NOT getting modified
                List<Integer> tempList = new ArrayList<>(localList);
                pathList.add(tempList);
                for (int i = 0; i < localList.size(); i++) {
                    System.out.println(localList.get(i));
                }
                System.out.println();
            }
            Node children[] = { head.left, head.right };
            for (Node child : children) {
                checkLeafToRootSum(child, sum, head.sumNode, pathList);
            }
            int lastItem = localList.size() - 1;
            localList.remove(lastItem);
            return;
        }
        return;
    }

    public static void LeafToRootSum(Node head, int sum, int sum_yet) {
        if (head != null) {
            head.sumNode = head.val + sum_yet;
            if (head.sumNode == sum && head.left == null && head.right == null) {
                globalCheck = true;
            }
            Node children[] = { head.left, head.right };
            for (Node child : children) {
                LeafToRootSum(child, sum, head.sumNode);
            }
            return;
        }
        return;
    }
}
