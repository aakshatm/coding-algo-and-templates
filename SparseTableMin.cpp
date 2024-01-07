class SpareTable{
public: 
    int n; 
    vector<vector<int>> table; 
    SpareTable(int n, vector<int> &arr){
        this -> n = n; 
        int k = log2(n);
        table.resize(k + 1, vector<int>(n));    
        table[0] = arr;
        buildTable();
        debug(table);
    }

    void buildTable(){
        for (int len = 1; len < table.size(); len++){
            for (int i = 0; (i + (1 << len) - 1) < n; i++){
                table[len][i] = min(table[len - 1][i], table[len - 1][i + (1 << (len - 1))]);
            }
        }
    }

    int query(int l, int r){
        int len = r - l + 1; 
        int k = log2(len);
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};
