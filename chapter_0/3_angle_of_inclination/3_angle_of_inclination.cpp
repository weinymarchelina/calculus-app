#include <iostream>
#include <stdio.h> 
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

double findTheta(double input);
double findSlope(double input);


int main() {
    // char type = 'm';
    // double input = 30;
    
    // char type = 't';
    // double input = -1;
    
    // double result;

    char type;
    double input;
    double result;

    do {
        cout << "Please select the value you want to find (m for slope, t for theta): ";
        cin >> type;
    } while (type != 'm' && type != 't');

    cout << "Please enter the value of " << (type == 'm' ? "theta" : "slope") << ": ";
    cin >> input;

    if (type == 'm') {
        result = findSlope(input);
        cout << "The result (m): " << result << endl;
    } else {
        result = findTheta(input);
        cout << "The result (theta): " << result << endl;
    }


    return 0;
}

double findTheta(double input) {
    cout << "m = " << input << endl;
    cout << '\n' << "m = tan theta" << endl;
    cout << input << " = tan theta" << endl;

    // In trigonometrics, arc tangent is the inverse operation of tangent.
    cout << '\n' << "Find the arc tangent of " << input << ": " << endl;
    cout << "tan^-1(" << input << ") = theta"<< endl;

    const double PI = 3.14159265;
    double result = atan(input) * 180 / PI;
    cout << "theta = " << result << " degrees" << " (is the same as " << result + 180 << " degrees)" << endl;


    return result;
}


double findSlope(double input) {
    cout << "theta = " << input << " degrees" << endl;
    cout << '\n' << "m = tan theta" << endl;
    cout <<  "m = tan " << input << " degrees" << endl;

    // In trigonometrics, arc tangent is the inverse operation of tangent.
    cout << '\n' << "Find the tangent of " << input << " degrees: " << endl;
     


    const double PI = 3.14159265;
    double result = tan(input * PI / 180);
    cout << "tan " << input << " = " << result << endl;   
    cout << "m = " << result << endl;    

    return result;
}