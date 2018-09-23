// André de Souza Ferreira //
// Código completo //

# include <stdio.h>

void checkbal(int vetor[], int N);

int main() {
    int t, i = 0;
    scanf("%d", &t);
    while (i < t) {
        int n, j;
        scanf("%d", &n);
        int num[n];
        for (j = 0; j < n; j++) {
            scanf("%d", &num[j]);
        }

        checkbal(num, n);
   
        
        i++;
    }

    return 0;
}


void checkbal (int vetor[], int N) {
    int h[N], rechts, links, k, flag = 1;

    for (k = 0; k < N; k++)
        h[k] = 0;
    
    for (k = N - 1; k >= 0; k--) {
        links = (2 * k) + 1;
        rechts = (2 * k) + 2;
        if (vetor[k] != -1) {

            if (rechts < N) {

                if (h[links] >= h[rechts]) {

                    h[k] = h[links] + 1;

                } else {
                    h[k] = h[rechts] + 1;
                }

                if (h[rechts] - h[links] > 1 || h[rechts] - h[links] < -1) {
                    flag = 0;
                    break;
                }

            } else if (links < N) {

                h[k] = h[links] + 1;

            } else {
                h[k] = 1;
            }
                    
        }
    }

    if (flag == 1) {
        printf("T\n");
    } else {
        printf("F\n");
    }
    

}