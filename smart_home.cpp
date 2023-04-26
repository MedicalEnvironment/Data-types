#include <iostream>
#include <string>
#include <sstream>

enum Switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void printSwitchState(int switches_state, int color_temperature) {
    std::cout << "Current state: " << std::endl;

    if (switches_state & LIGHTS_INSIDE) {
        std::cout << "Inside lights: ON, color temperature: " << color_temperature << "K" << std::endl;
    } else {
        std::cout << "Inside lights: OFF" << std::endl;
    }

    if (switches_state & LIGHTS_OUTSIDE) {
        std::cout << "Outside lights: ON" << std::endl;
    } else {
        std::cout << "Outside lights: OFF" << std::endl;
    }

    if (switches_state & HEATERS) {
        std::cout << "Heaters: ON" << std::endl;
    } else {
        std::cout << "Heaters: OFF" << std::endl;
    }

    if (switches_state & WATER_PIPE_HEATING) {
        std::cout << "Water pipe heating: ON" << std::endl;
    } else {
        std::cout << "Water pipe heating: OFF" << std::endl;
    }

    if (switches_state & CONDITIONER) {
        std::cout << "Conditioner: ON" << std::endl;
    } else {
        std::cout << "Conditioner: OFF" << std::endl;
    }
}

int main() {
    int switches_state = 0;
    int color_temperature = 5000;

    for (int day = 0; day < 2; ++day) {
        for (int hour = 0; hour < 24; ++hour) {
            std::string input;
            std::cout << "Day " << day + 1 << " - " << "Hour " << hour << ": ";
            std::cout << "Enter outside temp, inside temp, movement outside (yes/no), inside light (on/off): ";
            std::getline(std::cin, input);
            std::istringstream input_stream(input);

            int outside_temp, inside_temp;
            std::string movement, inside_light;

            input_stream >> outside_temp >> inside_temp >> movement >> inside_light;

            if (outside_temp < 0) {
                switches_state |= WATER_PIPE_HEATING;
            } else if (outside_temp > 5) {
                switches_state &= ~WATER_PIPE_HEATING;
            }

            if (inside_temp < 22) {
                switches_state |= HEATERS;
            } else if (inside_temp >= 25) {
                switches_state &= ~HEATERS;
            }

            if (inside_temp >= 30) {
                switches_state |= CONDITIONER;
            } else if (inside_temp <= 25) {
                switches_state &= ~CONDITIONER;
            }

            if (inside_light == "on") {
                switches_state |= LIGHTS_INSIDE;
            } else {
                switches_state &= ~LIGHTS_INSIDE;
            }

            if (hour >= 16 && hour < 5) {
                if (movement == "yes") {
                    switches_state |= LIGHTS_OUTSIDE;
                } else {
                    switches_state &= ~LIGHTS_OUTSIDE;
                }
            } else {
                switches_state &= ~LIGHTS_OUTSIDE;
            }

            if (hour >= 16 && hour <= 20 && switches_state & LIGHTS_INSIDE) {
                int time_passed = hour - 16;
                int total_duration = 20 - 16;
                color_temperature = 5000 - (time_passed * (5000 - 2700) / total_duration);
            } else if (hour == 0) {
                color_temperature = 5000;
            }

            std::cout << "Day " << day + 1 << " - " << "Hour " << hour << std::endl;
            printSwitchState(switches_state, color_temperature);
            std::cout << "------------------------------" << std::endl;
        }
    }

    return 0;
}
