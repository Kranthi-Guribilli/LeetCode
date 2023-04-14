//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        int count=0;
        string s;
        while(s.length()<B.length()){
            s.append(A);
            count++;
        }
        if(s.find(B,0)!=string::npos){
            return count;
        }
        else{
            count++;
            s.append(A);
        }
        if(s.find(B,0)!=string::npos){
            return count;
        }
        else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends