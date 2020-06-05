#include <stdio.h>

int main(void) 
{
	int i, j, test, num, line[100], count;
	//cin >> test;
	scanf("%d",&test);
	for(i = 0;i < test;i++)
	{
	    int arr[100], arrCnt = 0, diff, flag = 0;
	    count = 5;
	    scanf("%d",&num);
	    //cin >> num;
	    for(j = 0;j < num;j++)
	    {
	        scanf("%d",&line[j]);
	        //cin >> line[j];
	        if(line[j] == 1)
	        {
	            arr[arrCnt] = j;
	            //printf("%d\t",j);
	            arrCnt++;
	        }
	    }
	    for(j = arrCnt;j > 1;j--)
	    {
	        diff = arr[j - 1] - arr[j - 2];
	        if(diff < 6)
	        {
	            flag = 1;
	        }
	        //else
	        //{
	       //     flag = 0;
	        //}
	    }
	    /*for(j = 0;j < num;j++)
	    {
	        if(line[j] == 1)
	        {
	            if(count < 5)
	            {
	                flag = 1
	            }
	            else
	            {
	                count = 0;
	            }
	        }
	    }*/
	    if(flag == 1)
	    {
	        printf("NO\n");
	        //cout<<"NO"<<endl;  
	    }
	    else
	    {
	        printf("YES\n");
	        //cout<<"YES"<<endl;
	    }
	    
	}
	return 0;
}



