#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>
#include <math.h>

/*!
 * \brief Класс, позволяющий работать с координатами
 *
 * Создаёт поле шириной 2 ячейки и произвольной длины
 * Примерная схема расположения ячеек -
 * 0 |2|4|6|8|10  |\n
 *   |------------|\n
 * 1 |1|3|5|7|9|11|\n
 *
 * Все чётные ячейки расположены сверху, все нечётные - снизу
 *
 *
*/

class coordinates
{
public:
    /*! \brief Конструктор, по которому задаётся текущее расположение в координатах
    */
    coordinates(uint64_t x, uint64_t y);
    //! Конструктор, по которому задаётся текущее расположение по номеру ячейки
    //! \throw std::out_of_range В случае передачи конструтору переменной, равной нулю
    coordinates(uint64_t number);
    //! Пустой конструктор, задающий значение (1; 0), в программе не используется
    coordinates();

    //! Получить координату x
    uint64_t x() const;
    //! Получить координату y
    uint64_t y() const;
    //! Получить номер текущей ячейки
    uint64_t number() const;

    //! Поменять координату y на противоположную. Т.е. с 0 на 1 и с 1 на 0,
    void changeY();
    //! Сдвинутся на 1 вправо по координате x
    void moveRight();
    //! Сдвинутся на 1 влево по координате x
    void moveLeft();

    //! \brief Оператор, сравнивающий 2 координаты. Возвращает истинное значение, если координаты не равны
    //! Координаты не равные, если у них отличается хотя бы 1 значение.
    bool const operator !=(const coordinates &otherCoords);
    //! \brief Оператор, сравнивающий 2 координаты. Возвращает истинное значение, если координаты равны
    bool const operator ==(const coordinates &otherCoords);

private:
    //! Координата x
    uint64_t m_x;
    //! Координата y
    uint64_t m_y;

    //! Номер ячейки
    uint64_t m_number;
    //! \brief Обновить номер ячейки
    //! \details Для получения ячейки текущая координата x умножается на 2, и, если координата y нечётная, отнимается 1
    void updateNumber();
};

#endif // COORDINATES_H
