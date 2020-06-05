#include <iostream>
using namespace std;

void maximum(int arr[], int num, int max, int pos)
{
    int i, max, pos = 0, returnArr[2];
    max = arr[0];
    for(i = 1;i < num;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i]; 
            pos = i;
        }
    }
    //returnArr[0] = max;
    //returnArr[1] = pos;
    //return returnArr;
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
    int i, j, test, num, cars[100000], profit, sellingCar[2];
    int max, pos;
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
            maximum(cars, num, max, pos);
            sellingCar = max;
            profit += sellingCar;
            cars[pos] = -1;
            depreciate(cars, num);
        }
            
    }
	return 0;
}

