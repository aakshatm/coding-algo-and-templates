class dsu{
    public: 
    int* parent; 
    int* rank; 
    dsu(int n){
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i<n; i++){
            parent[i] = i; 
            rank[i] = 1; 
        }
    }

    int find(int node){
        if (parent[node] == node) return node; 
        int temp = find(parent[node]);
        parent[node] = temp;
        return temp;
    }

    bool Union(int n1, int n2){
        int leader1 = find(n1);
        int leader2 = find(n2);
        if (leader1 == leader2) {
            return false; 
        }
        if (rank[leader1] > rank[leader2]){
            // leader1 will become the parent of leader2
            parent[leader2] = leader1; 
        }else if (rank[leader2] > rank[leader1]){
            parent[leader1] = leader2; 
        }else{
            parent[leader2] = leader1; 
            rank[leader1]++; 
        }

        return true; 
    }

}
