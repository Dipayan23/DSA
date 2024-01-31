#include <iostream>
using namespace std;

void towerOfHanoi(int n,char from,char aux ,char to){
    if (n==1)
    {
        cout<<from<<"--------->"<<to<<endl;
        return;
    }
    towerOfHanoi(n-1,from,to,aux);
    cout<<from<<"--------->"<<to<<endl;
    towerOfHanoi(n-1,aux,from,to);
    return;
}

int main(){
    towerOfHanoi(3,'A','B','C');
return 0;
}