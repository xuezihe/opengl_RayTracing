#include<GL\glut.h>
#include <stdlib.h>  
#include<stdio.h>  

#include"perspectiveCamera.h"
#include"Sphere.h"
//#include""
#define WINDOW_WIDTH  600  
#define WINDOW_HEIGHT 600  
void initScene(int w, int h)
{
	// ������Ӱƽ��  
	glShadeModel(GL_SMOOTH);
	// ��ɫ����  
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// ������Ȼ���  
	glClearDepth(1.0);
	// ������Ȳ���  
	glEnable(GL_DEPTH_TEST);
	// ������Ȳ��Ե�����  
	glDepthFunc(GL_LEQUAL);
	// ����ϵͳ��͸�ӽ�������  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
//����������еĻ�ͼ����  
void  display() {
	float colorSpan = 0.0005f;
	float color = 0.0f;
	float pixelSize = 2.0f;
	float posY = -1.0f;
	float posX = -1.0f;
	long maxDepth = 20;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//��ԭ���ƶ������½�  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	double dx = 1.0f / WINDOW_WIDTH;
	double dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);

	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		double sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			double sx = dx*x;
			float colorR = x*1.0 / WINDOW_WIDTH * 255;
			float colorB = y*1.0 / WINDOW_HEIGHT * 255;
			glColor3ub(colorR, 0, colorB);
			glVertex2f(sx, sy);
		}
	}
	// ����������  
	glutSwapBuffers();
}

void renderDepth() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	float horiz = 0.0;
	float dep = 10;
	perspectiveCamera camera(GVector3(horiz, 10, dep), GVector3(0, 0, -1), GVector3(0, 1, 0), 90);
	long maxDepth = 18;
	CSphere* sphere1 = new CSphere(GVector3(0, 10, -10), 10.0);
	float dx = 1.0f / WINDOW_WIDTH;
	float dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);
	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		float sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			float sx = dx*x;
			CRay ray(camera.generateRay(sx, sy));
			IntersectResult result = sphere1->isIntersected(ray);
			if (result.isHit)
			{
				double t = MIN(result.distance*dD, 255.0f);
				int depth = (int)(255 - t);
				glColor3ub(depth, depth, depth);
				glVertex2f(sx, sy);
			}

		}
	}

	glEnd();
	// ����������  
	glutSwapBuffers();
}
void renderDepth1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	perspectiveCamera camera(GVector3(0, 10, 10), GVector3(0, 0, -1), GVector3(0, 1, 0), 90);
	long maxDepth = 20;
	CSphere* sphere1 = new CSphere(GVector3(0, 10, -10), 10.0);
	CSphere* sphere2 = new CSphere(GVector3(0, 5, -10), 6.0);
	//camera.initialize();
	float dx = 1.0f / WINDOW_WIDTH;
	float dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);
	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		float sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			float sx = dx*x;
			// ������װ
			//glColor3f fRaytracingCur(camera, sphere1, sphere2, reflectnum);

			CRay ray(camera.generateRay(sx, sy));
			IntersectResult result = sphere1->isIntersected(ray);
			IntersectResult result2 = sphere2->isIntersected(ray);
			int id = 0;
			if (result.isHit&& result2.isHit)
			{
				int id = (result.distance > result2.distance) ? 2: 1;
			}
			else if (result.isHit) id = 1;
			else if (result2.isHit) id = 2;
			switch (id)
			{
			case 1:
				;
			case 2:
				;
			default:
				break;
			}
			if (result.isHit)
			{
				//double t=MIN(result.distance*dD,255.0f);  
				//int depth = (int)(255 -t);  
				//xuanranshengdu  
				//glColor3ub(depth,depth,depth);  
				//xuanran normal  
				glColor3ub(128 * (result.normal.x + 1), 128 * (result.normal.y + 1), 128 * (result.normal.z + 1));
				glVertex2f(sx, sy);
			}
		}
	}
	glEnd();
	// ����������  
	glutSwapBuffers();
}


//���ô��ڴ�С��Ļص�����  
void resize(int width, int height)
{
	// ��ֹ���ڴ�С��Ϊ0  
	if (height == 0)
	{
		height = 1;
	}
	// ���õ�ǰ���ӿ�  
	glViewport(0, 0, (GLint)width, (GLint)height);
	// ѡ��ͶӰ����  
	glMatrixMode(GL_PROJECTION);
	// ����ͶӰ����  
	glLoadIdentity();
	// �����ӿڵĴ�С  
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	// ѡ��ģ�͹۲����  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void inital111111()
{
	glutInitDisplayMode(GLUT_SINGLE);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	//inital111111();
	initScene(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutDisplayFunc(renderDepth1);
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;
}