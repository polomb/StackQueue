#ifndef __List_Zadacha__
#define __List_Zadacha__

#include <iostream>
#include <algorithm>
#include "list.h"

using namespace std;

template<class Iterator>
Iterator ZadachaNumberSixteen(Iterator first)
{
    if (first == Iterator(nullptr) || ++Iterator(first) == Iterator(nullptr))
    {
        return Iterator(nullptr);
    }
    Iterator slow = first;
    Iterator fast = first;
    while (fast != nullptr && ++Iterator(fast) != nullptr)
    {
        ++slow;
        ++fast;
        if (++fast == Iterator(nullptr)) 
            break;
        if(slow == fast)
        {
            //См коммент
            Iterator tochka = slow;
            Iterator nachalo = first;
            while (tochka != nachalo)
            {
                ++tochka;
                ++nachalo;
            }
            return  nachalo;
        }
    }
    return Iterator(nullptr);
}
/*
У меня точно находится точка вы цикле. Причём путь slow = m + С, где m - до первой в цикле, 
С - прошёл дальше в цикл. Понимая, что slow точно не прошёл цикл, то С < k, где k - величина цикла.
Путь fast явно больше = 2 * slow = 2m + 2C = m + С + k * l, l = кол-во кругов, которые прошёл fast =>
m + C = k * l => m = k * l - C => m = (k-C) + k*(l-1). k-C - расстояние до начала цикла
если идти вперёд. И вот тут гениальное: Если пойти из этой точки и из начальной, и начальная пройдёт m
шагов, то та точечная пройдёт (k-C) + k*(l-1), а как мы уже поняли k-C приведёт нас в начало цикла, а
k*(l-1) нас будет приводить в ту же начальную точку. УРААААААА
*/
#endif

