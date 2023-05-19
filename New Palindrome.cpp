#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    string str;
    vector<int> freq;
    
    cin>>t;
    while(t--)
    {
    	cin>>str;
    	freq.assign(26,0);
    	for(int i=0;i<str.size();i++)
    	{
    		freq[str[i]-'a']++;
		}
		int count=0;
		for(int i=0;i<26;i++)
		{
			if(freq[i]>1) count++;
		}
		if(count>1) cout<<"YES\n";
		else cout<<"NO\n";
    }

}
