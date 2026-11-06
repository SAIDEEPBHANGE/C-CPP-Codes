#include <iostream>
using namespace std;
int main()
{
    int row, col, k=0;
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int count=1;
    int count1=1;
    int count2=n-1;
    int count3=n-1;
    cout<<endl;
//Printing upside pattern or above centre point
    for(int row=0; row<n; row++){
        for(int col=1; col<row+1; col++){
            cout<<"  ";
        }
        for(int k=0; k<col+1; k++){
            cout<<count<<" ";
            count++;
            for(int k=0; k<n-row-1;k++){
                cout<<"  ";
            }
            for(int k=0; k<n-row-2;k++){
                cout<<"  ";
            }
            for(int k=0; k<col+1; k++){
                if(row!=n-1){
                    cout<<count1<<" ";
                    count1++;
                }
            }
        }
        cout<<endl;
    }
//Printing downside pattern or below centre point 
    for(int row=0; row<n-1; row++){
        for(int col=1; col<n-row-2; col++){
            cout<<"  ";
        }
        for(int k=0; k<col+1; k++){
            if(row!=n-2){
                cout<<"  ";
            }
            for(int k=0; k<col+1;k++){
                cout<<count2<<" ";
                count2--;
            }
            for(int col=1; col<row+2; col++){
                cout<<"  ";
            }
            for(int k=0; k<row; k++){
                cout<<"  ";
            }
            for(int i=0; i<col+1; i++){
                cout<<count3<<" ";
                count3--;
            }    
        }
        cout<<endl;
    }
}