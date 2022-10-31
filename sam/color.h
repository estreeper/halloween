#ifndef color
#define color

struct rgb {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct hsl {
    float hue;
    float saturation;
    float luminance;
};

struct rgb hsl_to_rgb(struct hsl color_hsl);

struct hsl rgb_to_hsl(struct rgb color_rgb);

#endif