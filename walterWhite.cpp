#include <iostream>
using namespace std;

int maximum(int arr[],int num)
{
    int i, max = arr[0];
    for(i = 1;i < num;i++)
    {
        if(arr[i] > max)
        {
            max= arr[i];
        }
    }
    return max;
}

int main() {
	// your code goes here
	int n, num, teamA[100000], teamB[100000], i, j, max1, max2;
    cin>>n;
    for(i = 0;i < n;i++)
    {
        cin>>num;
        for(j = 0;j < num;j++)
        {
            cin>>teamA[j];
        }
        for(j = 0;j < num;j++)
        {
            cin>>teamB[j];
        }
        max1 = maximum(teamA, num);
        max2 = maximum(teamB, num);
        if(max1 != max2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
	return 0;
}

