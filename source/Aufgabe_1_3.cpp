#include <iostream>

int main()
{
	int kgV = 0;
	bool foundKgV = false;

	while (foundKgV == false) {
		kgV += 20;
		//std::cout << kgV << std::endl;	//<-- auskommentieren für Spaß

		if (kgV % 19 == 0) {
			if (kgV % 18 == 0) {
				if (kgV % 17 == 0) {
					if (kgV % 16 == 0) {
						if (kgV % 15 == 0) {
							if (kgV % 14 == 0) {
								if (kgV % 13 == 0) {
									if (kgV % 12 == 0) {
										if (kgV % 11 == 0) {
											foundKgV = true;	//Das hier hätter auch eine for-Schleife sein können
										}
									}
								}
							}
						}
					}
				}
			}
		}
	
	}

	std::cout << "kgV: " << kgV << std::endl;
	return 0;
}

