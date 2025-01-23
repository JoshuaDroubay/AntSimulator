#ifndef UNTITLED5_ANT_H
#define UNTITLED5_ANT_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

class ant {
public:
    ant();
    void SetInitialPosition(vector<double>);
    void SetInitialOrientation(vector<double>);
    void UpdateOrientation(double, double, vector<double>);
    void UpdatePosition();
    vector<double> GetLeftAntenna();
    vector<double> GetRightAntenna();
    vector<double> GetPosition();
    vector<double> GetOrientation();

private:
    vector<double> position;
    vector<double> orientation;
    double antennaLength = .2;
    double antennaAngle = M_PI/4;
};

#endif
