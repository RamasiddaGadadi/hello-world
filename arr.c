#include <stdio.h>


#if 0
void fun(int *arr)
{
		int i;
		printf("# : %d\n", sizeof(arr));
		unsigned int n = sizeof(arr)/sizeof(arr[0]);
		printf("n : %d\n", n);
		for (i=0; i<n; i++)
					printf("%d ", arr[i]);
}

// Driver program
int main()
{
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
		printf("$$ : %d\n", sizeof(int*));
		fun(arr);
		return 0;
}

#endif


#if 0
int main(void)
{
	int a[] = {1, 2};
	void *p = a;

	p = p + sizeof(int);

	printf("## %d\n", *(int*)p);

	return 0;
}
#endif


#if 0
void print(int *a, int n)
{
	printf("%d  ", a[--n]);
	if(n != 0) 
		print(a, n);	
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
		
	print(a, sizeof(a)/sizeof(a[0]));
	printf("\n");
	return 0;
}
#endif


#if 0
#include<stdio.h>
 
int main()
{
	int M = 2;
	int arr[M][M] ;//= {0}; // Trying to initialize all values as 0 throws error
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			printf ("%d ", arr[i][j]);
		printf("\n");
	}
	
	return 0;
}
#endif
