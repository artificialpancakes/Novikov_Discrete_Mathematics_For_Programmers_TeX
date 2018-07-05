#include<stdio.h>

void S(int x){
        printf("%d", x);
};

int main(){
        int n;
        scanf("%d", &n);
        int X[n];
        int Y[n];
        for(int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                        if(X[x] == Y[y])
                                S(x);           // Тело цикла
                                break;          // Следующий х
                }
        }
        return 0;
}

