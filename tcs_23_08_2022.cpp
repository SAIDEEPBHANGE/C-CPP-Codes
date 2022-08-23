/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<b.length();i++){
        for(int j=0;j<a.length();j++){
            if(b[i]==a[j]){
                a.erase(a.begin()+j);
                j--;
            }
        }
        cout<<a<<endl;
    }
    cout<<a<<endl;
    return 0;
}
