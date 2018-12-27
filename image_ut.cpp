// image_ut.cpp <UNIT TEST>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "image.h"

using namespace std;




image* readImage(const char * fileName, image *img) {


    char buff[16];

    FILE *fp;

    fp = fopen(fileName, "rb");

    fgets(buff, sizeof(buff), fp);
         

    char type = buff[1];

 
    int width;
    int height;
    char maxVal;

    fscanf(fp, "%d %d", &width, &height);
  

    fscanf(fp, "%hhu", &maxVal); 
  

     img = new image(height, width, 1, 3,maxVal,type);   

    //if the image is pnm
    if(img->get_type() == '6'){
  
        while (fgetc(fp) != '\n');

        img->pixels = (unsigned char *)malloc(img->get_channel_size() *img->get_width() * img->get_height() * sizeof(unsigned char));
            
        fread(img->pixels,  sizeof(unsigned char), img->get_channel_size() *img->get_width() * img->get_height(), fp);
        

    } 
   
    fclose(fp);
    return img;
    
    
}


void writeImage(const char * fileName, image *img) {


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


int main(int argc, char * argv[]) {
    image *img = new image(5, 5, 3, 3,255,6);

    unsigned char* px = (unsigned char *) calloc (img->get_pixel_size(), sizeof(unsigned char));
    for (int i = 0; i < img->get_pixel_size(); i++)
        px[i] = i + '0';
    img->set_pixel(2, 2, px);


    px = img->get_pixel(2, 2);
    cout << "[ ";
    for (int i = 0; i < img->get_pixel_size(); i++)
        cout << px[i] << " ";
    cout << "]" << endl;


    img = readImage(argv[1], img);

    writeImage(argv[2], img);

    return 0;
}
