#include <iostream>
#include <cstring>

bool stack(char *stringbuffer, char *input){
    int findindex = 0;
    int indexinsert = 0;
    while(input[findindex]!=0) {
        if (input[findindex] == '(' || input[findindex] == '{' || input[findindex] == '[') {
            stringbuffer[indexinsert] = input[findindex];
            ++indexinsert;
        }
        else if (indexinsert) {
            switch (input[findindex]) {
                case '}':
                    if (stringbuffer[indexinsert - 1] == '{') {
                        stringbuffer[--indexinsert] = 0;
                        break;
                    }
                    else {
                         return false;
                    }
                case ')':
                    if (stringbuffer[indexinsert - 1] == '(') {
                        stringbuffer[--indexinsert] = 0;
                        break;
                    }
                    else {
                         return false;
                    }
                case ']':
                    if (stringbuffer[indexinsert - 1] == '[') {
                        stringbuffer[--indexinsert] = 0;
                        break;
                    }
                    else {
                         return false;
                    }
                default:
                     return false;
            }
        }
        else {
             return false;
        }
        ++findindex;
    }
    if (stringbuffer[0]==0)
        return true;
    else
        return false;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;++i){
	char stringbuffer[50000];
        char input[100000];
        memset(stringbuffer, 0, sizeof(stringbuffer));
        scanf("%s",input);
        bool YN = stack(stringbuffer, input);
        if(YN)
            printf("Yes\n");
        else
            printf("No\n");
    }
     return 0;
}

