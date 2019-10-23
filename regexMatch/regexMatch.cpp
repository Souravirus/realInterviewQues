#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
#define mod 1000000007
using namespace std;

int debug = 0;

string filter_pattern(string pattern){
  string new_pat = "";
  for(int i = 0; i < pattern.length(); i++){
    if (pattern[i] == '*' && pattern[i-1] != '*'){
      new_pat += pattern[i];
    }

    else if(pattern[i] == '?' && pattern[i-1] != '?'){
      new_pat += pattern[i];
    }

    else if(pattern[i] == '+' && pattern[i-1] != '+'){
      new_pat += pattern[i];
    }

    else{
      new_pat += pattern[i];
    }
  }

  return new_pat;
}
int regex_match(string s, string pattern){
  int T[s.length()+1][pattern.length()+1];
  memset(T, -1, sizeof(T));
  for(int i = 1; i < s.length()+1; i++){
    T[i][0] = i-1;
  }

  T[0][0] = 0;
  for(int i = 1; i < pattern.length()+1; i++){
    if(pattern[i-1] == '*'){
      T[0][i] = T[0][i-2];
    }
  }

  for(int i = 1; i < s.length()+1; i++){
    for(int j = 1; j < pattern.length()+1; j++){
      if(pattern[j-1] == '.' || pattern[j-1] == s[i-1]){
        T[i][j] = T[i-1][j-1];
      }

      else if(pattern[j-1] == '*' || pattern[j-1] == '?'){
        T[i][j] = T[i][j-2];
        if(pattern[j-2] == '.' || pattern[j-2] == s[i-1]){
          if(T[i-1][j] != -1){
            if(T[i][j] == -1){
              T[i][j] = T[i-1][j];
            }

            else{
              T[i][j] = min(T[i][j], T[i-1][j]);
            }
          }
        }
      }

      else if(pattern[j-1] == '+'){
        if(pattern[j-2] == '.' || pattern[j-2] == s[i-1] ){
          T[i][j] = T[i-1][j-2];
        }
      }
    }
  }

  for(int i = 0; i < s.length()+1; i++){
    for(int j = 0; j < pattern.length()+1; j++){
      dout << T[i][j] << " ";
    }

    dout << endl;
  }

  for( int i = 1; i < s.length()+1; i++){
    if(T[i][pattern.length()] != -1){
      return T[i][pattern.length()];
    }
  }
  return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t=1;
	cin >> t;
  string s;
  cin >> s;
	while(t--){
    string pattern;
    cin >> pattern;
    pattern = filter_pattern(pattern);
    int ans = regex_match(s, pattern);
    if( ans != -1)
      cout << ans+1 << endl;
    else
      cout << "Undefined" << endl;
	}
	return 0;
}
//Hi there Sourav Sahoo please use lli instead of int
