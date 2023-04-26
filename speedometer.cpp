#include <iostream>
#include <string>
#include <cstdio>

int main() {
    double speed = 0.0;
    double delta = 0.0;
    const double epsilon = 0.01;
    const double maxSpeed = 150.0;

    do {
        // Read the speed difference (delta) from the user
        std::cout << "Enter speed delta: ";
        std::cin >> delta;

        // Update the speed and ensure it stays within the allowed range
        speed += delta;
        if (speed > maxSpeed) {
            speed = maxSpeed;
        } else if (speed < 0.0) {
            speed = 0.0;
        }

        // Format the speed display using std::sprintf
        char speedBuffer[8];
        std::sprintf(speedBuffer, "%.1f", speed);
        std::string speed_str(speedBuffer);
        speed_str += " km/h";

        // Display the current speed
        std::cout << "Current speed: " << speed_str << std::endl;

    } while (speed > epsilon);

    return 0;
}
