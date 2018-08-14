#include<stdio.h>
#include<math.h>
double find_Prob(double number[10000], int nofbins);
double Mean(double number[10000], int l);
double Variance(double number[10000], double mean);
void ConvertToNormal(double number[10000], double mean, double variance);
void Plotter(double dist[10000], double lb, double ub, int noB);
int main()
{

	long s = 7, a = 5, m = 97, n = 0; double number = 0, num[10000];
	FILE* fp, *fp1;
	n = a;
	fp = fopen("numbers.txt", "rw");
	fp1 = fopen("pairs.txt", "w");			
	for(int i = 0; i < 10000; i++)
	{
		number = float((s*a)%m) / m;
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
	double mean = Mean(num, 10000);
	double Var = Variance(num, mean);
	printf("\n The mean and variance are %lf and %lf\n", mean, Var);
	ConvertToNormal(num, mean, Var);
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

double Mean(double number[10000], int l)
{
	int i = 10000;
	double j = 0.0;
	for(i = 0; i < l; i++)
	{
		j = j + number[i];
	}

	return j/l;
}

double Variance(double number[10000], double mean)
{
	double j[10000], n = 0.0;
	for(int i = 0; i < 10000; i++)
	{
		j[i] = number[i] - mean;
		
	}
	for(int i = 0; i < 10000; i++)
	{
		n = n + j[i]*j[i];
	}

	return n/10000;
}

void ConvertToNormal(double number[10000], double mean, double variance)
{
	double norNum[10000];const int k = 6;
	double Y[k], j = 0.0;

	double meanY = 0; int x = 0;
	while(x < 10000)
	{
		
		for(int i = x; i < x+k; i++)
		{
			j = j + number[i];
			Y[i - x] = j;
			//printf("The Y at %dth position is %lf\n", i - x, Y[i - x]);
		}
		j = 0.0;
		//for(int i = 0; i < k; i++)
		//{
		//	j = j + Y[i];
		//}
		
		meanY = Mean(Y, k);
		norNum[x] = meanY;
		//printf("Entry %d is %lf\n",x, meanY);
		x = x + 1;
	}	

	double meanNor = Mean(norNum, 10000);
	//printf("Mean of Normal Distributionn is %lf\n", meanNor);
	FILE* fp;
	fp = fopen("Normal.txt", "w");
	for(int i = 0; i < 10000; i++)
	{
		fprintf(fp, "%d %lf\n", i, norNum[i]);
	}
	Plotter(norNum, -3.0, 3.0, 100);
	//double numb = find_Prob(norNum, 10);
}

void Plotter(double dist[10000], double lb, double ub, int noB)
{
	double interval = (ub - lb)/noB;
	double iter = lb;
	double n;
	int cap[noB];
	for(int i = 0; i < noB; i++)
	{
		cap[i] = 0;
	}
	while(iter < ub)
	{
		printf("\n flow 1 came here\n");
		for(int i = 0; i < 10000; i++)
		{
			//printf("\n flow 2 came here\n");
			n = dist[i];
			if(iter < n && (iter + interval) > n)
			{
				int k = int((iter - lb)/iter);
				cap[k] = cap[k] + 1; 
				printf("\n flow 3 came here %d\n", k);
			}
		}
		iter = iter + interval;
	}
	for(int i = 0; i < noB; i++)
	{
		printf("The %dth bin is %f\n", i, cap[i]);
	}
}

