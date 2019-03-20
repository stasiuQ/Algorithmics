#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_N = 100; // max size of a tab
const int no_tabs = 10000; // number of uncorrelated assembles of tabs
int no_iterations;

void print_tab (double* tab, int tab_size, int iter){
    if (tab_size == 10 && iter == 10){
        for (int i = 0; i < tab_size; i++){
            cout << tab[i] << " ";
        }
        cout << endl << endl;
    }
}

int partitioning (double* tab, int start, int finish){

    int i = start - 1;
    int j = finish + 1;
    double pivot = tab[static_cast<int>((start + finish)/2)];

    while (1){
        do {
            i++;
            no_iterations++;
        } while (tab[i] < pivot);
        do {
            j--;
            no_iterations++;
        } while (tab[j] > pivot);

        if (i >= j)
            return j;
        //swapping tab[i] with tab[j]
        swap(tab[i], tab[j]);
    }
}

double quick_search (double* tab, int first, int last, int k){
    if (last > first){
        int p = partitioning(tab, first, last);
        if (p == k){
            return tab[k];
        }
        else if (p > k){
            no_iterations++;
            quick_search(tab, first, p, k);
        }
        else if (p < k){
            no_iterations++;
            quick_search(tab, p + 1, last, k);
        }
    }
    return tab[k];
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
    int grid = ((max_N*max_N)/10)/no_elements;
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

int main (){
    /*
    srand(time(NULL));
    int size_N = 10;
    for (int q = 0; q < 10; q++){
        double* tabs = generate_random_tab(size_N);
        print_tab(tabs, size_N, 10);
        cout << quick_search(tabs, 0, size_N - 1, q) << endl;;
        print_tab(tabs, size_N, 10);
        delete[] tabs;
    }
    */
    srand(time(NULL));
    fstream data_iterations;
    fstream data_complexity;

    data_iterations.open ("data_iterations.txt", ios::out);
    data_complexity.open ("data_complexity.txt", ios::out);

    int size_N; // actual size of tab
    int iterations[no_tabs] = {0};


    for (size_N = 10; size_N <= max_N; size_N++){ // loop over the tab size

        unsigned long sum = 0;  // expression used in order to calculate the average iterations as a tab size function

        for (int i = 0; i < no_tabs; i++){ // loop over randomly generated tabs of equal size
            no_iterations = 0;
            double* tabs = generate_random_tab(size_N);
            int random_element = rand()% (size_N-1); // generating an element to be found

            print_tab(tabs, size_N, i);
            quick_search(tabs, 0, size_N - 1, random_element);
            print_tab(tabs, size_N, i);

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

    return 0;
}
