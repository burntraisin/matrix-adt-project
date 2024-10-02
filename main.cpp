#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Matrix {
    double a11, a12, a21, a22;
    string name;
};

void get_matrix(string name, Matrix &m);
void get_scalar(int &b);
void print_matrix(fstream &outfile,string name, Matrix m);
void calc_sum(Matrix m1, Matrix m2, Matrix &sum);
void calc_diff(Matrix m1, Matrix m2, Matrix &diff);
void scalar_mult(int k, Matrix m, Matrix &k_m);
void calc_prod(Matrix m1, Matrix m2, Matrix &prod);
void calc_inv(Matrix m, double &m_inv);

int main() {
    int b = 0, userChoice = 0;
    Matrix m1, m2, sum, diff, k_m, prod, m_inv;
    fstream outfile;

    get_matrix("m1", m1);
    get_matrix("m2", m2);

    do {

    } while (userChoice != 0);

    return 0;
}

void get_matrix(string name, Matrix &m) {
    name = m.name;
    cout << "Enter a value for element a_11 of the matrix: ";
    cin >> m.a11;
    cout << "Enter a value for element a_12 of the matrix: ";
    cin >> m.a12;
    cout << "Enter a value for element a_21 of the matrix: ";
    cin >> m.a21;
    cout << "Enter a value for element a_22 of the matrix: ";
    cin >> m.a22;
}

void print_matrix(fstream &outfile, string name, Matrix m) {
    outfile << name << '\n' << m << endl;
}

void get_scalar(int &b) {

}

void calc_sum(Matrix m1, Matrix m2, Matrix &sum) {

}

void calc_diff(Matrix m1, Matrix m2, Matrix &diff) {

}

void scalar_mult(int k, Matrix m, Matrix &k_m) {

}

void calc_prod(Matrix m1, Matrix m2, Matrix &prod) {

}

void calc_inv(Matrix m, Matrix &m_inv) {

}