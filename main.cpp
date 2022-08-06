#include <iostream>
#include "Algorithm.h"
#include "FirstFit.h"
#include "BestFit.h"
#include "WorstFit.h"

using namespace std;

int main(){
    string line = "";

    //Hallo el metodo
    getline(cin, line);
    int method = stoi(line);

    //Hallo el numero de particiones
    getline(cin, line);
    int number_of_partitions = stoi(line);

    //Hallo el array de particiones
    int *partitions = new int[number_of_partitions];
    for (int i = 0; i < number_of_partitions; i++){
        getline(cin,line);
        partitions[i] = stoi(line);
    }

    //Hallo el numero de procesos
    getline(cin, line);
    int number_of_processes = stoi(line);

    //Hallo el array de procesos
    int *processes = new int[number_of_processes];
    for (int i = 0; i < number_of_processes; i++){
        getline(cin,line);
        processes[i] = stoi(line);
    }

    Algorithm *first_Fit = new FirstFit(number_of_partitions,partitions,number_of_processes,processes);
    Algorithm *best_fit = new BestFit(number_of_partitions,partitions,number_of_processes,processes);
    Algorithm *worst_fit = new WorstFit(number_of_partitions,partitions,number_of_processes,processes);

    switch (method)
    {
        case 1:
                first_Fit->allocate();
                break;
        case 2:
                best_fit->allocate();
                break;
        case 3:
                worst_fit->allocate();
                break;
    }
}