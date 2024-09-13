#include <iostream>
using namespace std;

int main() {
    int x1,x2,y1,y2;
    cout<<"Enter the value of x1 : ";
    cin>>x1;
    cout<<"Enter the value of y1 : ";
    cin>>y1;
    cout<<"Enter the value of x2 : ";
    cin>>x2;
    cout<<"Enter the value of y2 : ";
    cin>>y2;

    for(int x = x1; x < x2 ; x++) {
        for(int y = y1 ; y < y2 ; y++) {
            cout<<".";
        }
    }
}