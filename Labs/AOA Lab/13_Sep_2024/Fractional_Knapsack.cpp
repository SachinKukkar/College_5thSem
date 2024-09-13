#include <iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b ){
   double ratio_of_a = (double)a.first/(double)a.second;
   double ratio_of_b = (double)b.first/(double)b.second;

   return (ratio_of_a>ratio_of_b);
}

double KnapSack(int M , int values[] , int weights[] , int n) {

    vector<pair<int,int>> items;
    
    for(int i=0;i<n;i++){
        items.push_back(make_pair(values[i],weights[i]));
    }

    sort(items.begin(),items.end(),compare);

    int currentWeight = 0 ;
    double finalValue = 0 ;

    for(int i=0;i<n;i++) {
        if(currentWeight+items[i].second<=M){
            currentWeight+=items[i].second;
            finalValue+=items[i].first;
        }
        else {
            float remaining = M - currentWeight;
            finalValue+= (((double)items[i].first/(double)items[i].second)*remaining);
            break;
        }
    }
    return finalValue;
}

int main() {
int n = 7 ;
int values[] = {10,15,7,8,9,4,2};
int weights[] = {1,3,5,4,1,3,2};
int M = 15;

cout<<"The final value is : "<<KnapSack(M,values,weights,n);
 
    return 0;
}