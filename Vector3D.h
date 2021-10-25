#include <iostream>
using namespace std;

class Vector3D {

public:
//constructor
 Vector3D (double x, double y, double z);

//getters
 double X() const;
 double Y() const;
 double Z() const;

 double R();
 double Magnitude();
 double Theta();
 double Phi();

//setters
  void SetX (double x);
  void SetY (double y);
  void SetZ (double z);

  void SetCartesian (double x, double y, double z);
  void SetSpherical (double r, double theta, double phi);

// functions
  void print_cartesian();
  void print_spherical();

  // double scalarProduct(const Vector3D& , const Vector3D& ) const;


// Overloading
  Vector3D operator+ (const Vector3D& rhs) const;
  Vector3D operator- (const Vector3D& rhs) const;
  Vector3D operator* ( const double& rhs ) const;
  Vector3D operator/ ( const double& rhs ) const ;

  const Vector3D& operator= (const Vector3D& rhs);

  friend Vector3D operator* (const double& lhs, const Vector3D& rhs);

private:
 double x_, y_, z_;


};

//global
double angle(const Vector3D& , const Vector3D& );
double scalarProduct(const Vector3D& V1, const Vector3D& V2) ;
Vector3D vectorProduct(const Vector3D&, const Vector3D& );
