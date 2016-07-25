#include <stdio.h>
#define mod 1000000007
const int MAX = 2;
typedef  struct{
        long long  m[MAX][MAX];
}Matrix;
Matrix P = {1,1,1,0};
Matrix I = {1,0,0,1};
Matrix matrixmul(Matrix a,Matrix b){
       int i,j,k;
       Matrix c;
       for (i = 0 ; i < MAX; i++)
           for (j = 0; j < MAX;j++)
             {
                 c.m[i][j] = 0;
                 for (k = 0; k < MAX; k++){
                 	c.m[i][j] += (a.m[i][k] * b.m[k][j]);
                    c.m[i][j] %= 1000000007;
                 }
             }
       return c;
}
Matrix quickpow(long long n){
       Matrix m = P, b = I;
       while (n >= 1){
             if (n & 1)
                b = matrixmul(b,m);
             n = n >> 1;
             m = matrixmul(m,m);
       }
       return b;
}
int main()
{
    Matrix re;
    int f[3] = {0,1,1};
    long long n;
    while (scanf("%lld",&n)!=EOF){
        if (n <= 2)
        printf("%d\n",f[n]);
        else {
            re = quickpow(n - 2);
            printf("%lld\n",((re.m[0][0]*f[2])
            +(re.m[0][1]*f[1]))%1000000007);
        }
    }
    return 0;
}
