// image_ut.cpp <UNIT TEST>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "image.h"

using namespace std;

int main(int argc, char * argv[]) {
    // TODO : divide testes in more functions and call each one of them
    image *img = new image(2, 2, 3, 1);

    cout << "height = " << img->get_height() << endl;
    cout << "width = " << img->get_width() << endl;
    cout << "num_channels = " << img->get_num_channels() << endl;
    cout << "channel_size = " << img->get_channel_size() << endl;
    cout << "pixel_size = " << img->get_pixel_size() << endl;

    unsigned char *px = (unsigned char *) calloc (img->get_pixel_size() * img->get_width(), sizeof(unsigned char));
    px[0] = 'r';
    px[1] = 'g';
    px[2] = 'b';

    for (int i = 0; i < img->get_height(); i++)
        for (int j = 0; j < img->get_width(); j++) {
            img->set_pixel(i, j, px);
        }

    // there are some buggs in set_pixels/ set_pixels

    unsigned char *line = img->get_pixels(0, 0, img->get_width());

    for (int i = 0; i < img->get_pixel_size() * img->get_width(); i++)
        cout << line[i] << " ";

    cout << endl;

    return 0;
}
