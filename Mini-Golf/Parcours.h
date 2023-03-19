#ifndef PARCOURS_H
#define PARCOURS_H
#include <iostream>

class Parcours
{
public:
    Parcours();
    ~Parcours();

    void addCoor(double x, double y);
    void operator+=(Parcours ParscoursAajouter);
    int GetSize();
    double Getx(int index);
    double Gety(int index);
    void Display();

private:
    int size =0;
    int capacity = 16;
    double** tableau01;
};
#endif