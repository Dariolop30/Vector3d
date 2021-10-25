#include "Vector3D.h"

#include <iostream>
#include <math.h>
using namespace std;

//constructors

Vector3D::Vector3D (double x, double y, double z) {

  x_ = x;
  y_ = y;
  z_ = z;

}

//getters
double Vector3D::X() const {return x_ ;}
double Vector3D::Y() const {return y_ ;}
double Vector3D::Z() const {return z_ ;}

double Vector3D::R() {return (sqrt(x_*x_ + y_*y_ + z_*z_)) ;}
double Vector3D::Magnitude() {return (sqrt(x_*x_ + y_*y_ + z_*z_)) ;}
double Vector3D::Theta() {return atan(sqrt(x_*x_ + y_*y_)/z_) ;}
double Vector3D::Phi() {return atan(x_/y_) ;}

//setters
void Vector3D::SetX (double x) { x_ = x;}
void Vector3D::SetY (double y) { y_ = y;}
void Vector3D::SetZ (double z) { z_ = z;}

void Vector3D::SetCartesian (double x, double y, double z) { x_ = x; y_ = y; z_ = z; }
void Vector3D::SetSpherical (double r, double theta, double phi) { x_ = r * sin(theta) * cos(phi); y_ = r * sin(theta) * sin(phi); z_ = r * cos(theta); }

//functions
void Vector3D::print_cartesian() {

  cout << "Vector: \t  x = " << x_ << "\t y = " << y_ << "\t z = " << z_ << endl;

}

void Vector3D::print_spherical() {

  cout << "Vector: \t  r = " << this->R()<< "\t theta = " <<  this->Theta() << "\t phi = " << this->Phi() << endl;

}


double scalarProduct(const Vector3D& V1, const Vector3D& V2) {

  return (V1.X()* V2.X() + V1.Y() * V2.Y()+ V1.Z() * V2.Z());

}


double angle (const Vector3D& V1, const Vector3D& V2){

 return ( acos(scalarProduct(V1,V2)/( sqrt(scalarProduct(V1,V1)) *( sqrt(scalarProduct(V2,V2)) ) )) ); 

}


Vector3D vectorProduct (const Vector3D& V1, const Vector3D& V2){

  double v3_x = V1.Y() * V2.Z() - V1.Z() * V2.Y();
  double v3_y = V1.Z() * V2.X() - V1.X() * V2.Z();
  double v3_z = V1.X() * V2.Y() - V1.Y() * V2.X();

  return Vector3D (v3_x, v3_y, v3_z);

}

// Overloading

  Vector3D Vector3D::operator+ (const Vector3D& rhs) const {

    double sum_x = x_ + rhs.x_;
    double sum_y = y_ + rhs.y_;
    double sum_z = z_ + rhs.z_;

    return Vector3D(sum_x, sum_y, sum_z);

  }

  Vector3D Vector3D::operator- (const Vector3D& rhs) const {

    double diff_x = x_ - rhs.x_;
    double diff_y = y_ - rhs.y_;
    double diff_z = z_ - rhs.z_;

    return Vector3D(diff_x, diff_y, diff_z);

  }

  const Vector3D& Vector3D::operator= (const Vector3D& rhs) {

    x_ = rhs.x_;
    y_ = rhs.y_;
    z_ = rhs.z_;

    return *this;

  }


  Vector3D Vector3D::operator* ( const double& rhs ) const {

    return Vector3D(x_ * rhs, y_ * rhs, z_ * rhs);

  }

  Vector3D Vector3D::operator/ ( const double& rhs ) const {

    return Vector3D(x_ / rhs, y_ / rhs, z_ / rhs);

  }


 Vector3D operator* (const double& lhs, const Vector3D& rhs) {

     return Vector3D (lhs * rhs.x_, lhs * rhs.y_, lhs * rhs.z_);

 }
