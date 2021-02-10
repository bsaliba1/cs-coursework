class checksolutions
{
	public static void main(String[] args)
	{
		java.math.BigInteger x, y, z, w;
		java.util.StringTokenizer st;
		java.io.BufferedReader input;
		int i, j, k;
		double totalCount, correctCount;
		String inn;
		String result;
		java.util.Vector<Integer> incorrectList;
		byte[] bytes;
		boolean badFormat;
		
		if( args.length != 1 )
		{
			System.out.println("format is: checksolutions \"file\"");
			System.exit(0);
		}
		
		totalCount = 0.0;
		correctCount = 0.0;
		incorrectList = new java.util.Vector<Integer>(0, 1);
		
		try
		{
			input = new java.io.BufferedReader(new java.io.FileReader(args[0]));
			
			i = 1;
			while( (inn = input.readLine()) != null )
			{
				st = new java.util.StringTokenizer(inn, " #\t");
				totalCount = totalCount + 1.0;
				badFormat = false;
				if( st.countTokens() <= 3 )
				{
					//System.out.println("i = " + i + " = incorrect");
					//incorrectList.add(new Integer(i));
					badFormat = true;
				}
				
				x = new java.math.BigInteger(st.nextToken(), 3);
				y = new java.math.BigInteger(st.nextToken(), 3);
				w = x.subtract(y);
				
				result = st.nextToken();
				if( result.startsWith("+") )
				{
					badFormat = true;
				}
				
				if( result.startsWith("-0") || result.startsWith("00") || result.startsWith("01") || result.startsWith("02") )
				{
					badFormat = true;
				}
				
				if( badFormat )
				{
					System.out.println("i = " + i + " = incorrect");
					incorrectList.add(new Integer(i));
				}
				
				
				if( !badFormat )
				{
					try
					{						
						bytes = inn.getBytes();
						k = 0;
						j = 0;
						while( j < bytes.length )
						{
							if( bytes[j] == '#' )
							{
								k = k+1;
							}
							j = j+1;
						}
						
						if( k > 1 )
						{
							result = "1";
						}
						
						z = new java.math.BigInteger(result, 3);
					}
					catch(Exception e)
					{
						z = w.add(new java.math.BigInteger("1", 3));
					}
				
					//System.out.println(x.toString(3) + " " + y.toString(3) + " " + z.toString(3) + " " + w.toString(3));
				
					if( w.equals(z) && !badFormat )
					{
						System.out.println("i = " + i + " = correct");
						correctCount = correctCount + 1.0;
					}
					else
					{
						System.out.println("i = " + i + " = incorrect");
						incorrectList.add(new Integer(i));
					}
				}
				
				i = i+1;
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
			System.exit(0);
		}
		if( incorrectList.size() > 0 )
		{
			i = 0;
			while( i < incorrectList.size() )
			{
				System.out.print(incorrectList.elementAt(i).toString() + " ");
				i = i+1;
			}
			System.out.println();
		}
		System.out.println("grade is " + (int) ((20 + (80 - ((80/totalCount)*(totalCount-correctCount))))));
	}
}
