//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int>q;
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            inDeg[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(inDeg[i]==0) q.push(i);
	    }
	    //vector<int>ans;
	    int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        //ans.push_back(node);
	        cnt++;
	        for(auto it:adj[node]){
	            inDeg[it]--;
	            if(inDeg[it]==0) q.push(it);
	        }
	    }
	    if(cnt==V) return false;
	    return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends