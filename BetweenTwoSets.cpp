//
// Created by drStrange on 9/6/2017.
//

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    int gd=gcd(a,b);
    int l= (a*b)/gd ;
    return l;
}

int getTotalX(int a_size, int* a, int b_size, int* b) {
    int hcf=b[0],lm=a[0];
    int count=0;
    for(int i=0;i<b_size;i++){
        if(b[i] % hcf !=0 )
            hcf= gcd(hcf,b[i]);
    }

    for(int i=0;i<a_size;i++){
        if(lm%a[i] !=0 )
            lm= lcm(lm,a[i]);
    }

    if( hcf % lm != 0)
        return 0;
    else{
        for(int i=lm;i<=hcf;i=i+lm){
            if(hcf % i == 0)
                count++;
        }
        return (count);
    }

}



int main() {
    int n;
    int m;
    scanf("%i %i", &n, &m);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
        scanf("%i",&a[a_i]);
    }
    int *b = (int *)malloc(sizeof(int) * m);
    for (int b_i = 0; b_i < m; b_i++) {
        scanf("%i",&b[b_i]);
    }
    int total = getTotalX(n, a, m, b);
    printf("%d\n", total);
    return 0;
}
