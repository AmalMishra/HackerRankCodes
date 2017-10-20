#include <stdio.h>
#include <mem.h>

int main() {

    int n,k,count=0;
    scanf("%d %d",&n,&k);

    int num[n], rem[k];
    memset(num,0,n*sizeof(int));
    memset(rem,0,k*sizeof(int));

    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);

    for(int i=0;i<n;i++)
        rem[num[i]%k]++;

    if(rem[0]!=0)
        count=1;

    for(int i=1,j=k-1;i<=j;i++,j--){
        if(rem[i]>= rem[j] && i!=j)
            count+= rem[i];

        else if(i==j && rem[i]!=0)
            count++;
        else
            count+= rem[j];
    }
    if(count==0)
        printf("%d",1);
    else
        printf("%d",count);

    return 0;
}