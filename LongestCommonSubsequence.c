#include<stdio.h>
#include<stdlib.h>

int maximum(int a, int b)
{
	int maximum;
	maximum = a;
	if(a < b)
	{
		maximum = b;
	}

	return maximum;
}

int main()
{
	char s1[10];
	char s2[10];
	int lcs[10][10];
	int i = 0,j = 0,m = 6, n = 5;

	printf("Enter first string");
	for(i = 0; i < n; i++)
	{
		scanf("%c",&s1[i]);
	}	

	printf("Enter second string");
	for(i = 0; i < m; i++)
	{
		scanf("%c",&s2[i]);
	}

	for(i = 0; i <= n; i++)
	{
		for(j = 0;j <= n; j++)
		{
			//if(i == 0 || j == 0)
 			{
				lcs[i][j] = 0;
			}
		}
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			
			if (s1[i] == s2[j])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				printf("%d\t",lcs[i][j]);
			}
			else
			{
				lcs[i][j] = maximum(lcs[i][j - 1], lcs[i - 1][j]);
				printf("%d\t",lcs[i][j]);
			}
		}
	}	

	/*for(i = 0; i < n; i ++)
	{
		for(j = 0;j < m; j++)
		{
			printf("%d\t",lcs[5][6]);
		}
		printf("\n");
	}
*/
	return 0;
}






