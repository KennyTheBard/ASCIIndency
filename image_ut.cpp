// image_ut.cpp <UNIT TEST>

#include <iostream>
#include <cstdlib>
#include <vector>

#include "image.h"

using namespace std;

int main() {
    image* img = new image(5, 5, 3, 3);

    char* px = (char *) calloc (img->get_pixel_size(), sizeof(char));
    for (int i = 0; i < img->get_pixel_size(); i++)
        px[i] = i + '0';
    img->set_pixel(2, 2, px);

    px = img->get_pixel(2, 2);
    cout << "[ ";
    for (int i = 0; i < img->get_pixel_size(); i++)
        cout << px[i] << " ";
    cout << "]" << endl;

    return 0;
}
