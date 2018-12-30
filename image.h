// image.h

#ifndef IMAGE_H
#define IMAG_H

#include <vector>

using namespace std;

/**
    Implementation of an abstract image type
*/
class image {


public:
    image(int height, int width, int num_channels, size_t channel_size, bool big_endian);
    ~image();

    // setters and getters for a single pixel
    unsigned char* get_pixel(int line, int col);
    void set_pixel(int line, int col, unsigned char* px);

    // setters and getters for a number of pixels
    // (more efficient than a pixel per operation for mass reading and writing)
    unsigned char* get_pixels(int line, int col, unsigned long num_px);
    void set_pixels(int line, int col, unsigned char* pxs, unsigned long num_px);

    // getters for private internal values
    int get_height();
    int get_width();
    int get_num_channels();
    int get_bitmap_size();
    size_t get_channel_size();
    bool is_big_endian();
    size_t get_pixel_size();

private:
    // container for the occupied memory
    vector<unsigned char> bitmap;

    // image dimensions
    int height, width;

    // number of color channels
    int num_channels;

    // dimension in memory of a color channel
    size_t channel_size;

    // indicates the image's endianness
    bool big_endian;
};

#endif
