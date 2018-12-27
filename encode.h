#ifndef ENCODE_H
#define ENCODE_H

#include "image.h"

#define BYTE_MAX_VALUE

void encode_netpbm(const char * fileName, image *img) {
    // TODO : implement the encoding for netpbm
    FILE *fp;

    fp = fopen(fileName, "wb");

    fprintf(fp, "P%c\n",img->get_type());

    fprintf(fp, "%d %d\n",img->get_width(),img->get_height());


    fprintf(fp, "%u\n",img->get_max_value());


    if(img->get_type() == '6'){

        fwrite(img->pixels, sizeof(unsigned char),img->get_channel_size() *img->get_width() * img->get_height(), fp);

    }


    fclose(fp);

}

#endif
