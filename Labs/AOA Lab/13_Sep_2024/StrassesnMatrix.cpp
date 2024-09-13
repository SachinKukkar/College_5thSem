#include <iostream>

using namespace std;

void inputArray(int arr[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
}

void printArray(int arr[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {

int A[2][2];
int B[2][2];

cout<<"Enter the elements of the matrix A : ";
inputArray(A);
cout<<"Enter the elements of the matrix B :";
inputArray(B);

cout<<"The first matrix is : "<<endl;
printArray(A);
cout<<"The first matrix is : "<<endl;
printArray(B);


int P1 = (A[0][0]*(B[0][1]-B[1][1]));
int P2 = ((A[0][0]+A[0][1])*(B[1][1]));
int P3 = ((A[1][0]+A[1][1])*(B[0][0]));
int P4 = ((A[1][1])*(B[1][0]-B[0][0]));
int P5 = ((A[0][0]+A[1][1])*(B[0][0]+B[1][1]));
int P6 = ((A[0][1]-A[1][1])*(B[1][0]+B[1][1]));
int P7 = ((A[0][0]-A[1][0])*(B[0][0]+B[0][1]));

int C11 = P5+P4-P2+P6;
int C12 = P1+P2;
int C21 = P3+P4;
int C22 = P5+P1-P3-P7;

int C[2][2] = {{C11,C12},
                {C21,C22}};

cout<<"The Strassen's Matrix multiplication result is : "<<endl;
printArray(C);


 
    return 0;
}