#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#include "helper.cpp"
#include "vars.cpp"
#include "simulator.cpp"

void init()
{
    cout << "Generating random initial state:" << endl;
    delay(250);

    // Initial set of variables
    cout << "Boolean variables: " << endl;
    delay(500);
    nk_old = new int[nk_size];
    for(int i = 0; i < nk_size; i++)
    {
        nk_old[i] = randomBoolean();
        printf("%d ",nk_old[i]);
        delay(1);
    }
    cout << endl << endl;
    
    // Connections between variables
    delay(250);
    cout << "Generating random connections:" << endl;
    delay(500);
    nk_connec = new int *[nk_size];
    for (int i = 0; i < nk_size; i++)
        nk_connec[i] = new int[nk_num_connec];
    for(int i = 0; i < nk_size; i++)
    {
        printf("%d -> ", i);
        for(int j = 0; j < nk_num_connec; j++)
        {
            nk_connec[i][j] = randomNum(0, nk_size - 1);
            printf("%d ", nk_connec[i][j]);
            delay(1);
        }
        cout << endl;
        delay(1);
    }
    cout << endl;

    // Boolean functions
    delay(250);
    cout << "Generating boolean functions:" << endl;
    delay(500);
    truth_table = new int[nk_size];
    for(int i = 0; i < pow(2, nk_num_connec); i++)
    {
        truth_table[i] = randomBoolean();
        printf("f(%d) = %d\n", i, truth_table[i]);
        delay(1);
    }
    cout << endl;

    nk_new = new int[nk_size];
    bools = new int[nk_num_connec];
}

int main()
{
    srand(time(NULL));

    cout << "---> Random Boolean Networks <---" << endl
         << endl;
    cout << "Size of boolean network: ";
    cin >> nk_size;
    cout << "Number of connections: ";
    cin >> nk_num_connec;
    cout << "Delay between states: ";
    cin >> milli;
    cout << endl;

    init();
    simulate();
}