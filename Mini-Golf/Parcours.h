#ifndef PARCOURS_H
#define PARCOURS_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Parcours
{
public:
    Parcours();
    ~Parcours();

    void addCoor(double x, double y);
    void operator+=(Parcours ParscoursAajouter);
    int GetSize();
    std::vector<std::pair<double, double>> GetCoorXY() const {
        return CoorXY;
    }
    void removelast();
    void Display();

private:
    std::vector<std::pair<double, double>> CoorXY;
};
#endif