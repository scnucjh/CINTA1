// 
#include <iostream>
#include <cstring> 
using namespace std;
 
const int N = 112;
long long mat[N][N];
int n;
 
const int memosize = sizeof(mat[0]);
 
int sub(int i,int j,int k,int n) {
    for(int v=0;v<=n;v++) mat[j][v] -= mat[i][v]*k; 
}
 
void swapline(int i,int j,int n) {
    for(int v=0;v<=n;v++) swap(mat[i][v],mat[j][v]);
}
 
void swap_zeros_up(int n) {
    for(int i=0;i<n;i++) {
        if(mat[i][n]==0) continue;
        int j=i+1;
        while(j<n && mat[j][n]) j++;
        if(j==n) return;
        swapline(i,j,n);
    }
}
 
void shift_matrix(int n) {
    long long tmpmemo[N];
    memcpy(tmpmemo,mat[0],sizeof(tmpmemo));
    for(int i=1;i<n;i++) {
        memcpy(mat[i-1],mat[i],sizeof(tmpmemo));
    }
    memcpy(mat[n-1],tmpmemo,sizeof(tmpmemo));
}

 
int egcdn(int n,long long *a, long long *b) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            mat[i][j] = (i==j);
        }
        mat[i][n] = a[i];
    }
    while(true) {
        swap_zeros_up(n);
        int i=0;
        while(i+1<n && mat[i][n]==0) i++;
        if(i==n-1) {
            for(int i=0;i<n;i++) b[i] = mat[n-1][i];
            return mat[n-1][n];
        }
        for(int j=i+1;j<n;j++) {
            sub(i,j,mat[j][n]/mat[i][n],n);
        }
        shift_matrix(n);
    } 
} 
 
long long a[111], b[111];
 
 
int main() { 
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long d = egcdn(n,a,b);
    for(int i=0;i<n;i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
