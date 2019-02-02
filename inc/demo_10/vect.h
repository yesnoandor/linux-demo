// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};		// 两种模式，直角坐标和极坐标

	// RECT for rectangular, POL for Polar modes
    private:
        double x;			// horizontal value
        double y;			// vertical value
        double mag;			// length of vector
        double ang;			// direction of vector in degrees
        Mode mode;			// RECT or POL
        
    // private methods for setting values
        void set_mag();		// 设置矢量长度 (通过X，Y)
        void set_ang();		// 设置矢量角度 (通过X，Y)
        void set_x();		// 设置x坐标值 （通过mag,ang）
        void set_y();		// 设置y坐标值 （通过mag,ang）
		
    public:
       Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();

		double xval() const {return x;}       // report x value
        double yval() const {return y;}       // report y value
        double magval() const {return mag;}   // report magnitude
        double angval() const {return ang;}   // report angle
        void polar_mode();                    // set mode to POL
        void rect_mode();                     // set mode to RECT
        
    // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
		
    // friends
        friend Vector operator*(double n, const Vector & a);	// 友元函数重载*
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);	// 友元函数重载 <<
    };

}   // end namespace VECTOR
#endif
