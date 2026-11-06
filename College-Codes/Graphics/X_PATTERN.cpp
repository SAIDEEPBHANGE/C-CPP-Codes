#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter Number: ";
	cin>>n;
	static int m=n-1;
	for(int i=0;i<n;i++){
		for(int s=0;s<i;s++){
			cout<<" ";
		}
		cout<<i+1;
		if(i+1!=n){
			for(int ms=0;ms<2*m-1;ms++){
				cout<<" ";
			}
			cout<<i+1<<endl;
			m--;
		}
		else{
			cout<<"\n";
		}
	}
	for(int i=n-1;i>0;i--){
		for(int s=0;s<i-1;s++){
			cout<<" ";
		}
		cout<<i;
		for(int ms=0;ms<2*m+1;ms++){
			cout<<" ";
		}
		cout<<i<<endl;
		m++;
	}
	return 0;
}
