// now fill up table

vector<int> level; 
vector<vector<int>> up; // node, 2^ k ancestor kaun hai


// first build the tabble using this 
// initialze 1 level up parent in dfs 
for (int k = 1; k < 15; k++){
    for (int node = 0; node < n; node++){
        if (up[node][k - 1] == -1){
            up[node][k] = -1; 
        }else{
            up[node][k] = up[up[node][k - 1]][k - 1];
        }
    }
}


int findLca(int a, int b){
      if (level[a] < level[b]){
          return findLca(b, a);
      }
    
      // a level is bigger 
      int diff = level[a] - level[b];
   
      // uplift a by diff
    
      a = uplift(a, diff);
  
      if (a == b) return a; 

      // now both are on the same level
      for (int i = 14; i >= 0; i--){
          if (up[a][i] != -1 && up[b][i] != -1 && up[a][i] != up[b][i]){
              a = up[a][i];
              b = up[b][i];
          }
      }

      return uplift(a, 1);
  }
