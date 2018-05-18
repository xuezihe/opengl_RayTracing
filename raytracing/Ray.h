#ifndef CRAY_H  
#define CRAY_H  
#include <iostream>  
#include "gvector3.h"  
#define PI 3.14159  
using namespace std;
class CRay
{
private:
	GVector3 origin;
	GVector3 direction;
public:
	CRay();
	CRay(GVector3 o, GVector3 d);
	~CRay();
	void setOrigin(GVector3 o);
	void setDirection(GVector3 d);
	GVector3 getOrigin();
	GVector3 getDirection();
	//ͨ�������ߵĲ������̴������t������������ϵĵ�  
	GVector3 getPoint(double t);

};
#endif  