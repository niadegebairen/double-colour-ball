#include<iostream>
#include<fstream>
#include<vector>

std::ofstream out("set");
void combine(int a[],int n,int m,int b[],const int M){
	for(int i=n;i>=m;--i){
		b[m-1]=i-1;
		if(m>1)
			combine(a,i-1,m-1,b,M);
	else{
		for(int l=1;l<=16;++l){
			for(int j=M-1; j>=0; j--)
				out << a[b[j]] << " ";
			out<<l<<" "<<0<<std::endl;
		}
	}
	}
}
int main(){
	int a[33]={33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int b[6];
	combine(a,33,6,b,6);
	return 0;
}
