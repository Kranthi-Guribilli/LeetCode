//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007
class Solution{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int temp=(prev2+prev)%MOD;
            prev2=prev%MOD;
            prev=temp;
        }
        return prev;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends