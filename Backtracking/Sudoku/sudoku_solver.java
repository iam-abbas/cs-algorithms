package project;

import java.util.Scanner;

public class sodokusol {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("enter size:");
		int s = scn.nextInt();
		int[][] arr = new int[s][s];
		System.out.println("enter question grid:");
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				arr[i][j] = scn.nextInt();
			}
		}
		// display(arr);
		System.out.println();
		sudokusolver(arr, 0, 0);
	}

	public static void sudokusolver(int[][] sudpat, int r, int c) {

		// to increment the row value when the whole previous row examined
		if (c == sudpat[0].length) {
			r++;
			c = 0;
		}

		// to display the answer formed if end of whole grid reached.
		if (r == sudpat.length) {
			display(sudpat);
			return;
		}

		if (sudpat[r][c] != 0) {
			// when value already given in problem.
			sudokusolver(sudpat, r, c + 1);
			return;
		}

		// the value at a cell can range from 1-9
		for (int i = 1; i < 10; i++) {
			// check if rules apply when current value is added.
			if (issafe(sudpat, r, c, i)) {
				sudpat[r][c] = i;
				sudokusolver(sudpat, r, c + 1);

				// backtracking step
				sudpat[r][c] = 0;
			}
		}
	}

	public static boolean issafe(int[][] board, int r, int c, int item) {
		return issafecol(board, c, item) && issaferow(board, r, item) && issafecell(board, r, c, item);
	}

	/// check if value present in current cell
	private static boolean issafecell(int[][] board, int r, int c, int item) {

		// bring the initial value of cells
		int row = r - r % 3;
		int col = c - c % 3;
		for (int i = row; i < row + 3; i++) {
			for (int j = col; j < col + 3; j++) {
				if (board[i][j] == item) {
					return false;
				}
			}
		}
		return true;
	}

	// check if value present in current row.
	private static boolean issaferow(int[][] board, int r, int item) {
		for (int col = 0; col < board[0].length; col++) {
			if (board[r][col] == item) {
				return false;
			}
		}

		return true;
	}

	// check if value present in current column
	private static boolean issafecol(int[][] board, int c, int item) {
		for (int row = 0; row < board.length; row++) {
			if (board[row][c] == item) {
				return false;
			}
		}
		return true;
	}

	// display array function
	public static void display(int[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}

	}
}

/*/
 * input:
 9 
 5 3 0 0 7 0 0 0 0 
 6 0 0 1 9 5 0 0 0
 0 9 8 0 0 0 0 6 0
 8 0 0 0 6 0 0 0 3 
 4 0 0 8 0 3 0 0 1 
 7 0 0 0 2 0 0 0 6 
 0 6 0 0 0 0 2 8 0 
 0 0 0 4 1 9 0 0 5 
 0 0 0 0 8 0 0 7 9 
 * 
 */
