#include <iostream>
#include <string>
#include "Image.h"
using namespace std;

int main(){
	string fileName = "";
	cout << "Enter filename: ";
	//cin >> fileName;
	Image image;
	image.load("beach.ppm"); // loads image i.e. read file

	if(image.getImageLoaded()){  // getter for bool attribute. true when successful image loading done
        image.rotateRight();
		image.invertColors();
		image.brighten();

		image.darken();
		image.crop(100, 100, 400, 400);
		image.convertToPGM();

        image.flipVertical();
        image.flipHorizontal();
//		image.rotateLeft();
	}
	// don't forget to deallocate in destructor
	return 0;
}

