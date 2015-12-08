#include"Pixel.h"

Pixel::Pixel(){
    r = 0;
    g = 0;
    g = 0;
};  // sets default pixel to white
int Pixel::getR(){
    return r;
};
int Pixel::getG(){
    return g;
};
int Pixel::getB(){
    return b;
};
void Pixel::setR(int r){
    this->r = r;
};
void Pixel::setG(int g){
    this->g = g;
};
void Pixel::setB(int b){
    this->b = b;
};
void Pixel::setValues(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
};
