#include "color.h"
#include <stdio.h>
#include <assert.h>


void test_hsl_to_rgb(){
    struct hsl color_hsl;

    // Test Light pink 
    color_hsl.hue = 0;
    color_hsl.saturation = 0.5;
    color_hsl.luminance = 0.74;
    struct rgb color_rgb = hsl_to_rgb(color_hsl);

    assert(color_rgb.red == 221);
    assert(color_rgb.green == 155);
    assert(color_rgb.blue == 155);
    
    // Test light blue (180 degrees on the color wheel)
    color_hsl.hue = 0.5;
    color_hsl.saturation = 0.5;
    color_hsl.luminance = 0.74;
    color_rgb = hsl_to_rgb(color_hsl);

    assert(color_rgb.red == 155);
    assert(color_rgb.green == 221);
    assert(color_rgb.blue == 221);

    printf("test_hsl_to_rgb passed\n");
}

void test_rgb_to_hsl(){
    struct rgb color_rgb;

    // Test Light pink 
    color_rgb.red = 221;
    color_rgb.green = 155;
    color_rgb.blue = 155;
    struct hsl color_hsl = rgb_to_hsl(color_rgb);

    assert(color_hsl.hue == 0);
    assert(color_hsl.saturation > 0.49 && color_hsl.saturation < 0.51);
    assert(color_hsl.luminance > 0.73 && color_hsl.luminance < 0.75);
 
    
    // Test light blue (180 degrees on the color wheel)
    color_rgb.red = 155;
    color_rgb.green = 221;
    color_rgb.blue = 221;
    color_hsl = rgb_to_hsl(color_rgb);

    assert(color_hsl.hue == 0.5);
    assert(color_hsl.saturation > 0.49 && color_hsl.saturation < 0.51);
    assert(color_hsl.luminance > 0.73 && color_hsl.luminance < 0.75);

    printf("test_rgb_to_hsl passed\n");
}

    int main(int **argv, int argc){

  printf("Startinng tests\n");

  test_hsl_to_rgb();
  test_rgb_to_hsl(); 

  printf("Testing over");

  return 0;
}
