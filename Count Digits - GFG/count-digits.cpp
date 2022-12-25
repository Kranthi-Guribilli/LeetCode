//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool divisible(string N,int dig){
        int ans=0;
        for(int i=0;i<N.size();i++){
            ans=(ans*10+(N[i]-'0'));
            ans%=dig;
        }
        return (ans==0);
    }

    int evenlyDivides(int N){
        //code here
        string s=to_string(N);
        bool divide[10]={false};
        divide[1]=true;
        
        for(int i=2;i<=9;i++){
            if(divisible(s,i))
                divide[i]=true;
        }
        
        int res=0;
        for(int i=0;i<s.size();i++){
            if(divide[s[i]-'0']==true)
                res++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends