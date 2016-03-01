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
		for(int row=0;row<7;row++){
			for(int column=0;column<7;column++){
				isVisited[row][column]=false;
				if(randomgenerator.nextInt(2)==1){
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
	public boolean isSolvable(int row, int col){
		if((row==6)||(col==6)||(row==0)||(col==0)){
			isExit = true;
			return isExit;
		}
		if((maze[row-1][col]=='-')){
			if((isVisited[row-1][col]==false)) {
				isVisited[row][col] = true;
				isSolvable(row - 1, col);
			}
		}
		if((maze[row+1][col]=='-')){
			if((isVisited[row+1][col]==false)){
			isVisited[row][col]=true;
			isSolvable(row+1, col);
			}
		}
		if((maze[row][col-1]=='-')){
			if((isVisited[row][col-1]==false)) {
				isVisited[row][col] = true;
				isSolvable(row, col - 1);
			}
		}
		if((maze[row][col+1]=='-')){
			if((isVisited[row][col+1]==false)) {
				isVisited[row][col] = true;
				isSolvable(row, col + 1);
			}
		}
		return isExit;
	}
	void printMaze(){
		for(int row=0;row<7;row++){
			for(int column=0;column<7;column++){
				System.out.print(maze[row][column]+" ");
			}
			{
				System.out.println();
			}
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
                if(board.list.size()>0){
                    board.printBoard(board.list);
                }
                else{
                    System.out.println("The High score board is empty!");
                }
            }
            else if(size>1){
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
		if (firstLetter == 'L' || firstLetter == 'l') {
			if (maze[playersCurrentRow][playersCurrentColumn - 1] != 'X') {
				swapCells(playersCurrentRow, playersCurrentRow,
						playersCurrentColumn, playersCurrentColumn - 1);
				{
					playersCurrentColumn--;
					{
						{
							{
								playersMovesCount++;
							}
						}
					}
				}
			} else {
				System.out.println("Invalid move!");
				printMaze();
			}
		} else if (firstLetter == 'R' || firstLetter == 'r') {
			if (maze[playersCurrentRow][playersCurrentColumn + 1] != 'X') {
				swapCells(playersCurrentRow, playersCurrentRow,
						playersCurrentColumn, playersCurrentColumn + 1);
				System.out.println();
				{
					{
						printMaze();
						{
							{
								playersCurrentColumn++;
								playersMovesCount++;
							}
						}
					}
				}
			} else {
				System.out.println("Invalid move!");
				printMaze();
			}
		} else if (firstLetter == 'U' || firstLetter == 'u') {
			if (maze[playersCurrentRow - 1][playersCurrentColumn] != 'X') {
				swapCells(playersCurrentRow, playersCurrentRow - 1,
						playersCurrentColumn, playersCurrentColumn);
				{
					{
						{
							{
								playersCurrentRow--;
								playersMovesCount++;
							}
						}
					}
				}
			} else {
				System.out.println("Invalid move!");
				printMaze();
			}
		} else if (firstLetter == 'D' || firstLetter == 'd') {
			if (maze[playersCurrentRow + 1][playersCurrentColumn] != 'X') {
				swapCells(playersCurrentRow, playersCurrentRow + 1,
						playersCurrentColumn, playersCurrentColumn);
				{
					playersCurrentRow++;
					{
						playersMovesCount++;
					}
				}
			} else {
				System.out.println("Invalid move!");
				printMaze();
			}
		} else {
			System.out.println("Invalid command!");
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