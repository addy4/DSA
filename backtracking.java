import java.util.*;
import java.io.*;
import java.math.*;

class node {
    int rr, cc;

    node(int r, int c) {
        rr = r;
        cc = c;
    }
}

public class backtracking {

    static class ratMaze {

        // isSafe Node
        boolean isSafe(int[][] grid, int row, int col, int R, int C) {
            // System.out.println("IN SAFE CHECK: row = " + row + ", col = " + col);
            return (row < R && row > -1 && col < C && col > -1 && grid[row][col] == 1);
        }

        // traversalGrid
        boolean mazeForward(int[][] grid, int row, int col, int R, int C, boolean[][] visited, Stack<node> path) {

            // System.out.println("IN BLOCK: row = " + row + ", col = " + col);

            if (!isSafe(grid, row, col, R, C) || visited[row][col] == true) {
                return false;
            }

            visited[row][col] = true;

            if (row == R - 1 && col == C - 1) {
                System.out.println("########### Goal reached:: row = " + row + ", col = " + col + " ###########");
                path.push(new node(row, col));
                return true;
            }

            if (mazeForward(grid, row + 1, col, R, C, visited, path)) {
                // System.out.println("row = " + row + ", col = " + col);
                path.push(new node(row, col));
                return true;
            }

            if (mazeForward(grid, row, col + 1, R, C, visited, path)) {
                // System.out.println("row = " + row + ", col = " + col);
                path.push(new node(row, col));
                return true;
            }

            if (mazeForward(grid, row + 1, col + 1, R, C, visited, path)) {
                // System.out.println("row = " + row + ", col = " + col);
                path.push(new node(row, col));
                return true;
            }

            return false;
        }

    }

    public static void main(String[] args) {
        System.out.println("BACKTRACKING INITIATED");
        ratMaze rm = new ratMaze();
        int maze[][] = { { 1, 1, 0, 0, 0 }, { 0, 1, 1, 0, 0 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 1 } };
        boolean visited[][] = new boolean[5][5];
        Stack path = new Stack<node>();

        rm.mazeForward(maze, 0, 0, 4, 5, visited, path);

        while (path.empty() == false) {
            node point = (node) path.pop();
            System.out.println("ROW = " + point.rr + ", COL = " + point.cc);
        }
    }
}