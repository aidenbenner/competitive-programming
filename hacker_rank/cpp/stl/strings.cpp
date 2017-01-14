
#include <iostream>

using namespace std;
int main(){
    string a, b;
    
    cin >> a >> b;

    printf("%lu %lu\n", a.length(), b.length());
    
    cout << a + b << endl;
    
    char hold = b[0];
    b[0] = a[0];
    a[0] = hold;

    cout << a << " " << b;
}
