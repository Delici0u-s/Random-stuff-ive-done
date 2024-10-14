#include <stdio.h>
#include <stdlib.h>

//randint function
int randint(int min, int max){
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    return rand() % (max - min + 1) + min;
}

int main(void){
    // settable vars
    int SEED = 1;
    int repetitions = 5;
    int genmin = 0;
    int genmax = 1;

    //other for program
    int min = genmax;
    int max = genmin;
    srand(SEED);

    // innitialize result array
    int yap = abs(min - max)+1;
    int result[yap];
    for (int i = 0; i < yap; i++) {
        result[i] = 0;
    }

    // test randoutputresults
    for (int i = 0; i < repetitions; i++) {
        int tmp = randint(genmin, genmax);
        if (tmp < min){
            min = tmp;
        }
        else if (tmp > max){
            max = tmp;
        }
        result[tmp]++;
    }

    // give every random val:
    int Getspecific = 1; // 0 if yes
    //get gighest roll, and how often
    int maxc[] = {0,0};
    for (int i = 0; i < yap; i++) {
        if (result[i] > maxc[0]){
            maxc[0]=result[i];
            maxc[1]=i;
        }
        if (Getspecific == 0){
            printf("For %i: %i \n", i, result[i]);
        }
    }
    
    //all the printouts
    printf("Given: Min: %i, Max: %i, Repetitions: %i, with Seed: %i\n", genmin, genmax, repetitions, SEED);
    printf("in Generation: Min: %i Max: %i\n", min, max);
    printf("Highest gen: %i, with count %i\n", maxc[1], maxc[0]);
}

