// Written by Syed Hammad Ahmed
// OOP@DSU Fall 2015
// YOU MAY NOT MODIFY THIS FILE WITHOUT DISCUSSING WITH ME

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include"Pixel.h"
using namespace std;

class Image{
	private:
		Pixel** imageArray;
		int rows;
		int cols;
        int max;
        string filesName;
        bool fileFound;
	public:
		Image();  // Default Constructor.
		Image(string fileName);  // Parameterize Constructor.
		~Image();
        void load();
		void load(string fileName);
		void writePGM(string fileName, int** writeArray, int rows1, int cols1);
		bool getImageLoaded();
		void invertColors();
		void brighten();
		void darken();
		void crop(int x1, int y1, int x2, int y2);
		void convertToPGM();
		void flipVertical();
		void flipHorizontal();
		void rotateRight();
		void rotateLeft();
		void sharpen();
    private:
        void deallocate(Pixel** myArr,int rows);
        void writeFile(string fileName, Pixel** writeArray, int rows1, int cols1);
};

#endif
