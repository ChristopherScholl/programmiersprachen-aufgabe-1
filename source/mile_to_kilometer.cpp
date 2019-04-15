#include <iostream>

double mile_to_kilometer(double m) {
	return m * 1.60934;
}

int main()
{
  std::cout << "Bitte Meilen eingeben:\n";
  double miles = 0.0;
  std::cin >> miles;
  std::cout << miles << " Meilen entsprechen " << mile_to_kilometer(miles) << "Kilometern.\n";
  return 0;
}
