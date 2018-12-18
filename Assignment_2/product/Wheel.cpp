#include "Wheel.h"
// OK
Wheel::Wheel(int d, const string& mat)
{
	setMaterial(mat);
	diameter = d;
}
// OK
string Wheel::getMaterial() const
{
	return material;
}
// OK
void Wheel::setMaterial(const string& mat)
{
	material = mat;
}
// OK
int Wheel::getDiameter() const
{
	return diameter;
}
