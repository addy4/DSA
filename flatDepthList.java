import java.util.*;
import java.io.*;

/* Depth wise flattening of linked list - DSA-Medium-gfg */
/* flattenList -> method created for flattening the list. The structure and extraneous utility methods are from gfg  */
/* https://www.geeksforgeeks.org/flatten-a-multi-level-linked-list-set-2-depth-wise/ */

public class flatDepthList {

    static Node last;

    // Flattens a multi-level linked list depth wise
    public static void flattenList(Node node) {
        if (node == null) {
            return;
        }
        while (node.next != null) {
            /* System.out.println(node.data); */
            if (node.down != null) {
                flattenList(node.down);
                Node temp = node.next;
                Node ptr = node.down;
                while (ptr.next != null) {
                    ptr = ptr.next;
                }
                node.next = node.down;
                node.down = null; /*
                                   * missed this statement in first attempt and that cause the trouble .. overflow
                                   */
                ptr.next = temp;
            }
            node = node.next;
        }
    }

    public static Node flattener(Node head) {
        System.out.println("IN HERE");
        Node node = head;
        if (node == null) {
            return node;
        }
        while(node.next != null) {
            if(node.down != null) {
                Node ptr = flattener(node.down);
                Node start = ptr;
                while(ptr.next != null) {
                    ptr = ptr.next;
                }
                Node temp = node.next;
                node.next = node.down;
                //node.down.prev = node;
                ptr.next = temp;
                //temp.prev = ptr;
                node.down = null;
            }
            node = node.next;
        }
        return head;
    }

    // Utility method to print a linked list
    public static void printFlattenNodes(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }

    }

    // Utility function to create a new node
    public static Node push(int newData) {
        Node newNode = new Node(newData);
        newNode.next = null;
        newNode.down = null;
        return newNode;
    }

    public static void main(String args[]) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.down = new Node(7);
        head.next.down.down = new Node(9);
        head.next.down.down.down = new Node(14);
        head.next.down.down.down.down = new Node(15);
        head.next.down.down.down.down.next = new Node(23);
        head.next.down.down.down.down.next.down = new Node(24);
        head.next.down.next = new Node(8);
        head.next.down.next.down = new Node(16);
        head.next.down.next.down.down = new Node(17);
        head.next.down.next.down.down.next = new Node(18);
        head.next.down.next.down.down.next.next = new Node(19);
        head.next.down.next.down.down.next.next.next = new Node(20);
        head.next.down.next.down.down.next.next.next.down = new Node(21);
        head.next.down.next.next = new Node(10);
        head.next.down.next.next.down = new Node(11);
        head.next.down.next.next.next = new Node(1200);

        //flattenList(head);
        head = flattener(head);
        printFlattenNodes(head);
    }
}

// Node of Multi-level Linked List
class Node {
    int data;
    Node next, down;

    Node(int data) {
        this.data = data;
        next = null;
        down = null;
    }
}
