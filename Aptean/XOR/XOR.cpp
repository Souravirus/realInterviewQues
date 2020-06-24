#include<bits/stdc++.h>
#define lli long long int
using namespace std;


int main(){
  int Q;
  cin >> Q;
  while(Q--){
    lli L, R;
    cin >> L >> R; 
    L-=1;
    lli exL = 4 - (L % 4);
    lli numL;
    if(exL != 4)
      numL = L+exL; 
    else
      numL = L; 
    lli qL;
    qL = numL/4;

    lli exR = R % 4; 
    lli numR = R - exR;
    lli qR = numR/4;

    lli sumR = numR*(qR+1); 
    lli sumL = numL*(qL+1);

    if(exR == 1)
      sumR += 1;
    if(exR == 2 || exR == 3)
      sumR += 1 + numR + 3;
    if(exL == 1 || exL == 2)
      sumL -= (numL);
    if(exL == 3)
      sumL -= (2*numL-1);
    lli sum = sumR - sumL;

    cout << sum << endl;
  }
	return 0;
}
//Hi there Sourav Sahoo please use lli instead of int
