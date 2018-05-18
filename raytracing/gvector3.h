#ifndef GVECTOR3_H  
#define GVECTOR3_H  
#include <iostream>  
#include <cmath>  
#define MIN(x,y) (x)>(y)?(y):(x);  
#define MAX(x,y) (x)>(y)?(x):(y);  
using namespace std;


class GVector3
{

public:
	float x;
	float y;
	float z;
	// ȱʡ���캯��  
	GVector3();
	~GVector3();
	// �û����캯��  
	GVector3(float posX, float posY, float posZ);
	//���������Ϣ  
	void getInfo();
	//ʸ���ӷ�  
	GVector3 operator+(GVector3 v);
	//ʸ������  
	GVector3 operator-(GVector3 v);
	//����  
	GVector3 operator*(float n);
	//����  
	GVector3 operator/(float n);
	//�������  
	float dotMul(GVector3 v2);
	//�������  
	GVector3 crossMul(GVector3 v2);
	//����ֵ��  
	GVector3 abs();
	//��ȡ�����е����ֵ  
	float max();
	//��ȡ��������Сֵ  
	float min();
	//��ȡʸ������  
	float getLength();
	//������λ��  
	GVector3 normalize();
	//������֮��ľ���  
	float getDist(GVector3 v);
	//����������  
	static inline GVector3 zero() { return GVector3(0, 0, 0); }
	//��ӡ�����ķ���ֵ  
	void show();

};

#endif // GVECTOR3_H  