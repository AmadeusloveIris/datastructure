#include <iostream>

int compi(const void *a, const void *b)
{
    const long long *p = (long long *)a;
    const long long *q = (long long *)b;
    if (*p > *q)
        return 1;
    else if (*p < *q)
        return -1;
    else
        return 0;
}

int binsearch(const long long *a, const long long *b, const long long &m, const long long &n, int start, int end, int &N){
    int middle = (end + start) / 2;
    if (start > end){
        if ((long double)m/a[middle] + (long double)n/b[middle] < 1) {
            return 0;
        }
        else if ((long double)m/a[middle] + (long double)n/b[middle] > 1) {
            return N;
        }
    }
    else if ((long double)m/a[middle] + (long double)n/b[middle] > 1) {
        if ((long double)m/a[middle+1] + (long double)n/b[middle+1] < 1)
            return middle+1;
        else
            binsearch(a,b,m,n,middle+1,end,N);
    }
    else if ((long double)m/a[middle] + (long double)n/b[middle] < 1){
        if ((long double)m/a[middle-1] + (long double)n/b[middle-1] > 1)
            return middle;
        else
            binsearch(a,b,m,n,start,middle-1,N);
    }
    else
        return middle+1;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    if (!N)
        return 0;
    long long a[N];
    long long b[N];

    for (int i = 0; i < N; ++i){
        scanf("%lld",&a[i]);
    }
    for (int i = 0; i < N; ++i){
        scanf("%lld",&b[i]);
    }

    int M = 0;
    scanf("%d",&M);
    if (!M)
        return 0;
    long long query1[M];
    long long query2[M];

    for (int i = 0; i < M; ++i){
        scanf("%lld",&query1[i]);
        scanf("%lld",&query2[i]);
    }

    qsort(a, N, sizeof(a[0]), compi);
    qsort(b, N, sizeof(a[0]), compi);

    for (int i = 0; i < M ; ++i){
        printf("%d\n",binsearch(a, b, query1[i], query2[i] , 0, N-1,N));
    }
    return 0;
}
