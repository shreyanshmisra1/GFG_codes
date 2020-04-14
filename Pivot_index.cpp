#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
/*int computeSumArray(int arr[],int N)
{
    left_sum_arr[0]=0;
    left_sum_arr[1]=arr[0];
    //left_sum_arr[2]=left_sum_arr[1]+arr[1];
    //left_sum_arr[3]=left_sum_arr[2]+arr[2];
    
    for(int i=2;i<N;i++)
    {
        left_sum_arr[i]=left_sum_arr[i-2]+arr[i-2];
    }
        
*/

int leftSum(int arr[], int left_sum_arr[],int i)
{
    if(i==1)
    {
        return left_sum_arr[1];
    }
    left_sum_arr[i]=left_sum_arr[i-1]+arr[i-1];
    
    return left_sum_arr[i];
}

int midIndex(int arr[], int N, int sum)
{
    int left_sum_arr[N] = {0};
    left_sum_arr[0]=0;
    left_sum_arr[1]= arr[0];
    
    int flag = 0;
    if(N==1)
    {
        cout<<"1"<<endl;
        return 1;
    }
    for(int i=1;i<N;i++)
    {
        int temp = leftSum(arr,left_sum_arr,i);//temp should have left sum
        //cout<<" sum arr "<<left_sum_arr[i];
        if((sum-temp-arr[i]) == temp)
        {
            cout<<i+1<<endl;
            flag = 1;
            return i+1;
        }
    }
    
    if (flag == 0)
    {
        cout<<"-1"<<endl;
        return -1;
    }
    
    
}
int main() {
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    cin>>N;
	    int sum = 0;
	    int arr[N];
	    for(int i=0; i<N;i++)
	    {
	        cin>>arr[i];
	        sum=sum+arr[i];
	    }
	    midIndex(arr,N,sum);
	}
	
	return 0;
}
