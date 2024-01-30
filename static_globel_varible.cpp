#include <iostream>
using namespace std;
int y=0;
int Sum_globel(int n){
    if (n>0)
    {
        y++;
        return Sum_globel(n-1)+y;
    }
    
    return 0;
}

int Sum_static(int n){
    static int x=0;
    if (n>0)
    {
        x++;
        return Sum_static(n-1)+x;
    }
    
    return 0;
}

int main(){
    int z;
    cout<<"Enter the number :";
    cin>>z;
    cout<<Sum_static(z)<<endl;
    cout<<Sum_static(z)<<endl;
    cout<<Sum_globel(z)<<endl;
    cout<<Sum_globel(z)<<endl;
return 0;
}