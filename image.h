// image.h

#ifndef IMAGE_H
#define IMAG_H

#include <vector>

using namespace std;

class image {

public:
    image(int height, int width, int num_channels, size_t channel_size);
    ~image();
    char* get_pixel(int line, int col);
    void set_pixel(int line, int col, char* px);
    int get_height();
    int get_width();
    int get_num_channels();
    size_t get_channel_size();
    size_t get_pixel_size();

private:
    vector<char> bitmap;
    int height, width;
    int num_channels;
    size_t channel_size;

};

#endif
