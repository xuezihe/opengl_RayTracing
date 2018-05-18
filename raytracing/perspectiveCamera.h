#ifndef PERSPECTIVECAMERA_H  
#define PERSPECTIVECAMERA_H  
#include "Ray.h"  
class perspectiveCamera {
public:
	perspectiveCamera();
	~perspectiveCamera();
	perspectiveCamera(const GVector3& _eye, const GVector3& _front, const GVector3& _refUp, float _fov);
	CRay generateRay(float x, float y);

private:
	GVector3 eye;
	GVector3 front;
	GVector3 refUp;
	float   fov;
	GVector3 right;
	GVector3 up;
	float   fovScale;
};
#endif  