# Aplikasi Garis Dengan Algoritma DDA
Pembuatan aplikasi Garis menggunakan Algoritma Bresenham dengan menggunakan libray openGL dan Glut untuk membentuk sebuah garis.

## Deskripsi
Algoritma Bresenham adalah algoritma pembentukan garis dengan pendekatan garis lurus antara dua titik yang diberikan. Pendekatan ini biasa digunakan untuk menggambar garis pada layar komputer, karena hanya menggunakan integer penambahan, pengurangan dan pergeseran. Algoritma ini merupakan salah satu algoritma paling awal yang dikembangkan di bidang komputer grafis.

## Getting Started
Menentukan Titik
```
//tentukan titik awal dan akhir
x2 = 0;
y2 = 300;
x1 = 500;
y1 = 0;
x= x1;
y= y1;
```
## Masalah Yang Ditemukan
1. Tidak dapat membuat garis vertikal dan horizontal
2. Tidak berjalan ketika x1 = x2

## Penyelesaian Masalah
1. Perbaikan Looping untuk membuat garis lurus dan garis x1 = x2
```
int iterasi = 0;
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
}
```
2. Perbaikan Tidak berjalan ketika x1 = x2
```
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
```
## Built With
* Microsoft Visual Studio Community 2015

## Contributors
* [Galang Rambu Anarki](https://dinus.ac.id/mahasiswa/A11.2015.08929)
* [Muhammad Wahyu Kuncoro](https://dinus.ac.id/mahasiswa/A11.2015.08930)
* [Rizki Ramadhan Fratama](https://dinus.ac.id/mahasiswa/A11.2015.08913)

## License
The GNU General Public License v3.0
