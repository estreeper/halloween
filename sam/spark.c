#include "spark.h"
#include <stdlib.h>

char faces[5] = {'>', '#', '*', 'o', 'Z'};

void set_array(char *array, int length, char value){
    /** Sets all values in an array to a given value */
    for(int i = 0; i < length; i++){
        array[i] = value;
    }
}

void init_spark(struct spark_type *spark)
{
    /** 
     * Initialize the spark object
     */
    spark->distance = 0;
    spark->value = faces[rand() % 5];
    spark->time = 0;
    spark->pace = rand() % 10 + 1; // does not change

    return; 
}

void update_spark(struct spark_type *spark){
    /** 
     * Update the spark object
     */
    spark->time += 1;
    if (spark->time > spark->pace){
        /** Move the spark forward*/
        spark->distance += 1;
        spark->time = 0; 
    }
}

void write_a_spark_to_array(struct spark_type *spark, char *array) {
    /** 
     * Write the spark object to the array
     */
    array[spark->distance] = spark->value;
}

void write_all_sparks_to_array(struct spark_type *sparks, char *array, int num_sparks){
    /** 
     * Write all the sparks objects to the array
     */
    for (int i = 0; i < num_sparks; i++){
        write_a_spark_to_array(&sparks[i], array);
    }
}

void tick_sparks(struct spark_type *sparks, int num_sparks, int array_length){
    /** 
     * Loop through the sparks and write them to the array
     */
    for(int i = 0; i < num_sparks; i++){
        update_spark(&sparks[i]);
        if(sparks[i].distance > array_length){
            init_spark(&sparks[i]);
        }
    }
}
