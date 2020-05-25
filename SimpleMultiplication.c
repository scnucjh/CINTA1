#include <stdio.h>

int mul1(int x,int y) {
    int result = 0;
    while(y) {
        if(y&1) result += x;
        x<<=1; y>>=1;
    }
    return result;
}

int mul2(int x,int y) {
    return y ? y&1? (mul2(x,y>>1)<<1) + x :  mul2(x,y>>1)<<1 : 0;
}

int main() {
    int x = 2333, y = 6666;
    printf("%d %d\n",mul1(x,y),mul2(x,y));
    printf("answer is %d\n",x*y);
    return 0;
}