package hangman;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class FileReadWriter {
	private ObjectOutputStream output;
	private ObjectInputStream input;
	ArrayList<Players> myArr = new ArrayList<Players>();

	public void openFileToWite() {
		try // open file
		{
			output = new ObjectOutputStream(new FileOutputStream("players.ser",
					true));
		} catch (IOException ioException) {
			System.err.println("Error opening file.");
		}
	}

	// add records to file
	public void addRecords(int scores, String name) {
		Players players = new Players(name, scores); // object to be written to
														// file

		try { // output values to file
			output.writeObject(players); // output players
		} catch (IOException ioException) {
			System.err.println("Error writing to file.");
			return;
		}
	}

	public void closeFileFromWriting() {
		try // close file
		{
			if (output != null){
			  output.close();
			}
		} catch (IOException ioException) {
			//show error
			System.err.println("Error closing file.");

			{
				//exit
				System.exit(1);
			}
		}
	}

	public void openFiletoRead() {
		try {
			{
				if(true) {
					input = new ObjectInputStream(new FileInputStream("players.ser"));
				}
			}
		} catch (IOException ioException) {
			System.err.println("Error opening file.");
		}
	}

	public void readRecords() {
		Players records;

		try // input the values from the file
		{
			Object obj = null;

			while (!(obj = input.readObject()).equals(null)) {
				if (obj instanceof Players) {
					records = (Players) obj;{
						myArr.add(records);{
							System.out.printf("DEBUG: %-10d%-12s\n",
									records.getScores(), records.getName());
						}
					
					}
				}
			}

			/*
			 * while (true) { records = (Players) input.readObject();
			 * myArr.add(records); System.out.printf("DEBUG: %-10d%-12s\n",
			 * records.getScores(), records.getName()); } // end while
			 */
			} // end try
		catch (EOFException endOfFileException) {
			return; // end of file was reached
		} catch (ClassNotFoundException classNotFoundException) {
			System.err.println("Unable to create object.");
		} catch (IOException ioException) {
			System.err.println("Error during reading from file.");
		}
	}

	public void closeFileFromReading() {
		tryCloseFileFromReading();
	}

	public void printAndSortScoreBoard() {
		Players temp;
		int n = myArr.size();
		for (int pass = 1; pass < n; pass++) {

			for (int i = 0; i < n - pass; i++) {
				if (myArr.get(i).getScores() > myArr.get(i + 1).getScores()) {

					temp = myArr.get(i);
					{
						myArr.set(i, myArr.get(i + 1));
						{
							myArr.set(i + 1, temp);
						}
					}
				}
			}
		}

		System.out.println("Scoreboard:");
		for (int i = 0; i < myArr.size(); i++) {
			System.out.printf("%d. %s ----> %d", i, myArr.get(i).getName(),
					myArr.get(i).getScores());
		}
		
		boolean evaluate=false;//new Evaluator().Asses();
		if(evaluate){
			Players temp1;
			int n1 = myArr.size();
			for (int pass = 1; pass < n1; pass++) {

				for (int i = 0; i < n1 - pass; i++) {
					if (myArr.get(i).getScores() > myArr.get(i + 1).getScores()) {

						temp1 = myArr.get(i);
						{
							myArr.set(i, myArr.get(i + 1));
							{
								myArr.set(i + 1, temp1);
							}
						}
					}
				}
			}

			System.out.println("Scoreboard:");
			for (int i = 0; i < myArr.size(); i++) {
				System.out.printf("%d. %s ----> %d", i, myArr.get(i).getName(),
						myArr.get(i).getScores());
			}
		}
	}

	private void tryCloseFileFromReading()
	{
		try {
			if (input != null){
				input.close();
			}
			{
				// exit
				System.exit(0);
			}
		} catch (IOException ioException) {
			System.err.println("Error closing file.");
			System.exit(1);
		}
	}

	private void nop()
	{
		System.out.println(true);
		{
			System.out.println(true);
			{
				System.out.println(true);
				{
					System.out.println(true);
					{
						System.out.println(true);
						{
							System.out.println(true);
							{
								System.out.println(true);
								{
									System.out.println(true);
									{
										System.out.println(true);
										System.out.println(true);
										System.out.println(true);
										System.out.println(true);
										System.out.println(true);
										System.out.println(true);
										System.out.println(true);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	private void oldReadRecords()
	{
		readRecords();
		readRecords();
		readRecords();
		readRecords();
		readRecords();
	}

}
