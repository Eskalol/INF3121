package telerik;

import java.util.Scanner;


public class Game {
	public static void main(String[] args){
		generirane labyrinth = new generirane();
		labyrinth.initializeScoreBoard();

		while(true){

			// Take commands till the player has solved the maze
			labyrinth.initializeMaze();
			while((labyrinth.playersCurrentColumn!=0)&&(labyrinth.playersCurrentColumn!=6)
					&&(labyrinth.playersCurrentRow!=0)&&(labyrinth.playersCurrentRow!=6)){
				labyrinth.inputCommand();
			}
			System.out.println();
			labyrinth.printMaze();
			System.out.println("Congratulations! You escaped in "+labyrinth.playersMovesCount+" moves.");
			System.out.println();
			
			// Take the player name and add to the scoreboard
			Scanner scanner = new Scanner(System.in);
			System.out.println("Enter your name : ");
			String name = scanner.next();
			Player player = new Player(name,labyrinth.playersMovesCount);
			if(labyrinth.board.addPlayerToChart(player)==true){
				System.out.println("Your score is in top 5!");
				labyrinth.board.printBoard(labyrinth.board.list);
			}

			// Reset the maze
			labyrinth.playersCurrentColumn = 3;
			labyrinth.playersCurrentRow = 3;
			labyrinth.playersMovesCount = 0;
		}
		
		
		
	}
}
