#include <iostream>
#include <cstring>


int half_find(const int *buffer_filter, bool &find_or_not ,const int &key, int begininedx, int endindex){
    int mid = (endindex + begininedx)/2;
    if (begininedx > endindex){
        if(endindex == 0)
            return 0;
        else
            return endindex;
    }
    else if (key > buffer_filter[mid]){
        if (key < buffer_filter[mid+1]){
            return mid;
        }
        else
            half_find(buffer_filter, find_or_not, key, mid + 1, endindex);
    }
    else if (key < buffer_filter[mid]) {
        if (key > buffer_filter[mid - 1])
            return --mid;
        else
            half_find(buffer_filter, find_or_not, key, begininedx, mid-1);
        }
    else{
        find_or_not = true;
        return mid;
    }
}

int half_mustfind(const int *buffer_filter, const int &key, int begininedx, int endindex){
    int mid = (endindex + begininedx)/2;
    if (key > buffer_filter[mid])
            half_mustfind(buffer_filter, key, mid + 1, endindex);
    else if (key < buffer_filter[mid])
            half_mustfind(buffer_filter, key, begininedx, mid-1);
    else
        return mid;
}

void remove(int *buffer_sort, int inserted, int del, const int &key){
    if(inserted > del){
        for (int i = del; i < 1+inserted; ++i){
            buffer_sort[i]=buffer_sort[i+1];
        }
        buffer_sort[inserted]=key;
    }
    else if(inserted < del){
        for (int i = del; i > 1+inserted; --i){
            buffer_sort[i] = buffer_sort[i-1];
        }
        buffer_sort[inserted+1]=key;
    }
    else{
        buffer_sort[inserted] = key; 
    }
}

int main(){
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int buffer[n];
    int buffer_sort[n+2];
    memset(buffer, 0, sizeof(int)*n);
    memset(buffer_sort, 0, sizeof(int)*(n+2));
    buffer_sort[n+1]=999;
    int timesreadmemory = 0;
    int bufferind = 0;
    for (int i = 0; i < m; ++i){
        int tmp;
        scanf("%d", &tmp);
        bool find_or_not = false;
        int dex = half_find(buffer_sort, find_or_not, tmp, 1, n);
        if(!find_or_not) {
            ++timesreadmemory;
            if(bufferind == n)
                bufferind = 0;
            int replace = half_mustfind(buffer_sort, buffer[bufferind], 1, n);
            buffer[bufferind] = tmp;
            ++bufferind;
            remove(buffer_sort, dex, replace, tmp);
        }
    }
    printf("%d",timesreadmemory);
    return 0;
}
