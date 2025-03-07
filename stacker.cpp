/**
 * @file stacker.cpp
 * @author Jocelyn Ruiz
 * @date 2025-03-07
 * @brief stacker implementation file for stacker class
 * 
 * This program reads a file stores its contents into magic_number, width, height, max_color, and pixles. 
 * Vector is used for pixel data to be stored. Then this is written to output file. 
 */

#include "stacker.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

Stacker::Stacker(){//Initializes default values for image contents
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 255;
}
int Stacker::loadImage(const std::string& filename){
  std::ifstream fimage(filename);//Open file for reading

  if (!fimage) {
    std::cerr << "Error in opening file" << std::endl;
    return 1;//return 1 if file cannot be opened
  }
  //read the header of the file
  fimage >> magic_number;

  fimage >> width >>height >>max_color;

  //following reads the pixel data
  Pixel pixel;

  for (int i = 0; i < width * height; i++){
    fimage >> pixel.red >> pixel.green >> pixel.blue;
    pixels.push_back(pixel);
  }
  fimage.close();
  return 0;// return success

}

int Stacker::outImage(const std::string& outfilename){
  std::ofstream file(outfilename);//open file for writing

  if(!file){
    std::cerr << "Error" << std::endl;
    return 1;
  }
  //writes the ppm header
  file << magic_number << "\n";

  file << width << " " << height << "\n";

  file << max_color << "\n";

  //writes the pixel data to output file
  for(int i = 0; i < width*height; i++){
    file <<pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << "\n";
  }
  file.close();
  return 0;//return success
}
