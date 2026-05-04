#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;

int knapsack(int weight[], int profit[],int n,int W){
    int KS[n+1][W+1];
    for(int i=0;i<=W;i++){
        KS[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        KS[i][0] = 0;
    }

    for(int i =1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(weight[i-1]>j){
                KS[i][j] = KS[i-1][j];
            } else {
                KS[i][j] = max(KS[i-1][j], profit[i-1]+KS[i-1][j-weight[i-1]]);
            }
        }
    }
    return KS[n][W];
}

int main(){
    int weight[] = {1,2,4};
    int profit[] = {10,12,28};
    int n = sizeof(weight)/sizeof(weight[0]);
    int capa = 6;
    cout<<knapsack(weight,profit,n,capa);
    return 0;
}