//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool PartitionUtil(int n,int arr[],int target){
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int j=0;j<n;j++){
            dp[j][0]=true;
        }
        if(arr[0]<=target) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notTaken=dp[i-1][k];
                bool taken=false;
                if(arr[i]<=k){
                    taken=dp[i-1][k-arr[i]];
                }
                dp[i][k]= taken||notTaken;
            }
        }
        return dp[n-1][target];
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int tSum=0;
        for(int i=0;i<N;i++){
            tSum+=arr[i];
        }
        if(tSum%2) return 0;
        else return PartitionUtil(N,arr,tSum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends