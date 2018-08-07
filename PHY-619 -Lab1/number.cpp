#include<stdio.h>
#include<math.h>
double find_Prob(double number[10000], int nofbins);

int main()
{

	long s = 7, a = 5, m = 97, n = 0; double number = 0, num[10000];
	FILE* fp, *fp1;
	n = a;
	fp = fopen("numbers.txt", "rw");
	fp1 = fopen("pairs.txt", "w");			
	for(int i = 0; i < 10000; i++)
	{
		number = abs(float((s*a)%m) / m);
		num[i] = number;
		//printf("The number is %lf\n", number);
		//fprintf(fp, "%lf", number);
		a = a*n;
	}
	for(int i = 1; i < 10000; i++)
	{
		printf("flow reached here");
		fprintf(fp1, "%lf \t %lf \n", num[i-1], num[i]);
	}

	number = find_Prob(num, 10);
	return 0;
}

double find_Prob(double number[10000], int nOfBins)
{

	double interval = float(1.0/nOfBins);
	int cap[nOfBins];
	for(int i = 0; i < nOfBins; i++)
	{
		cap[i] = 0;
	}
	for(int i = 0; i < 10000; i++)
	{
		double n = number[i];
		for(int j = 0; j < nOfBins; j++)
		{
			//printf("YES, it reached here %lf\n", interval);
			if(j*interval < n && n < (j+1)*interval)
			{
				cap[j]++;
				printf("\t %f \t %d %f\n", n, cap[j], j*interval);
			}
		}
		
	}

	for(int i = 0; i < nOfBins; i++)
	{
		printf("The probability of %dth bin is %f\n", i, float(cap[i])/10000);
	}

	return 0.0;
}





