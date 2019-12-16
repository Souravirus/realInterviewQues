#include<bits/stdc++.h>
using namespace std;

struct Box{
	int h,w,d;
};

bool compare(Box a,Box b){
	return (a.d*a.w)>(b.w*b.d);
}

int maxstackheight(Box b[],int n){
	Box rt[3*n];
	int index=0;
	for(int i=0;i<n;i++){
		rt[index].h=b[i].h;
		rt[index].w=max(b[i].w,b[i].d);
		rt[index].d=min(b[i].d,b[i].w);
//		cout<<rt[index].h<<"*"<<rt[index].w<<"*"<<rt[index].d<<endl;	
		index++;
		rt[index].h=b[i].w;
		rt[index].w=max(b[i].h,b[i].d);
		rt[index].d=min(b[i].h,b[i].d);
//		cout<<rt[index].h<<"*"<<rt[index].w<<"*"<<rt[index].d<<endl;	
		index++;
		rt[index].h=b[i].d;
		rt[index].w=max(b[i].h,b[i].w);
		rt[index].d=min(b[i].h,b[i].w);
//		cout<<rt[index].h<<"*"<<rt[index].w<<"*"<<rt[index].d<<endl;		
		index++;
	}
	n=3*n;
//	for(int i=0;i<n;i++)
//		cout<<rt[i].h<<"*"<<rt[i].w<<"*"<<rt[i].d<<endl;	
	sort(rt,rt+n,compare);
	int lis[3*n];
	for(int i=0;i<n;i++)
		lis[i]=rt[i].h;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(rt[i].w<rt[j].w && rt[i].d<rt[j].d && lis[i]<lis[j]+rt[i].h)
				lis[i]=lis[j]+rt[i].h;
		}
	}	
	int m=0;
	for(int i=0;i<n;i++)
		if(m<lis[i]) m=lis[i];
	return m;
}

int main(){
	int n;
	cin>>n;
	Box box[n];
	for(int i=0;i<n;i++){
		cin>>box[i].h>>box[i].w>>box[i].d;
	}
//	for(int i=0;i<n;i++) cout<<box[i].h<<" "<<box[i].w<<" "<<box[i].d<<endl;
	cout<<maxstackheight(box,n)<<endl;	
}
