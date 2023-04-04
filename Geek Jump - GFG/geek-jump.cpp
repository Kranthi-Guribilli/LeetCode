//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev=0;
        int prev2=0;
        for(int i=1;i<=n-1;i++){
            int jumpTwo=INT_MAX;
            int jumpOne=prev+abs(height[i]-height[i-1]);
            if(i>1){
                jumpTwo=prev2+abs(height[i]-height[i-2]);
            }
            int curr_i=min(jumpOne,jumpTwo);
            prev2=prev;
            prev=curr_i;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends