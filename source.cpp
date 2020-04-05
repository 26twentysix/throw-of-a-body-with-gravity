#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(0, "");
	const double G = 9.80665;
	const double PI = 3.14159265358979323846;
	double x = 0;
	double y = 0;
	double angleInRad = 0;
	double time = 0;
	double timeInFly = 0;
	double angle = 0;
	double speed = 0;
	cout << "Введите скорость тела(в м/c), угол(в градусах) броска относительно земли и время(в секундах), прошедшее с момента броска: \n";
	cin >> speed >> angle >> time;
	angleInRad = angle * (PI / 180);
	timeInFly = (2 * speed * sin(angleInRad)) / G; 
	if (timeInFly < time) { 
		time = timeInFly;
	}
	y = (speed * sin(angleInRad) * time - ((G * (time * time)) / 2)); 
	x = speed * cos(angleInRad) * time; 
	cout << "Координаты тела в заданный момент времени: " << x << ", " << y; 
}
