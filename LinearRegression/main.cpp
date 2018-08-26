//
//  main.cpp
//  LinearRegression
//
//  Created by Ruowen Tan on 26/08/2018.
//  Copyright © 2018 Ruowen Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class LinearRegression {
    // Assume y = ax + b
    double a;
    double b;
    
public:
    void fit(vector<double> X, vector<double> y);
    void display() {cout << "y = " << a << "x + " << b << endl;}
    double predict(double x);
};

void LinearRegression::fit(vector<double> X, vector<double> y) {
    
    // Compute y = ax + b, a only
    double sum_of_x = 0;
    for (int i = 0; i < X.size(); i++) {
        sum_of_x += X[i];
    }
    double average_of_x = sum_of_x / X.size();
    
    double numerator = 0;
    for (int i = 0; i < X.size(); i++) {
        numerator += y[i] * (X[i] - average_of_x);
    }
    
    double left = 0;
    for (int i = 0; i < X.size(); i++) {
        left += pow(X[i], 2.0);
    }
    
    double denominator = 0;
    denominator += left;
    denominator -= pow(sum_of_x, 2.0) / X.size();
    
    this->a = numerator / denominator;
    
    // Compute y = ax + b, b only
    double temp = 0.0;
    for (int i = 0; i < X.size(); i++) {
        temp += y[i] - this->a * X[i];
    }
    this->b = temp / X.size();
}

double LinearRegression::predict(double x) {
    return this->a * x + this->b;
}



int main(int argc, const char * argv[]) {
    
    vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {1.0, 2.0, 3.0, 4.0, 5.0};
    LinearRegression l = LinearRegression();
    l.fit(X, y);
    l.display();
    
    vector<double> years_experience = {1.1, 1.3, 1.5, 2, 2.2, 2.9, 3};
    vector<double> salary = {39343, 46205, 37731, 43525, 39891, 56642, 60150};
    LinearRegression l2 = LinearRegression();
    l2.fit(years_experience, salary);
    l2.display();
    cout << "Predict: 4 years work experience." << endl;
    cout << l2.predict(4) << endl;
    /* Outputs:
     y = 1x + 0
     y = 9555.38x + 27101.7
     Predict: 4 years work experience.
     65323.2
     */
}
