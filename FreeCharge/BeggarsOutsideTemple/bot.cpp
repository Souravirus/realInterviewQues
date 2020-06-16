vector<int> Solution::solve(int A, vector<vector<int> > &B){
    vector<int> add(A);
    vector<int> ans(A);
    fill(add.begin(), add.end(), 0);
    for(int i = 0; i < B.size(); i++){
        add[B[i][0]-1] += B[i][2];
        if(B[i][1] != A){
            add[B[i][1]] -= B[i][2];
        }
    }

    int curr = 0;
    for(int i = 0; i < A; i++){
        curr += add[i];
        ans[i] = curr;
    }

    return ans;
}