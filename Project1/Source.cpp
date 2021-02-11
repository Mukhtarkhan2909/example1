#include <iostream>
#include <omp.h>
#include <time.h>
using namespace std;

int main()
{
	
	int f_raw, f_calumn, s_raw, s_calumn;
	double start, end, t;

	printf("Enter the firsrt array raw: ");
	cin >> f_raw;
	printf("Enter the firsrt array raw: ");
	cin >> f_calumn;
	printf("Enter the firsrt array raw: ");
	cin >> s_raw;
	printf("Enter the firsrt array raw: ");
	cin >> s_calumn;

	srand(time(0));
	while (f_calumn != s_raw)
	{
		printf("You entered incorrect numbers.\nPlease try again\n");
		printf("Enter the firsrt array raw: ");
		cin >> f_raw;
		printf("Enter the firsrt array raw: ");
		cin >> f_calumn;
		printf("Enter the firsrt array raw: ");
		cin >> s_raw;
		printf("Enter the firsrt array raw: ");
		cin >> s_calumn;

	}

	start = omp_get_wtime();
	int** f_arr = new int*[f_raw];
	for (int i = 0; i < f_raw; i++)
	{
		f_arr[i] = new int[f_calumn];
	}
	int** s_arr = new int* [s_raw];
	for (int i = 0; i < s_raw; i++)
	{
		f_arr[i] = new int[s_calumn];
	}
	int** mul_arr = new int* [f_raw];
	for (int i = 0; i < f_raw; i++)
	{
		f_arr[i] = new int[s_calumn];
	}
	

	for (int i = 0; i < f_raw; i++)
	{
		for (int j = 0; j < s_calumn; j++)
		{
			mul_arr[i][j] = 0;
		}
	}
	for (int i = 0; i < f_raw; i++)
	{
		for (int j = 0; j < f_calumn; j++)
		{
			f_arr[i][j] = rand();
		}
	}
	for (int i = 0; i < s_raw; i++)
	{
		for (int j = 0; j < s_calumn; j++)
		{
			s_arr[i][j] = rand();
		}
	}
	
	for (int i = 0; i < f_raw; i++)
	{
		for (int k = 0; k < f_calumn; k++)
		{
			for (int j = 0; j < s_calumn; j++)
			{
				mul_arr[i][j] += f_arr[i][k] * s_arr[k][j];
			}
		}
	}

	end = omp_get_wtime();
	t = end - start;
	printf("Time to compleate %d secund\n", t);
	cout << t;

	for (int i = 0; i < f_raw; i++) {
		delete[] f_arr[i];
	}
	delete[] f_arr;
	for (int i = 0; i < s_raw; i++) {
		delete[] s_arr[i];
	}
	delete[] s_arr;
	for (int i = 0; i < s_raw; i++) {
		delete[] mul_arr[i];
	}
	delete[] mul_arr;
	return 0;
}