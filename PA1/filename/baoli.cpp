#include <iostream>

class LCS{
private:
    char *namen;
    char *namem;
    const int K;//dont less than this
    const int M;
    const int N;
    int *evaluation;
    size_t index(int column, int row) const;
public:
    LCS(int n, int m, int k);
    int blast();
};

LCS::LCS(int n, int m, int k): K(k), M(m), N(n)
{
    namem = new char[m];
    namen = new char[n];
    scanf("%s",namen);
    scanf("%s",namem);
    evaluation = new int[(n+1) * (m+1) * sizeof(int) ];
}

size_t LCS::index(int column, int row) const {
    return (column+1) + sizeof(int)*N*(row+1);
}

int LCS::blast() {
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if(namen[i]!=namem[j])
                evaluation[index(i,j)] = evaluation[index(i-1,j)] > evaluation[index(i,j-1)] ? evaluation[index(i-1,j)] : evaluation[index(i,j-1)];
            else
                evaluation[index(i,j)] = evaluation[index(i-1,j-1)]+1;
        }
    }
    if(evaluation[index(N-1,M-1)]<K)
        return -1;
    else
        return N+M-2*evaluation[index(N-1,M-1)];
}

int main() {
    int n,m,kmost;
    scanf("%d %d %d",&n,&m,&kmost);
    int k = (n+m-kmost)/2;
    LCS compare(n,m,k);
    printf("%d",compare.blast());
    return 0;
}
