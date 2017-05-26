#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MEM_SIZE  32  // Here we define the size of the memoryu
#define DATA_SIZE 5000// In case you give the function a set base of data, here you can set its size
#define TOTAL_SHIFTS 5// The shifts can be calculate with a module, but since this code wont be modified much after you find its usage, I didnt think it was worth putting it in

int main(){
// Bellow we have the input, if not for usage on live data 
int measurments[DATA_SIZE] = {0};    
int memory[MEM_SIZE][1] = {0};
int result[DATA_SIZE] = {0};
int result_shift[DATA_SIZE] = {0};
int avg = 0;
int circular_counter = 1, i;
    for(i = 1; i <= DATA_SIZE ; i++){
        /* Adding the new value and substracting the old*/
        avg = avg + measurments[i]; 
        avg = avg - memory[k];
        result_shift[i] = avg;
        /**********************************/
        memory[circular_counter] = measurments[i]; //We store the values in a circular manner so we need O(1) operation each time
        if (circular_counter == MEM_SIZE){circular_counter = 0;} // We reset the circular counter to navigate properly the array
        circular_counter = circular_counter + 1;
        
        // Below I calculate the same thing in two different ways so you can see that on processors with few bits shifting 
        // is giving us more accuracy and its way faster to do, due to the design of the processors
        result[i] = avg/MEM_SIZE;    
        result_shift[i] >>= TOTAL_SHIFTS;
    }
    return 0;
}

