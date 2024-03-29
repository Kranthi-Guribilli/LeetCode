//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int tSum=0;
	    for(int i=0;i<n;i++){
	        tSum+=arr[i];
	    }
	    vector<vector<bool>>dp(n,vector<bool>(tSum+1,false));
	    for(int i=0;i<n;i++){
	        dp[i][0]=true;
	    }
	    if(arr[0]<=tSum) dp[0][arr[0]]=true;
	    for(int i=1;i<n;i++){
	        for(int k=1;k<=tSum;k++){
	            bool notTaken=dp[i-1][k];
	            bool taken=false;
	            if(arr[i]<=k){
	                taken=dp[i-1][k-arr[i]];
	            }
	            dp[i][k]=notTaken||taken;
	        }
	    }
	    int mini=1e9;
	    for(int i=0;i<=tSum;i++){
	        if(dp[n-1][i]==true){
	            int diff=abs(i-(tSum-i));
	            mini=min(mini,diff);
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends