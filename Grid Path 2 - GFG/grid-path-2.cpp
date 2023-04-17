//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int> > &maze){
    #define MOD 1000000007
    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==1){
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0 && maze[i][j]==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0 && maze[i][j]==0)
                up = prev[j]%MOD;
            if(j>0 && maze[i][j]==0)
                left = temp[j-1]%MOD;
                
            temp[j] = (up%MOD + left%MOD)%MOD;
        }
        prev = temp;
    }
    
    return prev[m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends