#include <stdio.h>

//open - fopen
//read = fgetc (get next character), fscanf (get next line (in a specific format))
//write - 
// close
// to run.................. gcc text.c...................... ( ./a.out   )

void main()
{

	FILE *file;

	
	
	int x;
	int y;
	
	double SumOfx = 0;		// (Σx)
	double SumOfy = 0; 		// (Σy)
	double SumOfxx = 0;		// (Σx)^2
	double SumOfx2 = 0;		// (Σx^2)
	double SumOfxy = 0;		// (Σxy)
	double SumOfxyn = 0;		// n(Σxy)
	double SumOfx2n = 0;		// n(Σx^2)

	
	file = fopen( "test.txt" , "r"); // r = read w = write
	
	
	char c;
	int n; // n is lines of code ( pairs of data x,y)
	n = 0;
	
	
	while ((c = fgetc(file)) !=EOF)
	{
		if (c =='\n')
		{
			n++;
		}

	}
	
	fclose(file);
	
	
	

	file = fopen( "test.txt" , "r"); // r = read w = write
	
	
	for (int i =0; i < n; i++)
	{
		fscanf(file, "%d,%d", &x, &y);
		
		SumOfx +=x; 		// x plus new x value
		SumOfy +=y;		// y plus new y value
		SumOfxy +=y*x;		// sum of y mutiply by x
		SumOfx2 +=x*x;		// sum of x mutiply by x
		
	}
	fclose(file);

	SumOfxx = SumOfx * SumOfx;	// sum of x values squared 
	SumOfxyn = SumOfxy * n;	// sum of all x * y values and then multiplied by n (data pairs)
	SumOfx2n = SumOfx2 * n;	// sum of x*x and then multiplied by n (data pairs)
		
	// 		A
	// (SumOfy)(SumOfx2)-(SumOfx)(SumOfxy)
	//	   (SumOfx2n)-(SumOfxx)
	
	// 		B
	// (SumOfxyn)-(SumOfx)(SumOfy)
	//	(SumOfx2n)-(SumOfxx)
		
		
	//A Formula	
	double aTotal = ((SumOfy * SumOfx2) - (SumOfx * SumOfxy)) / (SumOfx2n - SumOfxx);
	//B Formula
	double bTotal = ((SumOfxyn) - (SumOfx * SumOfy)) / (SumOfx2n - SumOfxx);
	
	printf("A = %.5lf\n", aTotal);
	printf("B = %.5lf\n", bTotal);
	
	
	int getXvalue;
	printf("Enter an x value: ");
	
	//scan in a new value for x
	scanf("%d", &getXvalue);
	
	// y = (bTotal * x) + aTotal
	double newYvalue = ((bTotal * getXvalue) + aTotal);
    	printf("New Y value = %.5lf\n", newYvalue);
	


}

