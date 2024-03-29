//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
      unordered_set<int>s;
      for(int i=0;i<n;i++){
          s.insert(a[i]);
      }
      int ans=0;
      for(int i=0;i<n;i++){
          if(s.find(a[i]-1)!=s.end()) continue;
          else{
              int j=a[i];
              while(s.find(j)!=s.end()) j++;
              ans=max(ans,j-a[i]);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends