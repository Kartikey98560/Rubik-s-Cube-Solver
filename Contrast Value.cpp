#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,k,count;
    
    vector<int> arr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr.assign(n,0);
		for(int i=0;i<n;i++) cin>>arr[i];
		
		bool flag=true;
		for(int i=0;i<n-1 and flag;i++)
		{
			if(arr[i]!=arr[i+1]) flag=false;
		}
		if(flag)
		{
			cout<<1<<endl;
			continue;
		}
		
		count=0;
		int lower=0,higher=0;
		int status=0;  //1-as   2-des  0-nil
		int i=0;
		//for(int i=0;i<n-1;i++)
		while(i<=n-1)
		{
			if(status ==1)
			{
				if(i!=n-1 and arr[i]<=arr[i+1])
				{
					higher++;
				}
				else
				{
					count+=(higher-lower-1);
					lower=higher;
					status=0;
					i--;
				}
			}
			else if(status==2)
			{
				if(i!= n-1 and arr[i]>=arr[i+1])
				{
					higher++;
				}
				else
				{
					count+=(higher-lower-1);
					lower=higher;
					status=0;
					i--;
				}
			}
			else if(status==0)
			{
				if(arr[i]<=arr[i+1])
				{
					lower=i;
					higher=i+1;
					status=1;
				}
				else
				{
					lower=i;
					higher=i+1;
					status=2;
				}
			}
			i++;
		}
		cout<<(n-count)<<endl;
   }

}