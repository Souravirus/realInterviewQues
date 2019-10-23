#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
#define mod 1000000007
using namespace std;

int debug = 0;
int regex_find(string pattern, string s){
  dout << "reached function" << endl;
  int last_match = 0;
  int s_ind = 0;
  char prev_char;
  int flag = 0;
  for(int i = 0; i < pattern.length();){
    dout << "pattern= " << pattern[i] << " string" << s[s_ind] << endl;
    dout << "i: " << i << "s_ind" << s_ind << endl;
    if(s_ind > s.length()-1){
      return -1;
    }
    if(pattern[i] == '.'){
      if(last_match == 0)
        last_match = s_ind; 
      
      if(i == pattern.length()-1){
        return last_match;
      }
      prev_char = '.';
      i++;
      s_ind++;
    }
    
    else if(pattern[i] >= '0' && pattern[i] <= '9' || pattern[i] >= 'A' && pattern[i] <= 'Z' || pattern[i] >= 'a' && pattern[i] <= 'z'){
      if(s[s_ind] == pattern[i]){
        if(i ==pattern.length()-1){
          return last_match;
        }
        if(last_match == 0)
          last_match = s_ind;
        prev_char = pattern[i];
        i++;
        s_ind++;
      }

      else{
        if(pattern[i+1] == '?' || pattern[i+1] == '*'){
          i += 2;
          s_ind += 2;
        }

        else{
          s_ind = last_match+1;
          last_match++;
          i = 0;
        }
        
      }
    }

    else if(pattern[i] == '*'){
      if(i == pattern.length()-1)
        return last_match;
      if(prev_char == '.'){
        if(s[s_ind] == pattern[i+1]){
          i++;
        }
        s_ind++;
      }
      else if(s[s_ind] == prev_char){
        s_ind++;
      }

      else{
        i++;
      }

    }

    else if(pattern[i] == '?'){
      if(i == pattern.length() -1)
        return last_match;
      if(pattern[i+1] == s[s_ind]){
        i++;
        s_ind++;
      }
    }

    else if(pattern[i] == '+'){
      if(s[s_ind] == prev_char){
        if(i == pattern.length() -1)
          return last_match;
        i++;
        s_ind++;
      }

      else{
        i = 0;
        s_ind = last_match+1;
        last_match++;
      }
    }
  }
  return last_match;
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
    int ans = regex_find(pattern, s);
    if(ans == -1){
      cout << "Unmatched" << endl;
    }

    else{
      cout << ans << endl;
    }
	}
	return 0;
}
