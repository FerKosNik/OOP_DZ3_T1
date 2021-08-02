#include <iostream>
using namespace std;

template <typename T1>
class Pair1 {
public:
    Pair1(T1 first, T1 second) {
        m_first = first;
        m_second = second;
    }

    T1 first() { return m_first; }
    T1 second() { return m_second; }

private:
    T1 m_first;
    T1 m_second;
};

//template <typename T1>
//class Pair1 : public const Pair1<T1> {
//public:
//    Pair1(const T1 first, const T1 second) :Pair(first, second) {
//        m_first = first;
//        m_second = second;
//    }
//
//    const T1 first() { return m_first; }
//    const T1 second() { return m_second; }
//    const T1 m_first;
//    const T1 m_second;
//};

template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) {
        m_first = first;
        m_second = second;
    }
    
    T1 first() { return m_first; }

    T2 second() { return m_second; }
private:
    T1 m_first;
    T2 m_second;
};






int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    //const Pair1<double> p2(3.4, 7.8);
    //cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    //=========================//

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    //const Pair<const double, const int> p2(3.4, 5);
    //cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    
    return 0;
}
