int Solution::solve(vector<int> &A) {
    int x[A.size()][4];
    x[0][0] = INT_MIN;// for selling on current price
    x[0][1] = -1*A[0];// for buying
    x[0][2] = 0;// for selling on previous days and now chilling
    x[0][3] = INT_MIN;// for buying on previous days and now chilling
    
    for(int i = 1; i < A.size(); i++){
        x[i][0] = max(x[i-1][1] + A[i], x[i-1][3] + A[i]);
        x[i][1] = x[i-1][2] - A[i];
        x[i][2] = max(x[i-1][0], x[i-1][2]);
        x[i][3] = max(x[i-1][3], x[i-1][1]);
     }
     
     return max(x[A.size()-1][0], x[A.size()-1][2]);
}
