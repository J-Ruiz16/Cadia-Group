#include <iostream>
#include "stacker.h"

using namespace std;

int main() {
    string fname;
    int numImage;

    cout << "Please enter the image you wish to stack: ";
    cin >> fname;

    cout << "Please enter the number of images: ";
    cin >> numImage;

    Stacker stacker;  

    if (stacker.stackImage(fname, numImage) == 0) {
        cout << "Stacking succeeded." << endl;
        cout << "Output written to: " << fname << ".ppm" << endl;
    } else {
        cerr << "Stacking failed!" << endl;
    }

    return 0;
}
