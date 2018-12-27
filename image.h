// image.h

#ifndef IMAGE_H
#define IMAG_H

#include <vector>

using namespace std;

class image {

public:
    image(int height, int width, int num_channels, size_t channel_size, unsigned char maxValue, char type);
    ~image();

    unsigned char* get_pixel(int line, int col);
    void set_pixel(int line, int col, unsigned char* px);

    unsigned char* get_pixels(int line, int col, int num_px);
    void set_pixels(int line, int col, unsigned char* pxs, int num_px);

    int get_height();
    int get_width();
    int get_num_channels();
    int get_bitmap_size();
    size_t get_channel_size();
    size_t get_pixel_size();
    unsigned char get_max_value();
    char get_type();
    
    unsigned char *pixels;

private:
    vector<unsigned char> bitmap;
    int height, width;
    int num_channels;
    size_t channel_size;
    unsigned char maxValue;
    char type;

};

#endif
