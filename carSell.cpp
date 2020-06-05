#include <iostream>
using namespace std;


int maximum(int arr[], int num)
{
    int i, localMax, localPos, returnArr[2];
    localMax = arr[0];
    for(i = 1;i < num;i++)
    {
        if(arr[i] > localMax)
        {
            localMax = arr[i]; 
            localPos = i;
        }
    }
    
    if(localMax < 0)
    {
        localMax = 0;
        localPos = 0;
    }
    
    arr[localPos] = -1;
    return localMax; 
}

void depreciate(int cars[],int num)
{
    int i;
    for(i = 0;i < num;i++)
    {
        if(cars[i] > 0)
        {
            cars[i]--;
        }
    }
}

int main()
{
    int i, j, test, num, cars[100000], profit;
    int sellingCar;
    //int max = 0, pos = 0;
    cin >> test;
    for(i = 0;i < test;i++)
    {
        profit = 0;
        cin >> num;
        for(j = 0;j < num;j++)
        {
            cin >> cars[j];
        }
        
        for(j = 0;j < num;j++)
        {
            sellingCar = maximum(cars, num);
            //sellingCar = max;
            //cout<<"Max Num "<<sellingCar<<endl;
            profit += sellingCar;
            //cars[*(sellingCar + 1)] = -1;
            depreciate(cars, num);
        }
        cout<<profit%1000000007<<endl;
            
    }
	return 0;
}

