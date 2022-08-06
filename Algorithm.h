#ifndef algorithm_H
#define algorithm_H

class Algorithm{
    protected:
        int number_of_partitions;
        int *partitions;
        int *original_partitions; //particiones originales, es necesario para mostrar la particion en la que el Pn se alojo 
        int number_of_processes;
        int *processes;
    public:
    Algorithm(int number_of_partitions, int *partitions, int number_of_processes, int *processes){
        this->number_of_partitions = number_of_partitions;
        this->partitions = partitions;
        this->original_partitions = new int[number_of_partitions];
        for(int i=0; i<number_of_partitions; i++){
            original_partitions[i] = partitions[i];
        }
        this->number_of_processes = number_of_processes;
        this->processes = processes;
    }
    virtual void allocate() = 0;
};

#endif