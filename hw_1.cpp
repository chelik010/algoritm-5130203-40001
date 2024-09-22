#include <iostream>

using namespace std;

int main() {
    int area, coverageType, materialType, floors;
    int hasWaterAndSewage;
    double basePrice, finalPrice;

    // Ввод данных
    cout << "Введите площадь земельного участка (в квадратных метрах): ";
    cin >> area;

    cout << "Выберите тип покрытия (1 - крыша, 2 - без крыши, 3 - сад): ";
    cin >> coverageType;

    cout << "Выберите тип материала (1 - высококачественный, 2 - саман, 3 - другой): ";
    cin >> materialType;

    cout << "Есть ли вода и канализация? (1 - да, 0 - нет): ";
    cin >> hasWaterAndSewage;

    cout << "Сколько этажей на участке: ";
    cin >> floors;

    // Рассчет базовой стоимости
    if (coverageType == 1) {
        basePrice = area * 5000;
    } else if (coverageType == 2) {
        basePrice = area * 3000;
    } else {
        basePrice = area * 1000;
    }

    // Применение коэффициента материала
    if (materialType == 1) {
        basePrice *= 1.15;
    } else if (materialType == 2) {
        basePrice *= 1.10;
    } else {
        basePrice *= 1.05;
    }

    // Добавление стоимости воды и канализации
    if (hasWaterAndSewage == 1) {
        basePrice += 2500;
    }

    // Применение коэффициента этажности
    if (floors == 2) {
        basePrice *= 1.10;
    } else if (floors == 3 || floors == 4) {
        basePrice *= 1.15;
    } else if (floors > 4) {
        basePrice *= 1.20;
    }

    // Итоговая стоимость
    finalPrice = basePrice;

    // Вывод результата
    cout << "Налог на имущество: " << finalPrice << " тыс. рублей" << endl;

    return 0;
}
