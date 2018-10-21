/*************************************************************************
 @Author: amadeus
 @Created Time : 2018年10月20日 星期六 09时50分56秒
 @File Name: baoli.cpp
 @Description:
 ************************************************************************/
#include <iostream>
#include <cstring>

int main(){
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int buffer[n];
    memset(buffer, 0, sizeof(int)*n);
    int timesreadmemory = 0;
    int bufferind = 0;
    for (int i = 0; i < m; ++i){
        int tmp;
        scanf("%d", &tmp);
        bool find_or_not = false;
        for (int l = 0; l < n; ++l){
            if (tmp == buffer[l]){
                find_or_not = true;
                break;
            }
        }
        if (!find_or_not){
            if (bufferind == n)
                bufferind = 0;
            ++timesreadmemory;
            buffer[bufferind]=tmp;
            ++bufferind;
        }
    }
    printf("%d",timesreadmemory);
    return 0;
}
