#ifndef DECODE_H
#define DECODE_H

#include "image.h"

#define BYTE_MAX_VALUE

/**
    Returns the smaller size of a data type
    required to hold the given value
*/
size_t maxVal2size(unsigned long long maxVal) {
    size_t size = 0;

    while (maxVal != 0) {
        maxVal /= BYTE_MAX_VALUE;
        size ++;
    }

    return size;
}

/**
    Decodes Netpbm formats into an image instance.
    Current Netpbm formats: PNM, PGM.
*/
image* decode_netpbm(FILE *in) {
    char type;
    int width, height;
    unsigned int maxVal;

    fscanf(in, "P%c %d %d %d ", &type, &width, &height, &maxVal);

    // instancing an image for either PNM or PGM format
    image *img = new image(height, width, (type == '6' ? 3 : 1), maxVal2size((unsigned long long) maxVal), false);

    int pixels_per_line = img->get_pixel_size() * img->get_width();
    unsigned char *line = (unsigned char *) malloc (pixels_per_line);

    for (int i = 0; i < img->get_height(); i++) {
        fread(pixels, sizeof(unsigned char), pixels_per_line, in);
        img->set_pixels(i, 0, pixels, pixels_per_line);
    }

    fclose(in);
    return img;
}

#endif
