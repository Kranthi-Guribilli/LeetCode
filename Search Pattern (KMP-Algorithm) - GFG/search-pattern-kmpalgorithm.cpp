//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
        void getlps(string p,vector<int> &lps){
            int i=0,j=1,m=p.size();
            while(j<m){
                if(p[j]==p[i]){
                    i++;
                    lps[j]=i;
                    j++;
                }
                else{
                    if(i==0){
                        lps[j]=0;
                        j++;
                    }else{
                        i=lps[i-1];
                    }
                }
            }
        }
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int>res;
            int m=pat.size(),n=txt.size();
            vector<int>lps(m,0);
            getlps(pat,lps);
            int ind1=0,ind2=0;
            while(ind1<n){
                if(txt[ind1]==pat[ind2]){
                    ind2++;ind1++;
                    if(ind2==m){res.push_back((ind1-m)+1);}
                    if(ind1==n){return res;}
                }
                else{
                    if(ind2==0){ind1++;}
                    else{ind2=lps[ind2-1];}
                }
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends