#include <iostream>
#include <cmath>
#include <string>

class Rocket {
public:
	void launch(int fuel, int acceleration) {
		int speed = 0;
		int height = 0;

		std::cout << "\nLaunching rocket...\n" << std::endl;

		while (fuel > 0) {
			fuel -= 10;
			speed += acceleration;
			height += speed;

			std::cout << "Fuel: " << fuel
				  << " | Speed: " << speed
				  << " | Height: " << height
				  << std::endl;
		}
	}
};

class Satellite {
public:
	void simulateOrbit(double radius, double angularSpeed, int steps) {
		double angle = 0;

		std::cout << "\nSimulating orbit...\n" << std::endl;

		for (int t = 0; t < steps; t++) {
			double x = radius * cos(angle);
			double y = radius * sin(angle);

			std::cout << "t=" << t
				  << " | x=" << x
				  << " | y=" << y
				  << std::endl;
			angle += angularSpeed;
		}
	}
};

void showMenu() {
	std::cout << "===== SPACE CONTROL =====" << std::endl;
	std::cout << "1. Launch rocket" << std::endl;
	std::cout << "2. Simulate satellite orbit" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Chose: ";
}

int main() {
	Rocket r;
	Satellite s;
	int choice;

	while(true) {
		showMenu();
		std::cin >> choice;

		switch (choice) {
			case 1: {
					int fuel, acc;

					std::cout << "Enter fuel: ";
					std::cin >> fuel;

					if (fuel <= 0) {
						std::cout << "Invalid fuel value.\n";
						break;
					}

					std::cout << "Enter acceleration: ";
					std::cin >> acc;

					if (acc <= 0) {
						std::cout << "Invalid acceleration value.\n";
						break;
					}

					r.launch(fuel, acc);
					break;
				}
			case 2: {
					double r, a;
					int steps;

					std::cout << "Enter orbit radius: ";
					std::cin >> r;
					if (r <= 0) {
						std::cout << "Invalid orbint radius value.\n";
						break;
					}

					std::cout << "Enter angular speed: ";
					std::cin >> a;
					if (a <= 0) {
						std::cout << "Invalid angular speed value.\n";
						break;
					}

					std::cout << "Enter simulation steps: ";
					std::cin >> steps;
					if (steps <= 0) {
						std::cout << "Invalid steps value.\n";
						break;
					}

					s.simulateOrbit(r, a, steps);
					break;
				}

			case 3:
				std::cout << "Exiting..." << std::endl;
				return 0;

			default:
				std::cout << "Invalid option.\n" << std::endl;
		}
	}
}
