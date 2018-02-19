#include <bits/stdc++.h>

using namespace std;

class Complex
{
private:
    int real;
    int imag;
public:
    Complex(): real(0), imag(0) {}
    void read_data()
    {
        cout << "Enter real and imag value";
        cin >> real >> imag;
    }
    void add_complex(Complex comp1, Complex comp2 )
    {
        real = comp1.real + comp2.real;
        imag = comp1.imag + comp2.imag;
    }

    static Complex add_complex_return(Complex comp1, Complex comp2 )
    {
        Complex temp;
        temp.real = comp1.real + comp2.real;
        temp.imag = comp1.imag + comp2.imag;
        return temp;
    }

    void display_sum()
    {
        cout << "sum " << real << ", i" << imag;
    }

};

int main()
{
    Complex c1, c2, c3;
    c1.read_data();
    c2.read_data();

    c3 = Complex::add_complex_return(c1, c2);

    c3.display_sum();

    return 0;
}

//2

#include <bits/stdc++.h>

using namespace std;

class check{
private:
    static int i;
public:
    check()
    {
        ++i;
    }
    ~check()
    {
        --i;
    }

    static void display()
    {
        cout << i << endl;
    }

};

int check::i = 0;

int main()
{
    check a,b,c;
    check::display();
    check *d = new check();
    check::display();
    delete d;
    check::display();
    return 0;
}

