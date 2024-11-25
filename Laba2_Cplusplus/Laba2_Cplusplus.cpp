

#include <iostream>
#include <vector>
#include <list>
#include "Info.hpp"


void processVector(const std::vector<Number>& numbers) {
    std::cout << "\n" << std::endl;
    std::cout << "--------processVector-" << std::endl;
    for (const auto& num : numbers) {
        std::cout << "Number: " << num.getValue() << ", String: " << num.getStringValue() << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "\n" << std::endl;
}

void processList(const std::list<Number>& numbers) {
    std::cout << "\n" << std::endl;
    std::cout << "--------processList-" << std::endl;
    for (const auto& num : numbers) {
        std::cout << "Number: " << num.getValue() << ", String: " << num.getStringValue() << std::endl;
    }
    std::cout << "----------------------" << std::endl;


}

Number createNumber(int val) {//just for fun
    return Number(val);
}


int main() {

    setlocale(LC_ALL, "Russian");

    Number num1(1);
    Number num2(2);
    Number num3(3);
    Number num4(4);

    Number* num5 = new Number(5);
    Number* num6 = new Number(6);
    Number* num7 = new Number(7);
    Number* num8 = new Number(8);

    std::cout << "--------start-" << std::endl;

    std::list<Number> numberList;
    numberList.push_back(num1);
    std::cout << "--------push_back-" << std::endl;
    numberList.push_back(num2);
    std::cout << "--------push_back-" << std::endl;

    std::vector<Number> numberVector;

    numberVector.emplace_back(num3);
    std::cout << "--------emplace_back-" << std::endl;
    numberVector.emplace_back(num4);
    std::cout << "--------emplace_back-" << std::endl;

    numberVector.emplace_back(*num5);
    std::cout << "--------emplace_back-" << std::endl;
    numberVector.emplace_back(*num6);
    std::cout << "--------emplace_back-" << std::endl;
    numberVector.emplace_back(*num7);
    std::cout << "--------emplace_back-" << std::endl;
    numberVector.emplace_back(*num8);
    std::cout << "--------emplace_back-" << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "vv - assign - vv" << std::endl;
    std::cout << "\n" << std::endl;



    //!noexcept
    Number num9 = createNumber(9);
    std::cout << "[ Created number9: " << num9.getValue() << ", String: " << num9.getStringValue() << " ]" << std::endl;

    std::cout << "Modifying number (!noexcept): " << num1.getValue() << std::endl;
    num1 = num9;

    std::cout << " to " << num9.getValue() << std::endl;

    std::cout << "\n" << std::endl;

    //noexcept
    Number num0 = createNumber(0);
    std::cout << "[ Created number0: " << num0.getValue() << ", String: " << num0.getStringValue() << " ]" << std::endl;

    std::cout << "Modifying number (noexcept): " << num2.getValue() << std::endl;
    num2 = std::move(num0);

    std::cout << " to " << num0.getValue() << std::endl;

    std::cout << "\n" << std::endl;

    //++ --
    Number sum = num1 + num2;
    Number difference = num4 - num3;

    std::cout << "Сумма: " << sum.getValue() << ", Строка: " << sum.getStringValue() << std::endl;
    std::cout << "Разность: " << difference.getValue() << ", Строка: " << difference.getStringValue() << std::endl;


    processList(numberList);
    processVector(numberVector);

    delete num5, num6, num7, num8;

    return 0;
}
