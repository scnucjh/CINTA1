#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a,int b) {
    while(a%b) {
        int c = a%b;
        a = b; b = c;
    }
    return b;
}

int bgcd(int a,int b) {
    if(a==b) return a;
    if(!a) return b;
    if(!b) return a;
    if(!(a&1)) return b&1 ?  bgcd(a>>1,b) : bgcd(a>>1,b>>1)<<1;
    if(!(b&1)) return bgcd(a,b>>1);
    return a>b ? bgcd((a-b)>>1,b) : bgcd((b-a)>>1,a);
}

int bgcd2(int a,int b) {
    if(a==b) return a;
    if(!a) return b;
    if(!b) return a;
    int d = 0, temp;
    while(!(a&1) && !(b&1)) a>>=1, b>>=1, d++;
    while(a) {
        while(!(a&1)) a>>=1;
        if(a<b) temp = a, a = b, b = temp;
        a = a-b;
    }
    return b<<d;
}

int ebgcd(int a,int b,int *s,int *t) {
    int r0 = a, r1 = b, e = 0;
    while( (~r0&1) &&(~r1&1) ) {
        r0>>=1, r1>>=1 , e++;
    }
    int A = r0, B = r1;
    int s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    while(r1) {
        while((~r0&1)) {
            r0>>=1;
            if((~s0&1)  && (~t0&1)) {
                s0 >>= 1, t0 >>= 1;
            }else {
                s0 = (s0 + B)>>1, t0 = (t0-A)>>1; 
            }
        }
        while((~r1&1)) {
            r1>>=1;
            if((~s1&1) && (~t1&1)) {
                s1 >>= 1, t1>>=1;
            }else {
                s1 = (s1 + B)>>1, t1 = (t1-A)>>1;
            }
        } 
        if(r1<r0) {
            int tmp;
            tmp = r0, r0 = r1, r1 = tmp;
            tmp = s0, s0 = s1, s1 = tmp;
            tmp = t0, t0 = t1, t1 = tmp;
        }
        r1 -= r0;
        s1 -= s0;
        t1 -= t0;
    }
    *s = s0, *t = t0;
    return (1<<e) * r0;
}


int main() {
    srand(time(NULL));
    for(int i=0;i<100;i++) {
        int a = rand()%100000, b = rand()%100000;
        int x,y;
        int d = ebgcd(a,b,&x,&y);
        printf("%d %lld\n",d ,1ll * a * x + 1ll * b  * y);
    }
    return 0;
}