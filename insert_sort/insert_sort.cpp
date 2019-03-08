#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_N = 100; // max size of a tab
const int no_tabs = 1000; // number of uncorrelated assembles of tabs
fstream log;

void print_tab (double* tab, int tab_size, int iter){
    if (tab_size == 10 && iter == 0){
        for (int i = 0; i < tab_size; i++){
            log << tab[i] << " ";
        }
        log << endl << endl;
    }
}

unsigned long insert_sort (double* tab, int N, int iteration){

    double temp;
    unsigned long no_iterations = 0;
    for (int i = 1; i < N; i++){
        temp = tab[i];
        int j = i-1;

        while (j >= 0 && temp < tab[j]){
            tab[j+1] = tab[j];
            j--;
            no_iterations++;

            print_tab(tab, N, iteration);
        }
        tab[j+1] = temp;

        print_tab(tab, N,iteration);
    }
    return no_iterations;
}

double* generate_random_tab (int N){
    double* chain = new double [N];
    for (int i = 0; i < N; i++){
        chain[i] = (static_cast<double>(rand())/RAND_MAX)*100; // generating double numbers from 0 to 100
    }
    return chain;
}

void make_histogram (fstream& file, int* data_tab, int tab_size){

    const int no_elements = 100;
    int grid = ((max_N*max_N)/2)/no_elements;
    int counter[no_elements] = {0};

    for (int i = 0; i < tab_size; i++){
        for (int q = 0; q < no_elements; q++){
            if ((data_tab[i] >= (q * grid)) && (data_tab[i] < ((q + 1)*grid))){
                counter[q]++;
                break;
            }
        }
    }

    for (int j =0; j < no_elements; j++){
        file << (j*grid) << "   " << counter[j] << endl;
    }
}

int main(){

    srand(time(NULL));
    fstream data_iterations;
    fstream data_complexity;

    data_iterations.open ("data_iterations.txt", ios::out);
    data_complexity.open ("data_complexity.txt", ios::out);
    log.open("data_log.txt", ios::out);

    int size_N; // actual size of tab
    int iterations[no_tabs] = {0};


    for (size_N = 10; size_N <= max_N; size_N++){ // loop over the tab size

        unsigned long sum = 0;  // expression used in order to calculate the average iterations as a tab size function
        for (int i = 0; i < no_tabs; i++){ // loop over randomly generated tabs of equal size
            double* tabs = generate_random_tab(size_N);
            unsigned int no_iterations = insert_sort(tabs, size_N, i);
            sum += no_iterations;

            if (size_N == max_N){
                iterations[i] = no_iterations;
            }

            delete[] tabs;
        }

        data_complexity << size_N << "  " << static_cast<double>(sum)/no_tabs << endl;
    }

    make_histogram(data_iterations, iterations, no_tabs);
    data_complexity.close();
    data_iterations.close();
    log.close();

return 0;
}
