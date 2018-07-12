#include<stdio.h>

int main(){
        int n, m;
        scanf("%d%d", &n, &m);
        int A[m + 1];
        for(int i = 1; i <= m; i++){
                A[i] = i;
        }
        if(m == n){
                for(int i = 1; i <= n; i++)
                        printf("%d ", A[i]);
                printf("\n");
        }
        int p = n;
        while(p >= 0){
                for(int i = 1; i <= n; i++)
                        printf("%d ", A[i]);
                printf("\n");
                if(A[n] == m)
                        p--;
                else
                        p = n;
                if(p >= 1){
                        for(int i = n; i >= p; i--){
                                A[i] = A[p] + i - p + 1;
                        }
                }
        }
        return 0;
}




