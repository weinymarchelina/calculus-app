#include <iostream>
#include <stdio.h> 
#include <cmath> 
using std::cout;
using std::cin;
using std::endl;

double findSlope(int a, int b, int c, char type, int slope[2]);
double findPointSlope(int pt[2], int slope[2], double result);

int main() {
    int pt[2];
    int a;
    int b;
    int c;
    char type;
    int slope[2];

    // TEST: https://www.wtamu.edu/academic/anns/mps/math/mathlab/col_algebra/col_alg_tut28_parpen.htm#:~:text=The%20slope%20of%20the%20parallel%20line%20is%200%20and%20the,the%20perpendicular%20line%20is%20undefined.
    // https://corbettmaths.com/wp-content/uploads/2013/02/parallel-and-perpendicular-graphs-pdf.pdf
    // https://corbettmaths.com/wp-content/uploads/2019/08/perpendicular-lines.pdf

    cout << "Please enter the point: ";
    cin >> pt[0] >> pt[1];

    cout << '\n' << "====================================" << endl;

    cout << "The linear equation (in ax + by = c)" << endl;
    cout << "Enter the coefficient of x: ";
    cin >> a;

    cout << "Enter the coefficient of y: ";
    cin >> b;

    cout << "Enter the constant: ";
    cin >> c;

    cout << '\n' << "====================================" << endl;

    
    do {
        cout << "Enter l for parallel or r for perpendicular: ";
        cin >> type;
        type = tolower(type);
    } while (type != 'l' && type != 'r');


    cout << '\n' << "====================================" << endl;
    cout << '\n' << "====================================" << endl;


    // int pt[2] = {6, 7};
    // int a = 2;
    // int b = 3;
    // int c = 12;
    // char type = 'r';
    // int slope[2];


    printf("Find the equation through (%d, %d) and %s to %dx + %dy = %d\n", pt[0], pt[1], (type == 'l' ? "parallel" : "perpendicular"), a, b, c);

    double result = findSlope(a, b, c, type, slope);
    printf("The slope (m) is : (%d/%d) \n", slope[0], slope[1]);
    printf("The slope (m) is : %.2lf", result); 

    cout << '\n' << "====================================" << endl;
    cout << '\n' << "====================================" << endl;

    double shift = findPointSlope(pt, slope, result);

    cout << '\n' << endl;
    if (shift > 0) {
        cout << "Shift up " << std::abs(shift) << " points" << endl;
    } else if (shift == 0) {
        cout << "Does not shift" << endl;
    } else {
        cout << "Shift down " << std::abs(shift) << " points" << endl;
    }

    printf("Press ENTER key to Continue\n");  
    getchar(); 
    return 0;
}

double findSlope(int a, int b, int c, char type, int slope[2]) {
    
    cout << '\n' << "====================================" << endl;

    cout << "Turn the equation into y = mx + b" << endl;
    printf("\t%dx + %dy = %d\n", a, b, c);
    printf("\t%dy = %dx + %d\n", b, -a, c);
    printf("\ty = (%d/%d)x + (%d/%d)\n", -a, b, c, b);
    printf("\ty = %.2lfx + %.2lf\n", (double)-a/b, (double)c/b);


    int rise = -a;
    int run = b;

    if (type == 'r') {
        rise = b;
        run = a;
    }

    
    cout << '\n' << (type == 'r' ? "Perpendicular" : "Parallel") << " lines' slope: " << endl;
    cout << "The rise \t: " << rise << endl;
    cout << "The run \t: " << run << endl;


    cout << "====================================" << endl;
    slope[0] = rise;
    slope[1] = run;

    return (double)rise/(double)run;
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
    printf("\t: y = %.2lfx + %.2lf \n",  result, shift);

    return shift;
}