#include <string>
#include<iostream>
#include"Image.h"
#include"Pixel.h"
#include<fstream>


Image::Image(){

    rows = 0;
    cols = 0;
    max = 0;
};

void Image::load(string fileName){
    cout << "file name " << fileName << endl;
    ifstream fin;
    fin.open(fileName.c_str());
    string myValue = "";

    if(fin){
        cout << "File found"<< endl;
        fin >> myValue;
        fin >> rows >> cols >> max;

        imageArray = new Pixel*[rows];

        for(int i = 0; i < rows; ++i){
            imageArray[i] = new Pixel[cols];
        }


        int r, g, b;
        int i = 0, j = 0;
        for(i = 0; i < rows; ++i){
            for(j = 0; j < cols; ++j){
                fin >> r >> g >> b;
                imageArray[i][j].setValues(r, g, b);

            }
        }
    }
    else {
        cout << "File not found ";
    }
    fin.close();
};

bool Image::getImageLoaded(){

    if(imageArray){
        return true;
    }
    else {
        return false;
    }
};

void Image::writeFile(string fileName, Pixel** writeArray, int rows1, int cols1){
    ofstream fout;
        fout.open(fileName.c_str());
        if(fout){
            fout << "P3\n";
            fout << rows1 << cols1 << max;
            int k = 0;
            for(int i = 0; i < rows1; ++i){
                for(int j = 0; j < cols1; ++j){
                    fout << writeArray[i][j].getR() << " ";
                    fout << writeArray[i][j].getG() << " ";
                    fout << writeArray[i][j].getB() << " ";
                    k++;
                }
                k = 0;
            }
        }
        else {
            cout << "File not opened";
        }
        fout.close();
}; // called from each of the following functions, to create a new file: see document for naming of new file

void Image::writePGM(string fileName, int** writeArray, int rows1, int cols1){
    ofstream fout;
        fout.open(fileName.c_str());
        if(fout){
            fout << "P2\n";
            fout << rows1 << " " << cols1 << endl << max << endl;
            for(int i = 0; i < rows1; ++i){
                for(int j = 0; j < cols1; ++j){
                    fout << writeArray[i][j] << " ";
                }
                fout << endl;
            }
        }
        else {
            cout << "File not opened";
        }
        fout.close();
}; // called from each of the following functions, to create a new file: see document for naming of new file

void Image::invertColors(){
    Pixel** myArr = new Pixel*[rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new Pixel[cols];
    }
    int r, g, b;
    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            r = 255 - imageArray[i][j].getR();
            g = 255 - imageArray[i][j].getG();
            b = 255 - imageArray[i][j].getB();
            myArr[i][j].setValues(r, g, b);
        }
    }
    writeFile("Beach-InvertColors.ppm", myArr, rows, cols);
    cout << "Created Beach-InvertColors.ppm"<< endl;
    deallocate(myArr, rows);
};

void Image::brighten(){

    Pixel** myArr = new Pixel*[this->rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new Pixel[this->cols];
    }
    int r, g, b;

    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            if((imageArray[i][j].getR() + (imageArray[i][j].getR() * 0.10)) <= 255){
                r = (imageArray[i][j].getR() + (imageArray[i][j].getR() * 0.10));
            }
            else {
                r = 255;
            }
            if((imageArray[i][j].getG() + (imageArray[i][j].getG() * 0.10)) <= 255){
                g = (imageArray[i][j].getG() + (imageArray[i][j].getG() * 0.10));
            }
            else {
                g = 255;
            }
            if((imageArray[i][j].getB() + (imageArray[i][j].getB() * 0.10)) <= 255){
                b = (imageArray[i][j].getB() + (imageArray[i][j].getB() * 0.10));
            }
            else {
                b = 255;
            }
            myArr[i][j].setValues(r, g, b);
        }
    }
    writeFile("Beach-Brighten.ppm", myArr, rows, cols);
    cout << "Created Beach-Brighten.ppm"<< endl;
    deallocate(myArr, rows);
};  // brightens the image by 10%

void Image::darken(){
    Pixel** myArr = new Pixel*[rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new Pixel[cols];
    }
    int r, g, b;
    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            if((imageArray[i][j].getR() - (imageArray[i][j].getR() * 0.10)) >= 0){
                r = (imageArray[i][j].getR() - (imageArray[i][j].getR() * 0.10));
            }
            else {
                r = 0;
            }
            if((imageArray[i][j].getG() - (imageArray[i][j].getG() * 0.10)) >= 0){
                g = (imageArray[i][j].getG() - (imageArray[i][j].getG() * 0.10));
            }
            else {
                g = 0;
            }
            if((imageArray[i][j].getB() - (imageArray[i][j].getB() * 0.10)) >= 0){
                b = (imageArray[i][j].getB() - (imageArray[i][j].getB() * 0.10));
            }
            else {
                b = 0;
            }
            myArr[i][j].setValues(r, g, b);
        }
    }
    writeFile("Beach-Darken.ppm",myArr,rows,cols);
    cout << "Created Beach-Darken.ppm"<< endl;
    deallocate(myArr, rows);
};

