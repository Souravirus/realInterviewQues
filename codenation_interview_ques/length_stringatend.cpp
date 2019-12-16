#include<bits/stdc++.h>
using namespace std;

bool isequal(string s){
	int num=0,x=1,i=s.length()-1;
	for( ;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			num = (s[i]-'0')*x+num;
			x*=10;
		}
		else
			break; 
	}
	return num==i+1;
}

int main(){
	string s;	
	cin>>s;
	isequal(s)?cout<<"yes"<<endl:cout<<"no"<<endl;
	return 0;
}
