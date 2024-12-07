#include <graphics.h>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
vector<int> numbers;
int size = 20;
int gap = 4;
void swap_colors(int i, int j, int x, int y)
{
    setcolor(GREEN);
    line(j, size, j, size - y);

    delay(1000);

    setcolor(BLACK);
    line(j, size, j, size - y);

    setcolor(WHITE);
    line(j, size, j, size - x);
    
    setcolor(BLACK);
    line(i, size, i, size - x);

    setcolor(GREEN);
    line(i, size, i, size - y);

    delay(500);

    setcolor(WHITE);
    line(i, size, i, size - y);
}
void selsort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(numbers[min_idx], numbers[i]);

        swap_colors(gap * i + 1,
                    gap * (min_idx) + 1,
                    numbers[min_idx],
                    numbers[i]);
    }
}
int main()
{

    int gd = DETECT, gm;
    int wid1;
    initgraph(&gd, &gm, NULL);

    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

    for (int i = 1; i <= size; i++)
        numbers.push_back(i);

    srand(static_cast<unsigned>(time(0)));
    
    random_shuffle(numbers.begin(), numbers.end());

    for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - numbers[i / gap]));
    }

    delay(1000);

    selsort();

    delay(5000);
    
    closegraph();

    return 0;
}

