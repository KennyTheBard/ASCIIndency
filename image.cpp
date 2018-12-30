// image.cpp

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "image.h"

using namespace std;

image::image(int height, int width, int num_ch, size_t ch_size, bool big_end)
: height(height), width(width), num_channels(num_ch), channel_size(ch_size), big_endian(big_end) {
    // 'allocate' the empty bitmap
    int bitmap_size = height * width * num_ch * ch_size;
    bitmap.reserve(bitmap_size);
    for (int i = 0; i < bitmap_size; i++) {
        bitmap.push_back(0);
    }
}

image::~image() {
    // swap idiom to shed all contents and capacity
    vector<unsigned char>().swap(bitmap);
}

unsigned char* image::get_pixel(int line, int col) {
    return get_pixels(line, col, 1);
}

void image::set_pixel(int line, int col, unsigned char* px) {
    set_pixels(line, col, px, 1);
}

unsigned char* image::get_pixels(int line, int col, unsigned long num_px) {
    int start = (line * width + col) * get_pixel_size();

    unsigned char* ret = (unsigned char *) calloc (num_px * get_pixel_size(), sizeof(unsigned char));
    memcpy(ret, &bitmap + start, num_px * get_pixel_size());

    return ret;
}

void image::set_pixels(int line, int col, unsigned char* pxs, unsigned long num_px) {
    int start = (line * width + col) * get_pixel_size();

    memcpy(&bitmap + start, pxs, num_px * get_pixel_size());
}


int image::get_height() {
    return height;
}

int image::get_width() {
    return width;
}

int image::get_num_channels() {
    return num_channels;
}

int image::get_bitmap_size() {
    return height * width * num_channels * channel_size;
}

size_t image::get_channel_size() {
    return channel_size;
}

bool image::is_big_endian() {
    return big_endian;
}

size_t image::get_pixel_size() {
    return num_channels * channel_size;
}
