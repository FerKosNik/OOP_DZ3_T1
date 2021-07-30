#include <iostream>
#include <cassert>

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);
        
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int* data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int* data = new int[m_length + 1];

        // Копируем все элементы до index-а
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data[index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    // для удаления последнего элемента массива (аналог функции pop_back() в векторах)
    void pop_back() {
        m_data[m_length];
        --m_length;
    }
    // для удаления первого элемента массива(аналог pop_front() в векторах)
    
    void pop_front() {
        // Создаем новый массив на один элемент меньше старого массива
        int* data = new int[m_length - 1];

        // Копируем все элементы со второго
        for (int i = 0; i < m_length-1; ++i)
            data[i] = m_data[i+1];

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        --m_length;

    }
    //    для сортировки массива
    
    void sort() {
        int temp;
        for (int i = 0; i < m_length-1; ++i) {
            for (int j = i; j < m_length; ++j)
                if (m_data[i] > m_data[j])
                {
                    temp = m_data[i]; m_data[i] = m_data[j]; m_data[j] = temp;
                }
        }
        
    }
    
    //    для вывода на экран элементов

    void show() {
        for (int i = 0; i < m_length; ++i) {
            std::cout << m_data[i] << std::endl;
        }
    }

};


int main() {
    ArrayInt arr1(5);
    arr1.insertBefore(12, 0);
    arr1.insertBefore(3, 1);
    arr1.insertBefore(41, 2);
    arr1.insertBefore(25, 3);
    arr1.insertBefore(16, 4);
    arr1.pop_back();
    arr1.pop_back();
    arr1.pop_back();
    arr1.pop_back();
    arr1.pop_back();
    
    arr1.show();
    arr1.sort();
    arr1.show();
    return 0;
}