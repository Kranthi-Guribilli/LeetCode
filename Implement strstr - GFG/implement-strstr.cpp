//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
void getlps(string p,vector<int>&lps){
    int len=0,ind=1,m=p.size();
    while(ind<m){
        if(p[ind]==p[len]){
            len++;
            lps[ind]=len;
            ind++;
        }
        else{
            if(len==0){
                lps[ind]=0;
                ind++;
            }else{
                len=lps[len-1];
            }
        }
    }
}
int strstr(string s, string p)
{
     //Your code here
     int m=p.size(),n=s.size();
     vector<int>lps(m,0);
     getlps(p,lps);
     int ind1=0,ind2=0;
     while(ind1<n){
        if(s[ind1]==p[ind2]){
            ind2++;ind1++;
            if(ind2==m){return ind1-m;}
         }else{
            if(ind2==0) ind1++;
            else ind2=lps[ind2-1];
        }
    }
    return -1;
}