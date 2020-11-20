#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "helper.cpp"
#include "vars.cpp"

using namespace std;

void displayNext()
{
    for(int i = 0; i < nk_size; i++)
    {
        for(int j = 0; j < nk_num_connec; j++)
        {
            if(nk_old[nk_connec[i][j]])
                bools[j] = 1;
            else bools[j] = 0;
        }
        nk_new[i] = truth_table[toDecimal(bools, nk_num_connec)];
    }
    for(int i = 0; i < nk_size; i++)
    {
        if(nk_new[i])
            printf("1 ");
        else
            printf("  ");
        nk_old[i] = nk_new[i];
    }
    cout << endl;
}

void simulate()
{
    int key, value;
    do 
    {
        displayNext();
        delay(milli);
    } while(!kbhit());

    key = getch();
    if(key == 0xE0)
    {
        value = getch();
        if(value == 72)
        {
            printf("Up key!");
        }
    }
    else if(key == 'p')
    {
        printf("P key!");
    }

    simulate();
}