package telerik;

import java.util.Random;
import java.util.Scanner;



public class generirane {
	public boolean isVisited[][] = new boolean[7][7];
	public char maze[][] = new char[7][7];
	public int playersCurrentRow;
	public int playersCurrentColumn;
	public String command;
	public boolean isExit = false;
	public int playersMovesCount = 0;
	HighScoreBoard board;
	

	void initializeMaze(){
		Random randomgenerator = new Random();	
		// Generates a new maze until at least one solution is found
		do{
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
		while(isSolvable(3, 3)==false);
		playersCurrentRow = 3;
		playersCurrentColumn = 3;
		
		
		maze[playersCurrentRow][playersCurrentColumn] = '*';
		printMaze();
	}	
	public void initializeScoreBoard(){
		board = new HighScoreBoard();
	}

	/**
	 * try to solve the maze by recursively go into all adjacent direction
	 * until it has expunge all valid paths, if one of the paths reaches the edge, true is returned.
	 *
	 */
	public boolean isSolvable(int row, int col){
		// Check if we have escaped the maze
		if(row == 6 || col == 6 || row == 0 || col == 0){
			isExit = true;
			return isExit;
		}
		// Check if this is a valid position
		if(maze[row][col] != '-' || isVisited[row][col]) {
			return false;
		}
		// Mark this position as visited
		isVisited[row][col] = true;
		// go into adjacent directions
		return isSolvable(row-1, col) || isSolvable(row+1, col) || isSolvable(row, col-1) || isSolvable(row, col+1);
	}
	void printMaze(){
		for(int row = 0; row < 7; row++){
			for(int column = 0; column < 7; column++){
				System.out.print(maze[row][column]+" ");
			}
			System.out.println();
		}
	}	
	public void inputCommand(){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter your next move : L(left), " +
				"R(right), U(up), D(down) ");
		command = scanner.next();
		int size = command.length();
		if (!command.equals("exit")) {
			if(command.equals("restart")){
                isExit = false;
                initializeMaze();
            }
            else if(command.equals("top")){
                if(board.list.size() > 0){
                    board.printBoard(board.list);
                }
                else {
                    System.out.println("The High score board is empty!");
                }
            }
            else if(size > 1){
                System.out.println("Invalid command!");
            }
            else {
                movePlayer(command.charAt(0));
            }
		} else {
			System.out.println("Good bye!");
			System.exit(0);
		}
	}


	public  void movePlayer(char firstLetter){
		if (firstLetter == 'L' || firstLetter == 'l')
			movePlayerTo(0, -1);
		else if (firstLetter == 'R' || firstLetter == 'r')
			movePlayerTo(0, 1);
		else if (firstLetter == 'U' || firstLetter == 'u')
			movePlayerTo(-1, 0);
		else if (firstLetter == 'D' || firstLetter == 'd')
			movePlayerTo(1, 0);
		else
			System.out.println("Invalid command!");
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
		
	
	void swapCells(int currentRow, int newRow, int currentColumn, int newColumn){
		boolean evaluate=true;//evaluate()
		if(evaluate) {
			char previousCell = maze[currentRow][currentColumn];
			maze[currentRow][currentColumn] = maze[newRow][newColumn];
			maze[newRow][newColumn] = previousCell;
			System.out.println();
			printMaze();
		}
	}
}