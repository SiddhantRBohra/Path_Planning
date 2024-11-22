#include <iostream>
#include <string>
#include <cmath>

/**
 * A struct for holding information about a car.
 */
struct Car {
    /**
     * The make (brand) of the car.
     */
    std::string make;
    
    /**
     * The model of the car.
     */
    std::string model;

    /**
     * The year the car was made.
     */
    int year;

    /**
     * The current value of the car in dollars.
     */
    float price_dollars;

    /**
     * Whether the car is used.
     */
    bool used = false;
};

/**
 * Calculate the value of the car at some point in the future.
 * @param  car The car to calculate the value of.
 * @param  years_from_now The number of years out to estimate the value.
 * @return  The estimated value.
 * 
 * Calculate the value using value = price_now * e^(-r * t) where r is the depreciation
 * rate and t is the years_from_now. Let's say Mercedes cars have a depreciation of 15%
 * or 0.15, and Teslas have a depreciation of 25% or 0.25. All other cars have a rate of
 * 20% or 0.20.
 */
float calculateCarValue(Car car, float years_from_now) {

    float r;
    float price_now = car.price_dollars;

    if (car.make == "Mercedes") {
        r = 0.15;
    } else if (car.make == "Subaru") {
        r = 0.20;
    } else if (car.make == "Tesla") {
        r = 0.25;
    }

    float value = price_now * exp(-r * years_from_now);
    return value;


    // *** End Student Code *** //
}

int main() {

    // *** Task: Collect information about the car then calculate its value with calculate_car_value() *** //
    Car car;
    int years_from_now;
    
    std::cout << "Enter the make (brand) of the car: (Mercedes, Subaru, Tesla)" << std::endl;
    std::getline(std::cin, car.make);

    std::cout << "Enter the model of the car" << std::endl;
    std::getline(std::cin, car.model);

    std::cout << "Enter the year the car was made" << std::endl;
    std::cin >> car.year;

    std::cout << "Enter the current price of the car" << std::endl;
    std::cin >> car.price_dollars;

    std::cout << "Is the car used? Enter 0 if no, 1 for yes" << std::endl;
    std::cin >> car.used;

    std::cout << "Enter the years from now at which you want to estimate the price of the car" << std::endl;
    std::cin >> years_from_now;

    std::cout << "The price of the car " << years_from_now << " years from now is " << calculateCarValue(car, years_from_now) << std::endl;
    // *** End Student Code *** //
    return 0;
}