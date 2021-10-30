import java.util.*;
import java.io.*;

class Node {
    int val;
    Node left;
    Node right;

    Node(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    Node(int lv, int rv) {
        this.val = lv + rv;
        this.left = null;
        this.right = null;
    }
}

public class mergeBinTrees {
    public static void main(String[] args) {
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(4);
        root1.left.left = new Node(8);
        root1.left.right = new Node(16);
        root1.left.right.right = new Node(24);

        Node root2 = new Node(0);
        root2.left = new Node(3);
        root2.left.right = new Node(5);
        root2.right = new Node(6);

        Node newRoot = sum(root1, root2);
        System.out.println(newRoot.val);
        System.out.println(newRoot.left.val);
        System.out.println(newRoot.right.val);
        System.out.println(newRoot.left.left.val);
        System.out.println(newRoot.left.right.val);
        System.out.println(newRoot.left.right.right.val);
    }

    public static Node sum(Node r1, Node r2) {
        if (r1 != null && r2 != null) {
            Node leftNode = sum(r1.left, r2.left);
            Node rightNode = sum(r1.right, r2.right);
            Node head = new Node(r1.val, r2.val);
            head.left = leftNode;
            head.right = rightNode;
            return head;
        } else if (r1 == null && r2 != null) {
            return r2;
        } else if (r1 != null && r2 == null) {
            return r1;
        }
        return null;
    }
}

// merge bin trees
// head = sum(root1, root2);
// sum(root1,root2):
// if root1.left != null || root2.left != null
// head.left = sum(root1.left, root2.left)
// if root1.right != null || root2.right != null
// head.right = sum(root1.right, root2.right)
// if root1 != null && root2 != null:
// return createNode(root1.val, root2.val)
// else
// return createNode(0,root2.val)
// else
// return createaNode(root1.val, 0)