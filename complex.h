#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex {
  private:
    double Real, Imag;

  public:
    Complex(double Real=0, double Imag=0)
    {
        this->Real = Real;
        this->Imag = Imag;
    };

    Complex& operator=(const Complex& s)
    {
        Real = s.Real;
        Imag = s.Imag;
        return *this;
    };

    Complex operator-() const
    {
        return Complex(-Real, -Imag);
    };

    Complex& operator=(double co)
    {
        Real = co;
        Imag = 0;
        return *this;
    };

    Complex operator+(const Complex& co) const
    {
        Complex n;
        n.Real = this->Real + co.Real;
        n.Imag = this->Imag + co.Imag;
        return n;
    };

    Complex& operator-=(Complex co)
    {
        Real -= co.Real;
        Imag -= co.Imag;
        return *this;
    };
    
    double abs() const
    {
		return sqrt(this->Real * this->Real + this->Imag * this->Imag);
	}
	
	Complex conj() const
	{
		Complex zespolona;
		zespolona.Real = this->Real;
		zespolona.Imag = this->Imag * (-1);
		return zespolona;		
	}
	
	double phase() const
	{
		double z;
        double modul;
        modul = abs();
        if(modul == 0)
        {
            return 0;
        }
        z = 180/M_PI*acos(this->Real/modul);
        if(this->Imag < 0)
        {
            return 360 - z;
        }
        return z;
	}
		
	
	friend Complex operator / (Complex s, Complex co);
	Complex operator /= (Complex co)
	{
		*this = *this/co;
        return *this;
	}

    friend Complex operator-(Complex, Complex);
    friend ostream& operator<<(ostream& s, const Complex& c)
    {
        s << "(" << c.Real << "," << c.Imag << ")";
        return s;
    };
};

inline Complex operator-(const Complex s1, const Complex s2) 
{
    Complex n(s1);
    return n -= s2;
}

Complex operator / (Complex s, Complex co) 
	{
		if(co.Real == 0 && co.Imag == 0)
        {
            cout << "Nie wolno dzielic przez zero" << endl;
        }
        Complex second;
		second.Real = (((s.Real*co.Real)+(s.Imag*co.Imag))/((co.Real*co.Real)+(co.Imag*co.Imag)));
		second.Imag = ((s.Imag*co.Real)-(s.Real*co.Imag))/((co.Real*co.Real)+(co.Imag*co.Imag));
		return second;
	}
#endif /* __Complex_H__ */
