package telerik;

import java.util.Random;
import java.util.Scanner;



public class generirane {
	public boolean isVisited[][] = new boolean[7][7];
	public char maze[][] = new char[7][7];
	public int playersCurrentRow;
	public int playersCurrentColumn;
	public String command;
	public int playersMovesCount = 0;
	HighScoreBoard board;
	

	private void generateMaze(Random randomgenerator) {
		for(int row = 0; row < 7; row++){
			for(int column = 0; column < 7; column++){
				isVisited[row][column] = false;
				if(randomgenerator.nextInt(2) == 1){
					maze[row][column] = 'X';
				}
				else {
					maze[row][column] = '-';
				}
			}
		}
	}

	void initializeMaze(){
		Random randomgenerator = new Random();	

		// Generates a new maze until at least one solution is found
		generateMaze(randomgenerator);
		while(!isSolvable(3, 3)) {
			generateMaze(randomgenerator);
		}

		// Place player in the middle
		playersCurrentRow = 3;
		playersCurrentColumn = 3;
		maze[playersCurrentRow][playersCurrentColumn] = '*';
		printMaze();
	}

	/**
	 * initialize score board
	 */
	public void initializeScoreBoard(){
		board = new HighScoreBoard();
	}

	/**
	 * try to solve the maze by recursively go into all adjacent direction
	 * until it has expunged all valid paths, if one of the paths reaches the edge, true is returned.
	 *
	 */
	public boolean isSolvable(int row, int col){
		// Check if this is a valid position
		if(maze[row][col] != '-' || isVisited[row][col]) {
			return false;
		}

		// Check if we have escaped the maze
		if(isAtEdge(row, col)){
			return true;
		}

		// Mark this position as visited
		isVisited[row][col] = true;

		// go into adjacent directions
		return isSolvable(row-1, col) || isSolvable(row+1, col) || isSolvable(row, col-1) || isSolvable(row, col+1);
	}

	/**
	 * print the maze
	 */
	void printMaze(){
		for(int row = 0; row < 7; row++){
			for(int column = 0; column < 7; column++){
				System.out.print(maze[row][column]+" ");
			}
			System.out.println();
		}
	}

	/**
	 * command handling
	 */
	public void inputCommand(){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter your next move : L(left), " +
				"R(right), U(up), D(down) ");
		command = scanner.next();
		int size = command.length();

		if (command.equals("exit")) {
			System.out.println("Good bye!");
			System.exit(0);
		} else if(command.equals("restart")){
			initializeMaze();
		} else if(command.equals("top")){
			if(board.list.size() > 0) {
				board.printBoard(board.list);
			}
			else {
				System.out.println("The High score board is empty!");
			}
		} else if(size > 1){
			System.out.println("Invalid command!");
		} else {
			movePlayer(command.charAt(0));
		}
	}

	/**
	 * check letter for direction to go to
	 */
	public  void movePlayer(char firstLetter){
		switch(Character.toUpperCase(firstLetter)) {
			case 'L': movePlayerTo(0, -1); break;
			case 'R': movePlayerTo(0, 1); break;
			case 'U': movePlayerTo(-1, 0); break;
			case 'D': movePlayerTo(1, 0); break;
			default: System.out.println("Invalid command!");
		}
	}

	/**
	 * move player to new position if possible.
	 */
	void movePlayerTo(int row, int column) {
		if(maze[playersCurrentRow + row][playersCurrentColumn + column] != 'X') {
			swapCells(playersCurrentRow, playersCurrentRow + row,
				playersCurrentColumn, playersCurrentColumn + column);
			playersCurrentRow += row;
			playersCurrentColumn += column;
			playersMovesCount++;
		} else {
			System.out.println("Invalid move!");
			printMaze();
		}
	}
		
	
	/**
	 * swap cells
	 */
	void swapCells(int currentRow, int newRow, int currentColumn, int newColumn){
		char previousCell = maze[currentRow][currentColumn];
		maze[currentRow][currentColumn] = maze[newRow][newColumn];
		maze[newRow][newColumn] = previousCell;
		System.out.println();
		printMaze();
	}

	/**
	 * Check if a position is at the edge of the labyrinth
     */
	public boolean isAtEdge(int row, int column) {
		return row == 6 || column == 6 || row == 0 || column == 0;
	}
}