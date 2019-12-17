#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
#define mod 1000000007
using namespace std;

class Money{
  int val; string type;
  public:
  Money(string t) {type = t;}
  void setval(int v) { val = v;}
  int getval() {return val;}
  string gettype() {return type;}
};

class Coins : public Money{
  public:
  Coins(): Money(string("Coins")){}
};

class Notes : public Money{
  public:
   Notes(): Money(string("Notes")){}
};

template <typename type>

class Bag {
  vector<type> v;
  public:
  void add(type T){
    v.push_back(T); 
  }

  void display(type T){
    cout << T.getval() << endl;
  }
  void display_all(){
    vector<type> n, c;
    for(int i = 0; i <v.size(); i++){
      if(v[i].gettype() == "Coins") c.push_back(v[i]);
      else n.push_back(v[i]);
    }

    cout << "Note :" << endl;
    for(int i = 0; i < n.size(); i++){
      display(n[i]);
    }

    cout << "Coin:" << endl;

    for(int i = 0; i < c.size(); i++){
      display(c[i]);
    }
  }
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
  Bag<Money>b;
	while(t--){
    string s;
    cin >> s;
    int val;
    cin >> val;
    if(s == "Note"){
      Notes n;
      n.setval(val);
      b.add(n);
    }

    if(s == "Coin"){
      Coins c;
      c.setval(val);
      b.add(c);
    }
	}

  b.display_all();
	return 0;
}
