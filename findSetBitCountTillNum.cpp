vector<long long> setBitCount(long long num){
    vector<long long> bitCounts(63, 0);
    int bit = 63; 
    while (true){
        // find the most significant set bit
        while (bit >= 0 && (num & ((ll)1 << bit)) == 0) bit--; 
        
        for (int i = bit - 1; i >= 0; i--){
            bitCounts[i] += ((ll)1 << (bit - 1));
        }
        bitCounts[bit] += ((num) - ((ll)1 << bit) + 1);
        num -= ((ll)1 << bit);
        if (num == 0) break; 
    }
    return bitCounts; 
}
