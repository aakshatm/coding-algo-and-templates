int m = 20;
int Par[n][m];

    
void dfs(int node, int par){
    Par[node][0] = par; 
    for (int i = 1; i < m; i++){
        Par[node][i] = Par[Par[node][i -1]][i - 1];
    }
    for (auto child : adj[node]){
        if (child != par){
            dfs(child, node);
        }
    }
}

int kthParent(int node, int k){
    for (int i = 0; i < m; i++){
        if ((1 << i) & k){
            node = Par[node][i];
        }
    }
    return node; 
}
