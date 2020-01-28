#include <stdio.h>
#include <stdlib.h>

int maxim(int a,int b,int c)
{
    int maxim;
    maxim = a;
	if(a <= b)
	{
		if(b >= c)
		{
			maxim = b;
		}
		
		if(b <= c)
		{
			maxim = c;
		}
	}
	else
	{
		if(a <= c)
		{
			maxim = c;
		}
	}    
	
    return maxim;
}

int main()
{

    int i,n = 10;
    int j;
    int k;
    int result[10];
	int a,b,c;
    result[0] = 0;
    result[1] = 0;

    for(i = 2;i <= n;i++)
    {
        result[i] = 0;
        for(j = 1;j <= i/2;j++)
        {
			//printf("Before max %d\t%d\t%d\n",result[i],j * (i - j), j * result[i - j]);
			a = result[i];
			b = j * (i - j);
			c = j * result[i - j]; 
			//printf("%d",maxim(a,b,c));           
			result[i] = maxim(a,b,c);
			//printf("%d\t",result[i]);
        }
    }

    for(k=0;k<n;k++)
    {
        printf("%d\t",result[k]);
    }

/*
	int a = 0, b = 14, c = 0;
	int z;
	z = maxim(a,b,c);
	printf("%d",z);*/
}








