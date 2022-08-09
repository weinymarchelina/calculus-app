#include <iostream>
#include <stdio.h> 
#include <cmath> 
using std::cout;
using std::cin;
using std::endl;

double findSlope(int pt1[2], int pt2[2], int slope[2]);
double findPointSlope(int pt[2], int slope[2], double result);

int main() {
    int pt1[2];
    int pt2[2];
    int slope[2];

    // int pt1[2] = {-2, -3};
    // int pt2[2] = {8, 2};

    cout << "Please enter the point 1: ";
    cin >> pt1[0] >> pt1[1];

    cout << "Please enter the point 2: ";
    cin >> pt2[0] >> pt2[1];

    printf("\n====================================\n");
    printf("The entered points\n");
    printf("First point\t: (%d, %d) \n", pt1[0], pt1[1]);
    printf("Second point\t: (%d, %d) \n", pt2[0], pt2[1]);

    double result = findSlope(pt1, pt2, slope);
    printf("The slope (m) is : (%d / %d) \n", slope[0], slope[1]);
    printf("The slope (m) is : %.2lf", result); 

    printf("\n\n====================================\n");
    printf("====================================\n\n");

    double shift = findPointSlope(pt1, slope, result);
    cout << '\n' << endl;
    if (shift > 0) {
        cout << "Shift up " << std::abs(shift) << " points" << endl;
    } else if (shift == 0) {
        cout << "Does not shift" << endl;
    } else {
        cout << "Shift down " << std::abs(shift) << " points" << endl;
    }


    return 0;
}

double findSlope(int pt1[2], int pt2[2], int slope[2]) {
    int rise = pt2[1] - pt1[1];
    int run = pt2[0] - pt1[0];

    printf("\n----------------------------\n");
    printf("The rise (y2 - y1)\t: %d - %d = %d\n", pt2[1], pt1[1], rise);
    printf("The run (x2 - x1)\t: %d - %d = %d\n\n", pt2[0], pt1[0], run);

    printf("----------------------------\n");
    slope[0] = rise;
    slope[1] = run;

    return (double)rise/run;
}

double findPointSlope(int pt[2], int slope[2], double result) {

    cout << "Equation of Point-Slope\n" << endl;

    printf("Formula\t: y - y1 = m(x - x1)\n"); 
    printf("\t: y - %d = (%d/%d) (x - %d)\n", pt[1], slope[0], slope[1], pt[0]);
    printf("\t: y = (%d/%d) (x - %d) + %d \n",  slope[0], slope[1], pt[0], pt[1]);

    cout << "\t" << endl;

    printf("\t: y = (%d/%d)x + (%d*%d / %d) + %d \n",  slope[0], slope[1], slope[0], -pt[0], slope[1], pt[1]);
    printf("\t: y = (%d/%d)x + (%d/%d) + %d \n",  slope[0], slope[1], (slope[0] * -pt[0]), slope[1], pt[1]);
    printf("\t: y = (%d/%d)x + (%d/%d) + (%d/%d) \n",  slope[0], slope[1], (slope[0] * -pt[0]), slope[1], (slope[1] *  pt[1]), slope[1]);
    printf("\t: y = (%d/%d)x + (%d/%d) \n",  slope[0], slope[1], ((slope[0] * -pt[0]) + (slope[1] *  pt[1])), slope[1]);
    
    cout << "\tOR" << endl;
    
    printf("\t: y = (%d/%d)x + %.2lf + %d \n",  slope[0], slope[1], (double)(-pt[0] * result), pt[1]);


    double shift = (-pt[0] * result) + pt[1]; 
    printf("\t: y = (%d/%d)x + %.2lf \n",  slope[0], slope[1], shift);

    return shift;
}