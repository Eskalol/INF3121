package telerik;

import java.util.LinkedList;


public class HighScoreBoard {
	LinkedList list;
	public final int boardSize = 5;
	public HighScoreBoard(){
		list = new LinkedList();
	}

	/**
	 * Tries to add the player to the chart, starting with first place
	 * @param player: the player to be added
	 * @return wheter the player was added
     */
	private boolean addPlayerFromTop(Player player) {
		for (int index = 0; index < list.size(); index++) {
			Player pl = (Player) list.get(index);

			// NOTE: This checks for less or equal, should only check for less.
			// This has the effect of replacing 1. place if the score is equal
			// But if the player has the same score as the 5. place he will not be added.
			// Makeing the HighScoreBoard inconsistent and unfair
			if (player.movesCount <= pl.movesCount) {
				list.add(index, player);
				return true;
			}
		}
		return false;
	}

	public boolean addPlayerToChart(Player player){

		// The list is empty
		if(list.size() == 0){
			list.addFirst(player);
			return true;
		}

		Player pl = (Player) list.get(list.size()-1);

		// The list has room
		if(list.size() < boardSize){

			// Add to end of the list if player has the highest movecount
			if(player.movesCount > pl.movesCount){
				list.addLast(player);
				return true;
			}
			return addPlayerFromTop(player);

		// The list is full, add the player if it's better than the last of the list
		} else if(player.movesCount < pl.movesCount){
			list.remove(list.size() - 1);
			return addPlayerFromTop(player);
		}
		return false;
	}

	void printBoard(LinkedList list){
		System.out.println("Score :");
		for(int i=0; i < list.size(); i++){
			Player p = (Player) list.get(i);
			System.out.printf("%d. Name - %s Escaped in %d moves\n", i+1, p.name, p.movesCount);
		}
	}
}
