#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(0, "");
	const double G = 9.80665;
	const double PI = 3.14159265358979323846;
	double x = 0;
	double y = 0;
	double angleInRad;
	double time;
	double timeInFly;
	double angle;
	double speed;
	double collisionSpeed;
	bool trigger = true;
	double arrayOfX[] = { 10, 11 };
	double arrayOfY[] = { 10, 11 };
	cout << "Введите скорость тела(в м/c) и угол(в градусах) броска относительно земли \n";
	cin >> speed >> angle;
	angleInRad = angle * (PI / 180); 
	time = (2 * speed * sin(angleInRad)) / G;
	double strtTime = 0.00001;
	while (trigger == true) {
		y = speed * sin(angleInRad) * strtTime - ((G * (strtTime * strtTime)) / 2); 
		x = speed * cos(angleInRad) * strtTime; 
		collisionSpeed = sqrt(pow(speed, 2) * pow(sin(angleInRad), 2) + pow((speed * sin(angleInRad) - G * pow(strtTime, 2)), 2));
		if (x > arrayOfX[0] && x < arrayOfX[1]) {
			if (y > arrayOfY[0] && y < arrayOfY[1]) {
				trigger = false;
				cout << "Произошло столкновение на скорости " << collisionSpeed << ",координаты тела в момент столкновения: " << x << ", " << y << "\n";
				if (x < arrayOfX[1]) {
					cout << "После столкновения тело упало вниз до координаты y = 0";
				}
			}
		}
		if (strtTime > time) {
			strtTime = time;
			y = speed * sin(angleInRad) * strtTime - ((G * (strtTime * strtTime)) / 2);
			x = speed * cos(angleInRad) * strtTime;
			trigger = false;
			cout << "Столкновения не произошло, координаты тела: " << x << ", " << y;
		}
		strtTime += 0.00001;
	}
}
