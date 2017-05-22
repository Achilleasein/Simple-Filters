#include <cstdlib>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MEM_SIZE 32

int main(){
int measurments[5000] = {0};    
int memory[MEM_SIZE][1] = {0};
int result[1][5000] = {0};
int result_shift[1][5000] = {0};
int avg = 0;
int k = 1, i;
    for(i = 1; i <= 5000 ; i++){
        avg = avg + measurments[i];
        avg = avg - memory[k][1];
        memory[MEM_SIZE][k] = measurments[i];
        if (k == MEM_SIZE){k = 0;}

        k = k + 1;
        result[1][i] = avg/MEM_SIZE;    
        result_shift[1][i] >>= 5;
    }
    return 0;
}

