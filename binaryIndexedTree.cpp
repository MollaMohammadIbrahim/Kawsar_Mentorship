#include<bits/stdc++.h>
using namespace std;
int tree[10000];
int size;

void updateTree(int index,int val){
    while(index <= size){
        tree[index] += val;
        index = index + (index & -index);
    }
}

int queryTree(int index){
    int sum = 0;
    while(index>0){
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

int main(){
    vector <int> ii = {1,2,3,4,5,6,7,8};
    size = ii.size();
    memset(tree,0,sizeof(tree));
    for(int i=0; i<size ; i++){
        updateTree(i+1,ii[i]);
    }
    cout<<"Sum till index 5: "<<queryTree(5)<<endl;

}