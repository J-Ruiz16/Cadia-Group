/**
 * @file main.cpp
 * @author Jocelyn Ruiz
 * @date 2025-03-07
 * @brief outputs the stack class implementation while also interacting with the user prompting
 * 
 * asks user for which image file to open, asks how many images, then stacks however many images were entered
 *
 */

#include "stacker.h"
#include <iostream>

int main(){
  std::string fname;
  int numImage;
  std::cout << "Please enter the image you wish to stack: ";
  std::cin >> fname;
  std::cout << "Please enter the number of images: ";
  std::cin >> numImage;

  std::cout << "Stacking images:" << std::endl;

  Stacker stacker;

  int readImages = stacker.loadImage(fname);
  int outputfile = stacker.outImage(fname);

  std::cout << readImages << std::endl;
  std::cout << outputfile << std:: endl;


  std::cout << "Output written to: " << fname << std::endl;

  return 0;
}