void Image::crop(int x1, int y1, int x2, int y2){
    Pixel** cropArray;
    int newRows = 0, newCols = 0,
    i = 0, j = 0,
    cC = 0, rC = 0,
    r = 0, b = 0, g = 0;
    newRows = x2 - x1;
    newCols = y2 - y1;
    cropArray = new Pixel*[newRows];
    for(int i = 0; i < newRows; ++i){
        cropArray[i] = new Pixel[newCols];
    }
    for(i = x1; i < x2; i++){
        cC = 0;
        for(j = y1; j < y2; j++){
            r = imageArray[i][j].getR();
            g = imageArray[i][j].getG();
            b = imageArray[i][j].getB();
            cropArray[rC][cC].setValues(r, g, b);
            cC++;
        }
        rC++;
    }
    writeFile("beach-Crop.ppm", cropArray, newRows, newCols);
    cout << "Created beach-Crop.ppm"<< endl;
    deallocate(cropArray, newRows);
};

void Image::convertToPGM(){
    int** myArr = new int*[rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new int[cols];
    }
    int r, g, b;
    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            r = imageArray[i][j].getR();
            g = imageArray[i][j].getG();
            b = imageArray[i][j].getB();
            myArr[i][j] = (r + g + b)/3;
        }
    }
    writePGM("Beach-ConverToPGM.pgm", myArr, rows, cols);
    cout << "Created-ConverToPGM.ppm"<< endl;
    for(int i = 0; i < rows; ++i){
        delete [] myArr[i];
    }
    delete [] myArr;
};

void Image::flipVertical(){
    Pixel** myArr = new Pixel*[this->rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new Pixel[this->cols];
    }
    int r, g, b;
    int ik = 0, jk = 0;
    for(i = (rows-1); i >= 0; i--){
        jk = 0;
        for(j = (cols-1); j >= 0; j--){

            r = imageArray[i][j].getR();
            g = imageArray[i][j].getG();
            b = imageArray[i][j].getB();
            myArr[ik][jk].setValues(r, g, b);
            jk++;
        }
        ik++;
    }
    writeFile("Beach-Vertical.ppm", myArr, rows, cols);
    cout << "Created Beach-Vertical.ppm"<< endl;
    deallocate(myArr, rows);
};

void Image::flipHorizontal(){
    Pixel** myArr = new Pixel*[this->rows];
    int i, j;
    for(i = 0; i < rows; ++i){
        myArr[i] = new Pixel[this->cols];
    }
    int r, g, b;
    int jk = 0;
    for(i = 0; i < rows; ++i){
        for(j = (cols-1); j >= 0; j--){
            r = imageArray[i][j].getR();
            g = imageArray[i][j].getG();
            b = imageArray[i][j].getB();
            myArr[i][jk].setValues(r, g, b);
            jk++;
        }
        jk = 0;
    }
    writeFile("Beach-Horizontal.ppm", myArr, rows, cols);
    cout << "Created Beach-Horizontal.ppm"<< endl;
    deallocate(myArr, rows);
};

void Image::rotateRight(){
    Pixel** myArr = new Pixel*[cols];
    int i, j;
    for(i = 0; i < cols; ++i){
        myArr[i] = new Pixel[rows];
    }
    int r, g, b;
    int ik = 0, jk = 0;
    for(i = 0; i < 442; i++){
        jk = 0;
        for(j = (441); j >= 0; --j){
            if(imageArray[i][j].getR() >= 0 && imageArray[i][j].getR() <= 255){
                r = imageArray[i][j].getR();
                g = imageArray[i][j].getG();
                b = imageArray[i][j].getB();
                myArr[jk][ik].setValues(r , g, b);
                jk++;
            }
        }
        ik++;
    }
    writeFile("Beach-RotateRight.ppm", myArr, cols, rows);
    cout << "Created Beach-RotateRight.ppm"<< endl;
    deallocate(myArr, cols);
}

void Image::deallocate(Pixel** myArr,int rows){
    for(int i = 0; i < rows; ++i){
        delete [] myArr[i];
    }
    delete [] myArr;
}

Image::~Image(){
    deallocate(imageArray, rows);
}

