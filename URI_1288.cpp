#include <iostream>

using namespace std;

/* Programação dinamica - problema da mochila. */

int maximo(int a, int b){
    if(a > b)
        return a;
    return b;
}

bool calculaAtaque(int N, int K, int R, int vetX[], int vetY[]){
    int mat[N + 1][K + 1];
    for(int i = 0; i < N; i++)      // inicializa 1ª linha com zero.
        mat[0][i] = 0;

    for(int j = 0; j < N; j++)      // inicializa 1ª coluna com zero.
        mat[j][0] = 0;

    for(int i = 1; i <= K; i++){
        for(int j = 0; j < N; j++){
            if(j > 0){
                mat[j][i] = mat[j-1][i];
                if (vetY[j] <= i)           // formula recursiva para os subproblemas.
                    mat[j][i] = maximo(mat[j][i], mat[j-1][i - vetY[j]] + vetX[j]);
            }
            else{
                mat[j][i] = 0;
                if(vetY[j] <= i)
                    mat[j][i] = maximo(mat[j][i], vetX[j]);
            }
        }
    }

    if(mat[N-1][K] >= R)
        return true;
    return false;
}

int main(){
    // N - numero de projeteis disponivies.
    // X - poder de destruicao do projetil, Y - peso do projetil.
    // K - capacidade de carga do canhão.
    // R - resistencia total do castelo.
    int casoTeste, N;
    int K, R;

    cin >> casoTeste;
    for(int i = 0; i < casoTeste; i++){
        cin >> N;

        int vetX[N + 1];
        int vetY[N + 1];

        // ler valores sobre projetil.
        for(int j = 0; j < N; j++)
            cin >> vetX[j] >> vetY[j];

        cin >> K;
        cin >> R;

        bool result = calculaAtaque(N, K, R, vetX, vetY);

        if(result)
            cout << "Missao completada com sucesso" << endl;
        else
            cout << "Falha na missao" << endl;
    }

    return 0;
}
