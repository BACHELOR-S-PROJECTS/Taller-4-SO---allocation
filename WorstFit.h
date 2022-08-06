#include "Algorithm.h"
#include <iostream>
using namespace std;

class WorstFit: public Algorithm{
    public:
    WorstFit(int number_of_partitions, int *partitions, int number_of_processes, int *processes):Algorithm(number_of_partitions, partitions, number_of_processes, processes){}
    virtual void allocate(){
        for (int i = 0; i < this->number_of_processes; i++){
            int major_difference = -1;
            int partition = -1;
            for (int j = 0; j < this-> number_of_partitions; j++){
                if(((major_difference < (*(partitions + j) - *(processes + i))) || (major_difference == -1)) && ((*(partitions+j) - *(processes+i))>-1)){
                    major_difference = *(partitions+j) - *(processes+i);
                    partition = j;
                }   
            }
            if (partition == -1){
                cout << "P" << i << " -> " <<processes[i] << " Not allocated." << endl;
            }
            else{
                cout << "P" << i << " -> " << processes[i]<< " is put in " << partitions[partition]<< ", " << partition+1 << " partition." << endl;
                partitions[partition] = partitions[partition] - processes[i];
            }
        }

    }
};