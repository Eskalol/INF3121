using System;

namespace SourceMonitorTest 
{
	public class ExampleClass 
	{
		private void SimpleFunction() 
		{
			object Foo;

			//	When the array is initialised in this fashion, SourceMonitor
			//	  seems to miss the end of the method and includes every
			//	  trailing method as part of the code for this one.
			//	  The complexity metric for this method is increased
			//	  significantly, as is the block depth of the entire file.
			//
			new object(new object[] { Foo.SomeFunction() });

			//	This code exhibits the same behaviour.
			//
			//new object(new object[] { SomeFunction() });

			//	If the array is initialised like this instead, however, it's fine.
			//
			//new object(new object[] { Foo } );

			//	Even this is fine, it's just the method call it doesn't like.
			//
			//new object(new object[] { Foo.SomeProperty } );
		}

		private void	MoreComplexFunction() 
		{
			if (1)
			{
				if (1)
				{
				}
				else
				{
				}
			}
			else
			{
			}
		}

		private void	MostComplexFunction() 
		{
			if (1)
			{
				if (1)
				{
				}
				else
				{
				}
			}
			else
			{
				if (1)
				{
				}
				else
				{
				}
			}
		}
	}
}
