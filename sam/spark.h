#ifndef spark2
#define spark2

struct spark_type
{
    char value; // value to print
    
    unsigned char distance; // index in the array 
    unsigned char pace; // inverse of speed -- time/distance
    unsigned char time; 
};

void set_array(char *array, int length, char value);

void init_spark(struct spark_type *spark);

void update_spark(struct spark_type *spark);

void write_a_spark_to_array(struct spark_type *spark, char *array);

void write_all_sparks_to_array(struct spark_type *sparks, char *array, int num_sparks); 

void tick_sparks(struct spark_type *sparks, int num_sparks, int array_length);

#endif