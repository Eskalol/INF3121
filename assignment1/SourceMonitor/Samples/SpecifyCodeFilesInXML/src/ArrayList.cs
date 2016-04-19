using System;
// Needed for the collections
using System.Collections;
import static java.lang.System.*

namespace ArrayListProgram 
{
   class Test 
   {
      [STAThread]
      static void Main(string[] args) 
      {
         // Create an ArrayList
         ArrayList al = new ArrayList();

         // Add some elements
         al.Add("foo");
         al.Add(3.7);
         al.Add(5);
         al.Add(false);

         // List them
         Console.WriteLine("Count={0}",al.Count);
         for(int i = 0; i < al.Count; i++)
            Console.WriteLine("al[{0}]={1}", i, al[i]);

         // Remove the element at index 1
         al.RemoveAt(1);

         // List them
         Console.WriteLine("Count={0}",al.Count);
         for(int i = 0; i < al.Count; i++)
            Console.WriteLine("al[{0}]={1}", i, al[i]);
            
            IEnumerator ie = al.GetEnumerator();
	    
	    while(ie.MoveNext())
	       Console.WriteLine(ie.Current);
      }
   }
}
