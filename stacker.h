/**
 * @file stacker.h
 * @author Jocelyn Ruiz
 * @date 2025-03-07
 * @brief Class definition stacker for stacking images
 *
 * This class uses private members to store the values width, height, max_color, magic_number. 
 * Uses a vector with struct Pixel to store the pixel data. Methods to read and write file data
 */
#include <vector>
#include <string>

#ifndef STACKER_H
#define STACKER_H


/**
 * reads ppm images, performs averaging for clearer image, stacks images, writing stacked image to ppm file
 *
 * @class Stacker{ stacker.h "cadia_group/stacker.h"
 * @brief class for stacking images to reduce noisy image
 *
 */
class Stacker{
 private:
  struct Pixel{
    int red;
    int green;
    int blue;
  };
  std::string magic_number;
  int width;
  int height;
  int max_color;
  std::vector<Pixel> pixels; //vector of pixel structs storing color information for the stacked image.

 public:
  Stacker();

/**
 * read image file data 
 *
 * @param const std::string& filename the name of the file that will be opened
 * @return int return 0 if everything goes smoothly
 * 
 */
  int loadImage(const std::string& filename);

/**
 * writes the image to ouput file 
 *
 * @param const std::string& filename the name of the file that the sample data will be written to
 * @return int return 0 if everything runs correctly
 * 
 */
  int outImage(const std::string& outfilename);

};
#endif //STACKER_H
