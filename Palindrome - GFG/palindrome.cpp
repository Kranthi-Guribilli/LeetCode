//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
	    string reverse(string str){
	        string ans;
            for (int i = str.length() - 1; i >= 0; i--)
                ans+=str[i];
            return ans;
	    }

		string is_palindrome(int n)
		{
		    // Code here.
		    string s=to_string(n);
		    string ans=reverse(s);
		    if(s==ans) return "Yes";
		    else return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends