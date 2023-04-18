//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<int>prev(n,0),cur(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                //if(i==0) cur[j]=Matrix[0][j];
                int up=matrix[i][j];
                if(i>0){
                    up+=prev[j];
                }else up+=(-1e9);
                
                int lD=matrix[i][j];
                if(j-1>=0){
                    lD+=prev[j-1];
                }else lD+=(-1e9);
                
                int rD=matrix[i][j];
                if(j+1<n){
                    rD+=prev[j+1];
                }else rD+=(-1e9);
                
                cur[j]=max(up,max(lD,rD));
            }
            prev=cur;
        }
        int maxi=INT_MIN;
        for(int j=0;j<n;j++){
            maxi=max(maxi,prev[j]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends