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
        int l = 0;
        while (l < N){
            if(query1[i] > a[l] || query2[i] > b[l]){
                ++l;
                continue;
            }
            else if ((long double)query1[i]/a[l] + (long double)query2[i]/b[l] < 1) {
                printf("%d\n", l);
                break;
            }
            else
                ++l;
        }
        if (l == N)
            printf("%d\n",l);
    }
    return 0;
}
