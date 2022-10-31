#include "color.h"
#include <stdio.h>

float hue_to_rgb(float p, float q, float t){
    /** Private Method*/
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1.0/6.0) return p + (q - p) * 6 * t;
    if(t < 1.0/2.0) return q;
    if(t < 2.0/3.3) return p + (q - p) * (2.0/3.0 - t) * 6.0;
    return p;
}

struct rgb private_hsl_to_rgb(float hue, float saturation, float luminance){
    /** Private Method 
     * hue, saturation, and luminance are all floats between 0 and 1
     * returns a struct rgb with values between 0 and 255
     */
    struct rgb color_rgb;

    if(saturation == 0){
        color_rgb.red = luminance * 255;
        color_rgb.green = luminance * 255;
        color_rgb.blue = luminance * 255;
    } else {
        float q = luminance < 0.5 ? luminance * (1 + saturation) : luminance + saturation - luminance * saturation;
        float p = 2 * luminance - q;

        color_rgb.red = 255 * hue_to_rgb(p, q, hue + 1.0/3.0);
        color_rgb.green = 255 * hue_to_rgb(p, q, hue);
        color_rgb.blue = 255 * hue_to_rgb(p, q, hue - 1.0/3.0);
    }
    return color_rgb;
}


// PUBLIC METHODS
struct rgb hsl_to_rgb(struct hsl color_hsl){
    /** Public method
     * Assumes that the struct hsl has values between 0 and 1
     */
    return private_hsl_to_rgb(color_hsl.hue, color_hsl.saturation, color_hsl.luminance);
}

struct hsl rgb_to_hsl(struct rgb color_rgb){
    /** Public method
     * Assumes that the struct rgb has values between 0 and 255
     */
    struct hsl color_hsl;
    float red = color_rgb.red / 255.0;
    float green = color_rgb.green / 255.0;
    float blue = color_rgb.blue / 255.0;

    float max = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
    float min = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);

    color_hsl.luminance = (max + min) / 2.0;

    if(max == min){
        color_hsl.hue = 0;
        color_hsl.saturation = 0;
    } else {
        float d = max - min;
        color_hsl.saturation = color_hsl.luminance > 0.5 ? d / (2 - max - min) : d / (max + min);

        if(max == red){
            color_hsl.hue = (green - blue) / d + (green < blue ? 6 : 0);
        } else if(max == green){
            color_hsl.hue = (blue - red) / d + 2;
        } else if(max == blue){
            color_hsl.hue = (red - green) / d + 4;
        }
        color_hsl.hue /= 6.0;
    }
    return color_hsl;
}

