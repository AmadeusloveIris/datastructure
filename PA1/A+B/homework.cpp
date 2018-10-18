//
// Created by amadeus on 18-10-17.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#define N 150010
const double pi = 3.141592653;
char s1[N>>1], s2[N>>1];
double rea[N], ina[N], reb[N], inb[N];
int ans[N>>1];

void Swap(double *x, double *y)
{
    double t = *x;
    *x = *y;
    *y = t;
}

int Rev(int x, int len)
{
    int ans = 0;
    int i;
    for(i = 0; i < len; i++){
        ans <<= 1;
        ans |= (x & 1);
        x >>= 1;
    }
    return ans;
}

void FFT(double *reA, double *inA, int n, bool flag)
{
    int s;
    double lgn = log((double)n) / log((double)2);
    int i;
    for(i = 0; i < n; i++){
        int j = Rev(i, lgn);
        if(j > i){
            Swap(&reA[i], &reA[j]);
            Swap(&inA[i], &inA[j]);
        }
    }
    for(s = 1; s <= lgn; s++){
        int m = (1<<s);
        double reWm = cos(2*pi/m), inWm = sin(2*pi/m);
        if(flag) inWm = -inWm;
        int k;
        for(k = 0; k < n; k += m){
            double reW = 1.0, inW = 0.0;
            int j;
            for(j = 0; j < m / 2; j++){
                int tag = k+j+m/2;
                double reT = reW * reA[tag] - inW * inA[tag];
                double inT = reW * inA[tag] + inW * reA[tag];
                double reU = reA[k+j], inU = inA[k+j];
                reA[k+j] = reU + reT;
                inA[k+j] = inU + inT;
                reA[tag] = reU - reT;
                inA[tag] = inU - inT;
                double rew_t = reW * reWm - inW * inWm; 
                double inw_t = reW * inWm + inW * reWm; 
                reW = rew_t;
                inW = inw_t;
            }
        }
    }
    if(flag){
        for(i = 0; i < n; i++){
            reA[i] /= n;
            inA[i] /= n;
        }
    }
}

int main()
{
#if 0
    freopen("in.txt","r",stdin);
#endif
    while(~scanf("%s%s", s1, s2)){
        memset(ans, 0 , sizeof(ans));
        memset(rea, 0 , sizeof(rea));
        memset(ina, 0 , sizeof(ina));
        memset(reb, 0 , sizeof(reb));
        memset(inb, 0 , sizeof(inb));
        int i, lent, len = 1, len1, len2;
        len1 = strlen(s1);
        len2 = strlen(s2);
        lent = (len1 > len2 ? len1 : len2);
        while(len < lent) len <<= 1;
        len <<= 1;
        for(i = 0; i < len; i++){
            if(i < len1) rea[i] = (double)s1[len1-i-1] - '0';
            if(i < len2) reb[i] = (double)s2[len2-i-1] - '0';
            ina[i] = inb[i] = 0.0;
        }
        FFT(rea, ina, len, 0);
        FFT(reb, inb, len, 0);
        for(i = 0; i < len; i++){
            double rec = rea[i] * reb[i] - ina[i] * inb[i];
            double inc = rea[i] * inb[i] + ina[i] * reb[i];
            rea[i] = rec; ina[i] = inc;
        }
        FFT(rea, ina, len, 1);
        for(i = 0; i < len; i++)
            ans[i] = (int)(rea[i] + 0.4);
        for(i = 0; i < len; i++){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
        int len_ans = len1 + len2 + 2;
        while(ans[len_ans] == 0 && len_ans > 0) len_ans--;
        for(i = len_ans; i >= 0; i--)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}
