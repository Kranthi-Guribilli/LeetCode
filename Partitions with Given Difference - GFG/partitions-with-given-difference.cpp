//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  int mod=(int) (1e9+7);
  int findUtil(int n,vector<int>&arr,int sum){
      vector<vector<int>>dp(n,vector<int>(sum+1,0));
      if(arr[0]==0){
          dp[0][0]=2;
      }else dp[0][0]=1;
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
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
	    // Your code goes here
	    int tSum=0;
	    for(int i=0;i<n;i++){
	        tSum+=arr[i];
	    }
	   if(((tSum-d)%2) || (tSum-d)<0) return 0;
	   return findUtil(n,arr,(tSum-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends