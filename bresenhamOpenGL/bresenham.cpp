//Algoritma Bresenham

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void bresenham(int a, int b, int c, int d);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Bresenham";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window); //set judul window

	
	init(); //jalankan fungsi init 
	glutDisplayFunc(display); //  set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(200, 200, 400, 400);//jalankan fungsi bresenham
	bresenham(200, 400, 400, 100);
	
	bresenham(500, 500, 600, 500);
	bresenham(100, 100, 20, 100);
	bresenham(200, 100, 300, 100);
	bresenham(400, 100, 500, 100);
	bresenham(600, 100, 700, 100);

	bresenham(100, 200, 100, 500);
	bresenham(600, 200, 600, 500);
	glutSwapBuffers(); //swap buffer 
}

void bresenham(int a, int b, int c, int d) {
	int x1, y1, x2, y2, x, y, dx, dy, xend, p, duady, duadydx;
	//tentukan titik awal dan akhir
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	
	//hitung p 
	p = 2 * dy - dx;
	duady = 2 * dy;
	duadydx = 2 * (dy - dx);
	
	//tentukan titik awal dan akhir
	if (x1 > x2) {
		x = x2;
		y = y2;
		xend = x1;
	}
	else
	{
		x = x1;
		y = y1;
		xend = x2;
	}

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	//perulangan untuk menggambar titik-titik 
	while (x < xend) {
		x++;
		if (p < 0) {
			p += duady; //p+duady
		}
		else
		{
			if (y1 > y2) {
				y--; //dimulai dari besar ke kecil
			}
			else y++;
		
			p += duadydx;
		}
		glVertex2i(x, y);
	}

	glEnd();
	glFlush();
}

