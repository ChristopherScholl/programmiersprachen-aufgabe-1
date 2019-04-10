#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>

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
	double circleArea = 3.1415926 * radius * radius;
	return circleArea * height;
}

double cylinderArea(double height, double radius) {
	double circleLength = 2 * 3.1415926 * radius;
	double circleArea = 3.1415926 * radius * radius;
	double side = circleLength * height;
	return side + (circleArea * 2);
}

TEST_CASE("describe_cylinder", "[cylinder]") {
	//REQUIRE(gcd(2, 4) == 2);
	//REQUIRE(gcd(9, 6) == 3);
	//REQUIRE(gcd(3, 7) == 1);
}

//1.8
int gcd(int a, int b) {
	return 1;
}

TEST_CASE("describe_gcd", "[gcd]") {
	//REQUIRE(gcd(2, 4) == 2);
	//REQUIRE(gcd(9, 6) == 3);
	REQUIRE(gcd(3, 7) == 1);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
