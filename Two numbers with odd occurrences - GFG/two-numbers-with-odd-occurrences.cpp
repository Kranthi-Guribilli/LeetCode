//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int a[], long long int n)  
    {
        // code here
        long long int x=a[0];
        for(int i=1;i<n;i++){
            x^=a[i];
        }
        int set_bit=(x & ~(x-1));
        long long int first=0,sec=0;
        for(int i=0;i<n;i++){
            if(set_bit&a[i]){
                first^=a[i];
            }else{
                sec^=a[i];
            }
        }
        if(first>=sec){
            return {first,sec};
        }else{
            return {sec,first};
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends