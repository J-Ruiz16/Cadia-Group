/**
 * @file stacker.cpp
 * @author Jocelyn Ruiz
 * @date 2025-03-07
 * @brief Implementation of the Stacker class for stacking PPM images.
 *
 * This program reads multiple PPM files, averages their pixel values, 
 * and writes the final stacked image to a new PPM file.
 */

 #include "stacker.h"
 #include <vector>
 #include <fstream>
 #include <string>
 #include <iostream>
 #include <sstream>
 
 Stacker::Stacker() {//Intializes default values for image contents
     magic_number = "";
     width = 0;
     height = 0;
     max_color = 255;
     image_count = 0;
 }
 
 int Stacker::loadImage(const std::string& filename) {
     std::ifstream fimage(filename); //Open file for reading
     
     if (!fimage) {
         std::cerr << "Error in opening file " << std::endl;
         return 1; //return 1 if file cannot be opened
     }
 
     // read the header of the file
     std::string file_magic_number;
     int file_width, file_height, file_max_color;
     
     fimage >> file_magic_number >> file_width >> file_height >> file_max_color;
 
     if (magic_number.empty()) {
         //first image sets these values
         magic_number = file_magic_number;
         width = file_width;
         height = file_height;
         max_color = file_max_color;
         pixels.resize(width * height, {0, 0, 0}); 
         //initialize all pixels to zero
     } 
 
     //read and accumulate pixel values
     for (int i = 0; i < width * height; i++) {
         int r, g, b;
         fimage >> r >> g >> b;
 
         pixels[i].red += r;
         pixels[i].green += g;
         pixels[i].blue += b;
     }
 
     fimage.close();
     image_count++;
     return 0; // return success
 }
 
 int Stacker::outImage(const std::string& outfilename) {
     std::ofstream file(outfilename); //open file for writing
     
     if (!file) {
         std::cerr << "Error " << std::endl;
         return 1;
     }
 
     // writes the ppm header
     file << magic_number << "\n";

     file << width << " " << height << "\n";

     file << max_color << "\n";

 
     // write the averaged pixel data to output file
     for (int i = 0; i < width * height; i++) {
         file << pixels[i].red / image_count << " "
              << pixels[i].green / image_count << " "
              << pixels[i].blue / image_count << "\n";
     }
 
     file.close();
     return 0; // return success
 }
 
 int Stacker::stackImage(const std::string& infilename, int numImage) {
     std::cout << "Stacking images:" << std::endl;
 
     for (int i = 1; i <= numImage; i++) {
         std::ostringstream filename;
         filename << infilename << "/" << infilename << "_"
                  << (i < 10 ? "00" : "0") << i << ".ppm";
 
         std::cout << "    " << filename.str() << std::endl;
 
         if (loadImage(filename.str()) != 0) {
             return 1; 
         }
     }
 
     std::string read_filename = infilename + ".ppm";
     return outImage(read_filename);
 }
 
