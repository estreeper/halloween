# Arduino 

I put my ideas into their own files and wrote stand alone tests. Hopefully everything is working... 

To make sure that there are no memory leaks, you may want to check out valgrind. 

## Colors 
I thought it would be helpful to use hsl space to generate color wheels 

    $ g++ -Wall -o test_color color_test.c color.c -I . 


## Sparks 
Sparks can be used to send bursts of light down the strip. 

## Issues 

### Make 
I am having trouble with my Makefile. 

### GCC 
gcc and g++ should be the same.. However I was having trouble with gcc so I switched to g++ 

