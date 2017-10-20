#include <stdio.h>
#include <malloc.h>

int findRank(int a[],int l,int r,int num,int size);

int main(){
    int n;
    scanf("%d",&n);
    int *scores = malloc(sizeof(int) * n);
    for(int scores_i = 0; scores_i < n; scores_i++){
        scanf("%d",&scores[scores_i]);
    }
    int m;
    scanf("%d",&m);
    int *alice = malloc(sizeof(int) * m);
    for(int alice_i = 0; alice_i < m; alice_i++){
        scanf("%d",&alice[alice_i]);
    }

    int rank[n],size=1;
    rank[0]=scores[0];
    for (int i = 1; i < n ; ++i) {

        if(scores[i]!=scores[i-1])
            rank[size++]=scores[i];
    }
    for (int j = 0; j <m ; ++j) {
        int frank = findRank(rank, 0, size-1, alice[j],size);
        printf("%d \n", frank);
    }
    return 0;
}

int findRank(int a[],int l,int r,int num,int size){

    int mid= (l+r)/2;
    if(l==r || l>r){
        if(a[l]==num)
            return(l+1);
        else if(a[l]>num) {
            return (l+2);
        }
        else
            return l+1;
    }
    else{
        if(a[mid]== num)
            return (mid +1);
        else if(a[mid]> num)
            return findRank(a,mid+1,r,num,size);
        else
            return(findRank(a,l,mid-1,num,size));
    }
}