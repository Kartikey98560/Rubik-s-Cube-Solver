#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,k;
    long long int sum;
    vector<int> arr;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        arr.assign(n,0);
		for(int i=0;i<n;i++) cin>>arr[i];
		
		sort(arr.begin(),arr.end());
		sum=0;
		for(int i=0;i<n;i++) sum+=arr[i];
		
		
		int lower=0,upper=n-1;
		for(int i=0;i<k;i++) sum-=arr[upper-i];
		
		upper=n-k;
		
		long long temp =sum;
		while(k--)
		{
			//cout<<sum<<' '<<lower<<' '<<upper<<endl;
			temp=temp-(arr[lower]+arr[lower+1])+arr[upper];
			lower+=2;
			upper++;
			if(temp>sum)
			{
				sum=temp;
			}
		}
		cout<<sum<<endl;
   }

}
