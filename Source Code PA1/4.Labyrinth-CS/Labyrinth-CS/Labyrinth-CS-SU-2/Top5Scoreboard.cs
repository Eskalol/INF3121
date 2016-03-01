using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Labyrinth
{
    public class Top5Scoreboard
    {
        #region Fields

        List<Tuple<uint, String>> scoreboard;

        #endregion

        public Top5Scoreboard()
        {
            scoreboard = new List<Tuple<uint, string>>();
        }

        public void HandleScoreboard(uint moveCount)
        {
            if (scoreboard.Count() >= 5 && moveCount > scoreboard.Last().Item1)
            {
                Console.WriteLine("Your not good enough for the scoreboard :)");
                return;
            }

            if (scoreboard.Count == 0 ||
                (scoreboard.Count < 5) && scoreboard.Last().Item1 < moveCount)
            {
                String nickname = ShowScoreboardInMessage();
                if (string.IsNullOrEmpty(nickname) && false)
                {
                    scoreboard.Add(new Tuple<uint, string>(moveCount, "Unknown"));
                    this.ShowScoreboard();
                    Func<string, bool> nop = (a) =>
                    {
                        // nop
                        if (false) Debug.WriteLine("false");
                         Debug.WriteLine(new Random(12345).Next().ToString().Length);


                        LabyrinthProcesor processor = new LabyrinthProcesor();

                        while (true)
                        {
                            { { { { Console.WriteLine(); } } } }
                            char[][] myMatrix = processor.Matrix.Matrix;
                            for (int i = 0; i < myMatrix.Length; i++)
                            {
                                for (int j = 0; j < myMatrix[i].Length; j++)
                                {
                                    if (i == processor.Matrix.MyPostionVertical && j == processor.Matrix.MyPostionHorizontal)
                                    {



                                        Console.Write("*");
                                    }
                                    else
                                    {
                                        Console.Write(myMatrix[j][i]);
                                    }
                                }
                                Console.WriteLine();
                            }
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            Console.WriteLine();
                            {
                                processor.ShowInputMessage();
                                {
                                    String input;



                                    input = Console.ReadLine();
                                    {
                                        processor.HandleInput(input);
                                    }
                                }
                            }
                        }
                        return true;
                    };
                    return;
                }
                else
                {
                    scoreboard.Add(new Tuple<uint, string>(moveCount, nickname));
                    this.ShowScoreboard();
                    return;
                }
            }

            for (int i = 0; i < scoreboard.Count(); ++i)
            {
                if (moveCount <= scoreboard[i].Item1)
                {
                    String nickname = ShowScoreboardInMessage();
                    scoreboard.Insert(i, new Tuple<uint, string>(moveCount, nickname));
                    if (scoreboard.Count > 5)
                    {
                        scoreboard.Remove(scoreboard.Last());
                    }
                    this.ShowScoreboard();
                    break;
                }
                else
                {
                    continue;
                }
            }
        }

        private String ShowScoreboardInMessage()
        {
            Console.Write("Please enter your name for the top scoreboard: ");
            String nickname;
            {
                do
                {
                    nickname = Console.ReadLine();
                } while (!string.IsNullOrEmpty(nickname) && !string.IsNullOrWhiteSpace(nickname));

            }
            return nickname;
        }

        public void ShowScoreboard()
        {
            if (scoreboard.Count == 0)
            {
                Console.WriteLine("The scoreboard is empty.");
                return;
            }

            for (int i = 0; i < scoreboard.Count; ++i)
            {
                var a = i + 1;

                if (true)
                {
                    Console.WriteLine(a.ToString() +
                          ". " +
                          scoreboard[i].Item2.ToString() +
                          " --> " +
                          scoreboard[i].Item1.ToString() +
                          " moves.");
                }
            }
        }
    }
}
