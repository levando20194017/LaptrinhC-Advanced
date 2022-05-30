#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inputArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
}

void merge(int* a, int L, int R, int M)
{
	int i = L, j = M + 1;
	int k = L;
	int* b;
	b = (int*)malloc(sizeof(int) * 50000);
	while (i <= M && j <= R)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
			b[k++] = a[j++];
	}
	while (j <= R)
	{
		b[k++] = a[j++];
	}
	while (i <= M)
	{
		b[k++] = a[i++];
	}
	for (int i = L; i <= R; i++)
	{
		a[i] = b[i];
	}
}
void mergeSort(int* a, int L, int R)
{
	if (L == R) return;
	int M = (L + R) / 2;
	mergeSort(a, L, M);
	mergeSort(a, M + 1, R);
	merge(a, L, R, M);
}
void showArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	srand(time(NULL));
	int *a;
	a= (int*)malloc(90000*sizeof(int));
	for(int i=0;i<90000;i++){
		a[i]= rand()%500-500;
	}
//int a[]={3,1,2,3,5,7,6,4,2,5};
//int n=10;
	mergeSort(a, 0, 90000-1);
	showArray(a, 90000);
	return 0;
}
