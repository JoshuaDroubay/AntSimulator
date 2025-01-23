#include "ant.h"

ant::ant() {
    orientation.resize(2);

    position.resize(2);

}

void ant::SetInitialPosition(vector<double> initialposition){
    int i = 0;

    for (i = 0; i < 2; ++i) {
        position.at(i) = initialposition.at(i);
    }
}

void ant::SetInitialOrientation(vector<double> initialorientation) {
    int i = 0;

    for (i = 0; i < 2; ++i) {
        orientation.at(i) = initialorientation.at(i);
    }
}

void ant::UpdateOrientation(double x1, double x2, vector<double> sound) {
    int i = 0;
    double theta;
    double deltax;
    double r = .1;
    double R = 20;
    double sPower = 0;
    vector<double> initialOrientation;

    initialOrientation.resize(2);
    for (i = 0; i < 2; ++i){
        initialOrientation.at(i) = orientation.at(i);
    }

    deltax = x1/x2 - 1;
    if (deltax != 0.0) {
        theta = (r / (2 * deltax)) * (sqrt(1 + pow((M_PI * deltax) / r, 2)) - 1);
    }

    else {
        theta = 0;
    }

    orientation.at(0) = cos(theta) * orientation.at(0) + sin(theta) * orientation.at(1) + R * initialOrientation.at(0)
            + sPower * sound.at(0);
    orientation.at(1) = -1 * sin(theta) * orientation.at(0) + cos(theta) * orientation.at(1) + R * initialOrientation.at(1)
            + sPower * sound.at(1);
}

void ant::UpdatePosition() {
    int i = 0;
    double travelDistance = .05;
    double norm;

    norm = sqrt(pow(orientation.at(0),2) + pow(orientation.at(1),2));

    for (i = 0; i < 2; ++i) {
        orientation.at(i) = orientation.at(i) / norm;
    }

    for (i = 0; i < 2; ++i) {
        position.at(i) = position.at(i) + (travelDistance) * orientation.at(i);
    }
}

vector<double> ant::GetLeftAntenna() {
    int i = 0;
    double norm;
    vector<double> antennaPosition;
    antennaPosition.resize(2);

    norm = sqrt(pow(orientation.at(0),2) + pow(orientation.at(1),2));

    for (i = 0; i < 2; ++i) {
        orientation.at(i) = orientation.at(i) / norm;
    }

    antennaPosition.at(0) = position.at(0) + antennaLength * (cos(antennaAngle) * orientation.at(0)
                                                              + sin(antennaAngle) * orientation.at(1));

    antennaPosition.at(1) = position.at(1) + antennaLength * (-sin(antennaAngle) * orientation.at(0)
                                                              + cos(antennaAngle) * orientation.at(1));

    return antennaPosition;
}

vector<double> ant::GetRightAntenna() {
    int i = 0;
    double norm;
    vector<double> antennaPosition;
    antennaPosition.resize(2);

    norm = sqrt(pow(orientation.at(0),2) + pow(orientation.at(1),2));

    for (i = 0; i < 2; ++i) {
        orientation.at(i) = orientation.at(i) / norm;
    }

    antennaPosition.at(0) = position.at(0) + antennaLength * (cos(antennaAngle) * orientation.at(0)
                                                              - sin(antennaAngle) * orientation.at(1));

    antennaPosition.at(1) = position.at(1) + antennaLength * (sin(antennaAngle) * orientation.at(0)
                                                              + cos(antennaAngle) * orientation.at(1));

    return antennaPosition;
}

vector<double> ant::GetPosition() {
    return position;
}

vector<double> ant::GetOrientation() {
    return orientation;
}
