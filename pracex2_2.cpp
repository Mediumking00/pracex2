#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			}
		}
	}
}

int main(){
	//Write your code here
	ifstream scor("score1.txt");
	float x[20]={};
	string line;
	int i=0 , t[20]={};
	while(getline(scor,line)){
		x[i]=atof(line.c_str());
		i++;
	}
	sort(x,i);
	int k=0;
ofstream T("rank.txt");
k=0;
for(int j=0;j<i;j++){
	if(x[j] >= x[j+1] || x[j] <= x[j-1])
			if (x[j-1]!=x[j]) {
				T<<x[j]<<" rank :"<<j+1<<endl;
				k=0;
			}if(x[j-1]==x[j]){
				T<<x[j]<<" rank :"<<j-k<<endl;
				k++;
			}
	}
ofstream P("result.txt");
	k=0;
	for(int j=0;j<i;j++){
		if(x[j] >= x[j+1] || x[j] <= x[j-1])
				if (x[j-1]!=x[j]) {
					P<<x[j]<<"="<<j+1<<endl;
					k=0;
				}if(x[j-1]==x[j]){
					P<<x[j]<<"="<<j-k<<endl;
					k++;
				}
		}

	return 0;
}
