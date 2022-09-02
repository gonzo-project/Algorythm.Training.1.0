/*
Name: triangle
Author: roboco
Date: 02.09.2022 11:20
Task name: B. Треугольник
Descriprion:	Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это возможно, выведите строку YES, иначе выведите строку NO.
Треугольник — это три точки, не лежащие на одной прямой.
*/

#include <iostream>
#include <fstream>

int main() {

	std::ifstream file{"input.txt"};

	int a, b, c;
	file >> a >> b >> c;

	if (a + b > c && a + c > b && c + b > a) std::cout << "YES";
	else std::cout << "NO";
	
	return 0;
}
