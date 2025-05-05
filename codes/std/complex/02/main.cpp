// complex_abs.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main(int argc, char* argv[])
{
    using namespace std;
    double pi = 3.14159265359;

    // Complex numbers can be entered in polar form with
    // modulus and argument parameter inputs but are
    // stored in Cartesian form as real & imag coordinates
    complex <double> c1 ( polar ( 5.0 ) );   // Default argument = 0
    complex <double> c2 ( polar ( 5.0 , pi / 6 ) );
    complex <double> c3 ( polar ( 5.0 , 13 * pi / 6 ) );
    cout << "c1 = polar ( 5.0 ) = " << c1 << endl;
    cout << "c2 = polar ( 5.0 , pi / 6 ) = " << c2 << endl;
    cout << "c3 = polar ( 5.0 , 13 * pi / 6 ) = " << c3 << endl;

    // The modulus and argument of a complex number can be recovered
    // using abs & arg member functions
    double absc1 = abs ( c1 );
    double argc1 = arg ( c1 );
    cout << "The modulus of c1 is recovered from c1 using: abs ( c1 ) = "
        << absc1 << endl;
    cout << "Argument of c1 is recovered from c1 using:\n arg ( c1 ) = "
        << argc1 << " radians, which is " << argc1 * 180 / pi
        << " degrees." << endl;

    double absc2 = abs ( c2 );
    double argc2 = arg ( c2 );
    cout << "The modulus of c2 is recovered from c2 using: abs ( c2 ) = "
        << absc2 << endl;
    cout << "Argument of c2 is recovered from c2 using:\n arg ( c2 ) = "
        << argc2 << " radians, which is " << argc2 * 180 / pi
        << " degrees." << endl;

    // Testing if the principal angles of c2 and c3 are the same
    if ( (arg ( c2 ) <= ( arg ( c3 ) + .00000001) ) ||
        (arg ( c2 ) >= ( arg ( c3 ) - .00000001) ) )
        cout << "The complex numbers c2 & c3 have the "
        << "same principal arguments."<< endl;
    else
        cout << "The complex numbers c2 & c3 don't have the "
        << "same principal arguments." << endl;
    return 0;
}