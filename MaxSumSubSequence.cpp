#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
int maxSum = 0;

int rec(int [], int, int, int, int, int);
int maxSubSeqSum(int[], int);

int main() {
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    cin>>N;
	    int arr[N];
	    for(int i=0; i<N;i++)
	    {
	        cin>>arr[i];
	    }
	    maxSubSeqSum(arr,N);
	    cout<<maxSum<<endl;
	}
	return 0;
}

int rec(int arr[], int N, int startIndex,int k, int sum, int currMaxIndex)
{
    //cout<<"Entered Rec, startIndex = " <<startIndex<<" currIndex "<<k<<" currMaxIndex = "<<currMaxIndex<<" sum "<<sum<<" maxsum intially  ="<<maxSum<<endl;
    if(sum>maxSum)
        {
            maxSum = sum;
        }
    //cout<<"maximum sum after comparison with sum = "<<maxSum<<endl;
    if(k == N-1)
    {
        //cout<<"reached end"<<endl;
        return sum;
        //rec(arr,N,startIndex,startIndex,arr[startIndex],startIndex);
    }
    
    if(arr[currMaxIndex]<arr[k+1])
    {
        sum=sum+arr[k+1];
        if(sum>maxSum)
        {
            maxSum = sum;
            //cout<<"maxsum updated = "<<maxSum<<endl;
        }
        
        currMaxIndex = k+1;
        //cout<<"  currMaxIndex = "<<currMaxIndex<<endl;
        rec(arr, N, startIndex, k+1, sum, currMaxIndex);
    }
    else 
    {
        rec(arr, N, startIndex, k+1, sum, currMaxIndex);
    }
    
    //cout<< "Exiting Rec, maxsum at recursion end = "<< maxSum<<endl<<endl;
}

int maxSubSeqSum(int arr[], int N)
{
    maxSum = 0;
    //cout<<"--"<<maxSum<<"--"<<endl;
    //int flag = -1;
    
    for(int i=0;i<N;i++) 
    {   
        int currMaxIndex = i;
        int sum=arr[i];
        //cout<<"sum at i "<<i<<" = "<<sum<<endl;
        //call recursion
        for(int j=i;j<N;j++)
        {
            //cout<<endl<<"j = "<<j<<endl;
            rec(arr,N,i,j,sum,currMaxIndex);
            //cout<<"j = " <<j<<endl; 
        }
        //cout<<"maxsum in loop after rec call = "<<maxSum<<" i="<<i<<endl;
    }
    //cout<<"--"<<maxSum<<"--"<<endl;
    return maxSum;
}
