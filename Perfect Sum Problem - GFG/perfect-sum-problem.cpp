//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod =(int)1e9+7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        /*for(int i=0;i<n;i++){
            dp[i][0]=1;
        }*/
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int k=0;k<=sum;k++){
                int notTaken=dp[i-1][k];
                int taken=0;
                if(arr[i]<=k){
                    taken=dp[i-1][k-arr[i]];
                }
                dp[i][k]=(taken+notTaken)%mod;
            }
        }
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends