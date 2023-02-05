//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define R2(n) n, n + 2 * 64, n + 1 * 64, n + 3 * 64
 
#define R4(n)                                              \
    R2(n), R2(n + 2 * 16), R2(n + 1 * 16), R2(n + 3 * 16)
 
#define R6(n)                                              \
    R4(n), R4(n + 2 * 4), R4(n + 1 * 4), R4(n + 3 * 4)
 
unsigned int lookuptable[256]
    = { R6(0), R6(2), R6(1), R6(3) };
class Solution {
  public:
    unsigned int reversedBits(long long X) {
        // code here
       unsigned int reverse_num = 0; 
       reverse_num = lookuptable[X & 0xff] << 24 
                  | lookuptable[(X >> 8) & 0xff] << 16
                  | lookuptable[(X >> 16) & 0xff] << 8
                  | lookuptable[(X >> 24) & 0xff];
       return reverse_num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends