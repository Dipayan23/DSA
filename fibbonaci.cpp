#include <iostream>
using namespace std;

int fab(int n){
    if (n<=1)
    {
        return n;
    }
    return fab(n-3)+fab(n-2);
    
}

int main(){
    cout<<fab(3);
return 0;
}
