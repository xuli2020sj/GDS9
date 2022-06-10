#include "Calculation.h"
#include <chrono>
#include <iostream>
#include <string>


void calculate() {
    Calculation CalculationB;
    CalculationB.TypeOfCal = 0;
    CalculationB.IsOnCal = true;

    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    CalculationB.StartDoing();
    CalculationB.m_FileName = "";
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::cout << "Run Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << "ms.\n";
}

int main() {
    calculate();
}
