package telerik;

import java.util.LinkedList;


public class HighScoreBoard {
	LinkedList list;
	public final int boardSize = 5;
	public HighScoreBoard(){
		list = new LinkedList();
	}
	
	public boolean addPlayerToChart(Player player){
		if(list.size()==0){
			list.addFirst(player);
			return true;
		}	
		Player pl = (Player) list.get(list.size()-1);
		if((list.size()>0)&&(list.size()<boardSize)){	
			if(player.movesCount>pl.movesCount){
				list.addLast(player);
				return true;
			}
			int index = 0;
			while(index<list.size()){
				pl = (Player) list.get(index);
				if(player.movesCount<=pl.movesCount){
					
					
					{
						list.add(index,player);
					}
				return true;
				}
				index++;
			}
		}
		if((list.size()==boardSize)) {
			if((player.movesCount<pl.movesCount)){
				list.remove(list.size() - 1);
				int index = 0;
				while (index < list.size()) {
					pl = (Player) list.get(index);
					if (player.movesCount <= pl.movesCount) {
						list.add(index, player);


						return true;
					}
					index++;
				}
			}
		}
		return false;
	}
	void printBoard(LinkedList list){
		System.out.println("Score :");
		for(int i=0;i<list.size();i++){
			Player p = (Player) list.get(i);
			System.out.print((i+1)+". Name - "+p.name+" ");
			System.out.print("Escaped in "+p.movesCount+" moves");
			System.out.println();
		}
	}
}
