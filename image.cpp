// image.cpp

#include <cstdlib>
#include "image.h"

using namespace std;

image::image(int height, int width, int num_ch, size_t ch_size)
: height(height), width(width), num_channels(num_ch), channel_size(ch_size) {
    // 'allocate' the empty bitmap
    int bitmap_size = height * width * num_ch * ch_size;
    bitmap.reserve(bitmap_size);
    for (int i = 0; i < bitmap_size; i++) {
        bitmap.push_back(0);
    }
}

image::~image() {
    // swap idiom to shed all contents and capacity
    vector<char>().swap(bitmap);
}

char* image::get_pixel(int line, int col) {
    char* ret = (char *) calloc (get_pixel_size(), sizeof(char));

    int start = (line * width + col) * get_pixel_size();
    int end = (line * width + col) * get_pixel_size() + get_pixel_size();
    for (int i = start; i < end; i++)
        ret[i - start] = bitmap[i];

    return ret;
}

void image::set_pixel(int line, int col, char* px) {
    // TODO : choose a safer alternative for pointer

    int start = (line * width + col) * get_pixel_size();
    int end = (line * width + col) * get_pixel_size() + get_pixel_size();
    for (int i = start; i < end; i++)
        bitmap[i] = px[i - start];
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

size_t image::get_channel_size() {
    return channel_size;
}

size_t image::get_pixel_size() {
    return num_channels * channel_size;
}