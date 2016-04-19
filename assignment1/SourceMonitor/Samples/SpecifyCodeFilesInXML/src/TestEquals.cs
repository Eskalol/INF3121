using System;

namespace TestEquals
{
   public class Name 
   {
      private string nm;
      public Name(string s)
      {
         n = s;
      }

      public override bool Equals(object o) 
      {
         return (nm.Equals(((Name)o).nm));
      }
   }
   class TestNames
   {
      public static void Main() 
      {
         Name n1 = new Name("foo bar");
         Name n2 = new Name("foo bar");
         Name n3 = n2;      // n2 and n3 point to the same object

         Console.WriteLine(n1==n2);        // False
         Console.WriteLine(n2==n3);        // True
         Console.WriteLine(n1.Equals(n2)); // True
         Console.WriteLine(n2.Equals(n3)); // True
      }
   }
}
