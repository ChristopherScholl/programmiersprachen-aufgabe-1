#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>

//1.8
int gcd(int a, int b) {
	return 1;
}

TEST_CASE("describe_gcd", "[gcd]") {
	REQUIRE(gcd(2, 4) == 2);
	REQUIRE(gcd(9, 6) == 3);
	REQUIRE(gcd(3, 7) == 1);
}

//1.9
int checksum(int zahl) {
	int sum = 0;
	while (zahl != 0) {
		sum += zahl % 10;
		zahl = zahl / 10;
	}
	return sum;
}

TEST_CASE("describe_checksum", "[checksum]") {
	REQUIRE(checksum(-1) == -1);//die Quersumme einer negativen Zahl ist hier selbst als negative Zahl definiert
	REQUIRE(checksum(0) == 0);
	REQUIRE(checksum(1) == 1);
	REQUIRE(checksum(38) == 11);
	REQUIRE(checksum(119705) == 23);
}

//1.10
int sum_multiples() {
	int sum = 0;
	for (int i = 1; i <= 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

TEST_CASE("describe_sum_multiples", "[sum_multiples]") {
	REQUIRE(sum_multiples() == 234168);
}

//1.11
double fract(double a) {
	double f = a - (int)(a);
	return f;
}

TEST_CASE("describe_fract", "[fract]") {
	REQUIRE(fract(0.1) == Approx(0.1));
	REQUIRE(fract(1.13) == Approx(0.13));
	REQUIRE(fract(3.1415926) == Approx(0.1415926));
}

//1.12
double cylinderVolume(double height, double radius) {
	if (height < 0 || radius < 0) {
		return -1;
	}
	else {
		double circleArea = 3.1415926 * radius * radius;
		return circleArea * height;
	}
}

double cylinderArea(double height, double radius) {
	if (height < 0 || radius < 0) {
		return -1;
	}
	else {
		double circleLength = 2 * 3.1415926 * radius;
		double circleArea = 3.1415926 * radius * radius;
		double side = circleLength * height;
		return side + (circleArea * 2);
	}
}

TEST_CASE("describe_cylinder", "[cylinder]") {
	REQUIRE(cylinderVolume(-1, 1) == -1);
	REQUIRE(cylinderVolume(1, 1) == Approx(3.1415926));
	REQUIRE(cylinderVolume(12, 50) == Approx(94247.7796076));
	REQUIRE(cylinderArea(-1, 1) == -1);
	REQUIRE(cylinderArea(1, 1) == Approx(12.5663706));
	REQUIRE(cylinderArea(3, 2) == Approx(62.8318530));
}

//1.13
int factorial(int zahl) {
	if (zahl < 1) {
		return -1; //nicht erlaubt
	}
	else {
		int product = 1;

		for (int i = 1; i <= zahl; i++) {
			product *= i;
		}

		return product;
	}
}

TEST_CASE("describe_factorial", "[factorial]") {
	REQUIRE(factorial(0) == -1); //-1 = Fehler
	REQUIRE(factorial(1) == 1);
	REQUIRE(factorial(3) == 6);
	REQUIRE(factorial(5) == 120);
}

//1.14
bool is_prime(int zahl) {
	bool p = true;

	if (zahl <= 1) {
		return false;
	}
	else {
		for (int i = 2; i <= zahl / 2; ++i) {
			if (zahl % i != 0) {
				p = false;
				break;
			}
		}
		return p;
	}
}

TEST_CASE("describe_is_prime", "[is_prime]") {
	REQUIRE(is_prime(0) == false);
	REQUIRE(is_prime(1) == false);
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(3) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(5) == true);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
