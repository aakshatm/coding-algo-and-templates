vector<int> start(n + 1); 
vector<int> end(n + 1);
vector<int> arr(n);
timer = -1; 
dfs(1, -1, adj, start, end, arr, values);


void dfs(int node, int parent, vector<int> adj[], vector<int>& pre, vector<int>& post, vector<int>&arr, vector<int>&value){
    timer++; 
    pre[node] = timer; 
    arr[timer] = value[node];

    for (auto child: adj[node]){
        if (child == parent) continue; 
        dfs(child, node, adj, pre, post, arr, value);
    }

    post[node] = timer; 
  
}
