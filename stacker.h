/**
 * @file stacker.h
 * @author Jocelyn Ruiz
 * @date 2025-03-07
 * @brief Class definition for Stacker, which stacks multiple noisy images into a clearer image.
 *
 * This class handles reading PPM images, performing pixel averaging for denoising, 
 * and writing the final stacked image to a new PPM file.
 */

 #ifndef STACKER_H
 #define STACKER_H
 
 #include <vector>
 #include <string>
 
 class Stacker {
 private:
     struct Pixel {
         int red;
         int green;
         int blue;
     };
 
     std::string magic_number;
     int width;
     int height;
     int max_color;
     std::vector<Pixel> pixels; // Vector storing the final stacked image pixel data
     int image_count; // Track number of images stacked
 
 public:
     Stacker();
 
     /**
      * Reads and adds image data from a PPM file.
      * @param filename The name of the file to open and read.
      * @return 0 if successful, 1 on error.
      */
     int loadImage(const std::string& filename);
 
     /**
      * Outputs the final stacked image to a PPM file.
      * @param outfilename The name of the output file.
      * @return 0 if successful, 1 on error.
      */
     int outImage(const std::string& outfilename);
 
     /**
      * Stacks multiple images by averaging their pixel values.
      * @param infilename The name of the images input (e.g., "orion").
      * @param numImage The number of images to stack.
      * @return 0 if successful, 1 on error.
      */
     int stackImage(const std::string& infilename, int numImage);
 };
 
 #endif // STACKER_H
 
