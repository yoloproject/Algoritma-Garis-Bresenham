// Garis Dengan Algoritma Bresenham
// Team		: Yolo
// Tanggal  : 2 November 2017
// Di Ubah  : 2 November 2017

// Pustaka
#include <GL\freeglut.h> 
#include <GL\glut.h> // Pustaka window  
#include <iostream> // Header / Pustaka C++ input dan output

using namespace std;

//identifier fungsi
void init(); // Fungsi inisialisasi
void display(void); // Fungsi Display
void bresenhamOpenGl(void);

//  posisi window di layar
int win_x; // Posisi Layar X
int win_y; // Posisi Layar Y

//  ukuran window
int win_width = 400; // Tinggi Window
int win_height = 400; // Lebar Window

//  judul window
char *judul_win = "Aplikasi Pembuat Garis Dengan Bresenham";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	win_x = (glutGet(GLUT_SCREEN_WIDTH) - win_width) / 2;
	win_y = (glutGet(GLUT_SCREEN_HEIGHT) - win_height) / 2;
	glutInitWindowSize(win_width, win_height); //set ukuran window 
	glutInitWindowPosition(win_x, win_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_win);


	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set background 
	glColor3f(1.0, 0.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks  
	glLoadIdentity(); // set matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenhamOpenGl(); //panggil fungsi bresenhamOpenGl
	glutSwapBuffers(); //swap buffer 
}

void bresenhamOpenGl(void) {

	int x1, y1, x2, y2, x, y, dx, dy, xend, p, duady, duadydx;
	//tentukan titik awal dan akhir
	x1 = 120;
	y1 = 20;
	x2 = 20;
	y2 = 100;
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

		if( (x1 == x2 && y1 < y2) || (y1 == y2 && x1 < x2) )
		{
			x = x1;
			y = y1;

		}
		else if( (x1 == x2 && y1 > y2) || (y1 == y2 && x1 > x2) )
		{
			x = x2;
			y = y2;
		}
		else
		{
			x = x1;
			y = y1;
			
		}
		xend = x2;

		if ( ((x1 != x2)) && y1 > x2)
		{
			xend = y1;
		
		}
		
		if (xend < y1)
		{
			xend = y1;
		}
		else if (xend < y2)
		{
			xend = y2;
		}


	}


	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	//perulangan untuk menggambar titik-titik 
	for (int k = x; k <= xend; k++)
	{
		if (x1 != x2)
		{
			x++;
		}

		if (p < 0) {
			p += duady;
		}

		else
		{
			if (y1 > y2 && x1 != x2)
			{
				y--;
			}
			else
			{
				y++;
			}
			
			p += duadydx;
		}
		glVertex2i(x, y);
		cout << "X : " << x << " " << "Y : " << y << "\n" ;

	}

	glEnd();
	glFlush();
}

