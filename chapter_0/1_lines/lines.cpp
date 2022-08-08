#include <iostream>
using std::cout;
using std::cin;
using std::endl;

float findSlope(float pt1[2], float pt2[2], float riseAndRun[2]);
float findPointSlope(float pt1[2], float riseAndRun[2],float result);

int main() {
    
    float pt1[2];
    float pt2[2];
    float riseAndRun[2];

    // float pt1[2] = {-2, -3};
    // float pt2[2] = {8, 2};

    cout << "Please enter the point 1: ";
    cin >> pt1[0] >> pt1[1];

    cout << "Please enter the point 2: ";
    cin >> pt2[0] >> pt2[1];

    cout << '\n' << "====================================" << endl;
    cout << "The entered points" << endl;
    cout << "First point\t: (" << pt1[0] << ", " << pt1[1] << ") "<< endl;
    cout << "Second point\t: (" << pt2[0] << ", "<< pt2[1] << ") "<< endl;

    float result = findSlope(pt1, pt2, riseAndRun);
    cout << "The slope (m) is : " << riseAndRun[0] << " / "<<  riseAndRun[1] << endl;
    cout << "The slope (m) is : " << result << endl;

    cout << '\n' << "====================================" << endl;
    cout <<  "====================================" << '\n' << endl;

    float shift = findPointSlope(pt1, riseAndRun, result);

    if (shift > 0) {
        cout << "Shift up " << abs(shift) << " points" << endl;
    } else if (shift == 0) {
        cout << "Does not shift" << endl;
    } else {
        cout << "Shift down " << abs(shift) << " points" << endl;
    }


    






    return 0;
}

float findSlope(float pt1[2], float pt2[2], float riseAndRun[2]) {
    float rise = pt2[1] - pt1[1];
    float run = pt2[0] - pt1[0];

    cout << '\n' << "----------------------------" << endl;
    cout << "The rise (y2 - y1)\t: " << pt2[1] << " - " << pt1[1] <<  " = " << rise << endl;
    cout << "The run (x2 - x1)\t: " << pt2[0] << " - " << pt1[0] <<  " = " << run << endl;
    cout <<  "----------------------------" << '\n' << endl;

    // cout << "The slope is: " << rise << " / "<< run <<  endl;
    riseAndRun[0] = rise;
    riseAndRun[1] = run;

    return rise/run;
}

float findPointSlope(float pt1[2], float riseAndRun[2], float result) {

    cout << "Equation of Point-Slope" << endl;
    cout << "Formula\t: " << "y - y1 = m(x - x1)" << endl;
    cout << "\t: " << "y - " << pt1[1] << " = (" << riseAndRun[0] << " / "<<  riseAndRun[1] << ") (x - " << pt1[0] << ")" << endl;
    cout << "\t: " << "y" << " = (" << riseAndRun[0] << " / "<<  riseAndRun[1] << ") (x - " << pt1[0] << ") + " << pt1[1] << endl;


    // y = m.x - (m.x1 + y1)

    float shift = (-pt1[0] * result) + pt1[1]; 
    cout << "\t: " << "y" << " = (" << riseAndRun[0] << " / "<<  riseAndRun[1] << ")x + " << shift  << endl;
    return shift;
}