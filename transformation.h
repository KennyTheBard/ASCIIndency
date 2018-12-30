#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <vector>

#include "image.h"

#define BYTE_SIZE 8

unsigned long long int cast_from_bytes(unsigned char* v, size_t num_chars, bool big_endian) {
    unsigned long long int ret = 0;
    int start, end;

    if (big_endian) {
        ret = v[0];
        for (int i = 1; i < num_chars; i++) {
            ret <<= BYTE_SIZE;
            ret |= v[i];
        }
    } else {
        ret = v[num_chars - 1];
        for (int i = num_chars - 2; i >= 0; i--) {
            ret <<= BYTE_SIZE;
            ret |= v[i];
        }
    }

    return ret;
}

unsigned char* cast_to_bytes(unsigned long long int v, size_t num_chars, bool big_endian) {
    unsigned char* ret = (unsigned char*) calloc (num_chars, sizeof(unsigned char));
    int i, ind;

    if (big_endian) {
        i = num_chars - 1;
        ind = -1;
    } else {
        i = 0;
        ind = 1;
    }

    unsigned char ch;
    for (int k = 0; k < num_chars; k++) {
        ch = v;
        ret[i] = ch;
        v >>= BYTE_SIZE;
        i += ind;
    }

    return ret;
}

/**
    Returns the grayscale of an image
    ratio - vector of ratios for each color channel
    the sum of the element in ratio must be lower or equal with 1
*/
image* grayscale(image* img, vector<float> ratio) {
    image* ret = new image(img->get_height(), img->get_width(), 1, img->get_channel_size());

    for (int y = 0; y < ret->get_height(); y++)
        for (int x = 0; x < ret->get_width(); x++) {
            unsigned long long int aux = 0;

            unsigned char* px = img->get_pixel(y, x);
            for (int i = 0; i < img->get_pixel_size(); i += img->get_channel_size()) {
                aux += ratio[i] * cast_from_bytes(px + i, img->get_channel_size(), img->is_big_endian());
            }

            ret->set_pixel(y, x, cast_to_bytes(aux, img->get_channel_size(), img->is_big_endian()));
        }

    return ret;
}

#endif
