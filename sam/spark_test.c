#include "spark.h"
#include <stdio.h>
#include <unistd.h>



void print_array(char *array, int length){
    /** Prints an array of characters */
    for(int i = 0; i < length; i++){
        printf("%c", array[i]);
    }
    printf("\n");
}


void loop_n(struct spark_type* sparks, char* array, int spark_legth, int array_length, int n){ 
    for(int i = 0; i < n; i++){
        set_array(array, array_length, '.');
        tick_sparks(sparks, spark_legth, array_length);
        write_all_sparks_to_array(sparks, array, spark_legth);
        print_array(array, array_length);

        // Sleep for a second 
        //sleep(1);
    }
}


int main(void) {
    /** basic */
    struct spark_type sparks[10];
    char array[80];
    for(int i = 0; i < 10; i++){
        /** setup */
        init_spark(&sparks[i]);
    }

    loop_n(sparks, array, 10, 80, 1000);

    
    return 0;
}