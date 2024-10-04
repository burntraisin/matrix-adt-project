#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Matrix
{
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
void calc_inv(Matrix m, Matrix &m_inv);
void print_matrix_to_console(string name, Matrix m);

int main()
{
    int b = 0, userChoice = 0;
    Matrix m1, m2, sum, diff, k_m, prod, m_inv;
    fstream outfile;

    get_matrix("m1", m1);
    get_matrix("m2", m2);

    do
    {
        cout << "Enter a number to perform one of the following on the two matrices:" 
        << '\n' << "1. Sum" 
        << '\n' << "2. Difference" 
        << '\n' << "3. Multiply by a scalar" 
        << '\n' << "4. Product" 
        << '\n' << "5. Inverse" 
        << '\n' << "0. Quit" 
        << endl;

        cin >> userChoice;
        switch (userChoice)
        {
            case 0:
                break;
            case 1:
                calc_sum(m1, m2, sum);
                print_matrix_to_console("Sum", sum);
                break;
            case 2:
                calc_diff(m1, m2, diff);
                print_matrix_to_console("Difference", diff);
                break;
            case 3:
                get_scalar(b);
                scalar_mult(b, m1, k_m);
                print_matrix_to_console("Scalar Multiplication", k_m);
                break;
            case 4:
                calc_prod(m1, m2, prod);
                print_matrix_to_console("Product", prod);
                break;
            case 5: 
                calc_inv(m1, m_inv);
                print_matrix_to_console("Inverse", m_inv);
                break;
            default:
                break;
        }
    } while (userChoice != 0);

    outfile.open("output.txt", ios::out);
    print_matrix(outfile, "First matrix", m1);
    print_matrix(outfile, "Second matrix", m2);
    print_matrix(outfile, "Sum", sum);
    print_matrix(outfile, "Difference", diff);
    print_matrix(outfile, "Scalar Multiplication", k_m);
    print_matrix(outfile, "Product", prod);
    print_matrix(outfile, "Inverse", m_inv);
    outfile.close();
    return 0;
}

void get_matrix(string name, Matrix &m)
{
    m.name = name;
    cout << "Enter a value for element a_11 of the matrix " << m.name << ": ";
    cin >> m.a11;
    cout << "Enter a value for element a_12 of the matrix " << m.name << ": ";
    cin >> m.a12;
    cout << "Enter a value for element a_21 of the matrix " << m.name << ": ";
    cin >> m.a21;
    cout << "Enter a value for element a_22 of the matrix " << m.name << ": ";
    cin >> m.a22;
}

void print_matrix(fstream &outfile, string name, Matrix m)
{
    int nameLength = name.length();
    string nameLengthSpaces;
    nameLengthSpaces.assign(nameLength, ' ');

    outfile << fixed << setprecision(2);
    outfile << string(nameLength, ' ') << string(3, ' ') << setw(12) << m.a11 << setw(12) << m.a12 << endl;
    outfile << name << " = " << endl;
    outfile << string(nameLength, ' ') << string(3, ' ') << setw(12) << m.a21 << setw(12) << m.a22 << endl << endl;
}

void get_scalar(int &b)
{
    cout << "Enter a scalar: ";
    cin >> b;
}

void calc_sum(Matrix m1, Matrix m2, Matrix &sum)
{
    sum.a11 = m1.a11 + m2.a11;
    sum.a12 = m1.a12 + m2.a12;
    sum.a21 = m1.a21 + m2.a21;
    sum.a22 = m1.a22 + m2.a22;
}

void calc_diff(Matrix m1, Matrix m2, Matrix &diff)
{
    diff.a11 = m1.a11 - m2.a11;
    diff.a12 = m1.a12 - m2.a12;
    diff.a21 = m1.a21 - m2.a21;
    diff.a22 = m1.a22 - m2.a22;
}

void scalar_mult(int k, Matrix m, Matrix &k_m)
{
    k_m.a11 = k * m.a11;
    k_m.a12 = k * m.a12;
    k_m.a21 = k * m.a21;
    k_m.a22 = k * m.a22;
}

void calc_prod(Matrix m1, Matrix m2, Matrix &prod)
{
    prod.a11 = ((m1.a11 * m2.a11) + (m1.a12 * m2.a21));
    prod.a12 = ((m1.a11 * m2.a12) + (m1.a12 * m2.a22));
    prod.a21 = ((m1.a21 * m2.a11) + (m1.a22 * m2.a21));
    prod.a22 = ((m1.a21 * m2.a12) + (m1.a22 * m2.a22));
}

void calc_inv(Matrix m, Matrix &m_inv)
{
    double detA = ((m.a11 * m.a22) - (m.a21 * m.a12));
    m_inv.a11 = (m.a22 / detA);
    m_inv.a12 = (-m.a12 / detA);
    m_inv.a21 = (-m.a21 / detA);
    m_inv.a22 = (m.a11 / detA);
}

void print_matrix_to_console(string name, Matrix m)
{
    int nameLength = name.length();
    string nameLengthSpaces;
    nameLengthSpaces.assign(nameLength, ' ');

    cout << fixed << setprecision(2);
    cout << string(nameLength, ' ') << string(3, ' ') << setw(12) << m.a11 << setw(12) << m.a12 << endl;
    cout << name << " = " << endl;
    cout << string(nameLength, ' ') << string(3, ' ') << setw(12) << m.a21 << setw(12) << m.a22 << endl << endl;
}