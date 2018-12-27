#ifndef FILTER_H
#define FILTER_H

#include "image.h"

image* grayscale(image* img, int* retio) {
    image* ret = new image(img->get_height(), img->get_width(), 1, img->get_channel_size());

    long sum;

    for (int i = 0; i < ret->get_height(); i++)
        for (int j = 0; j < ret->get_width(); j++) {
            sum = 0;
        }

}

#endif
