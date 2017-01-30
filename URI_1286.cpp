#include <iostream>

using namespace std;

/* programação dinamica - problema da mochila */

int calculaLista(int N, int P, int tempo[], int qtd[]){
    int mat[N + 1][P + 1];

    for(int i = 0; i <= P; i++)     // inicializa 1ª linha com 0.
        mat[0][i] = 0;
    for(int j = 1; j <= N; j++)     // inicializa 1ª coluna com 0.
        mat[j][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= P; j++){

            if(qtd[i - 1] <= j){
                if((tempo[i - 1] + mat[i - 1][j - qtd[i - 1]]) > mat[i - 1][j])
                    mat[i][j] = tempo[i - 1] + mat[i - 1][j - qtd[i - 1]];
                else
                    mat[i][j] = mat[i - 1][j];
            }
            else
                mat[i][j] = mat[i - 1][j];
        }
    }
    // retorna o valor máximo.
    return mat[N][P];
}

int main(){
    // N - numero de pedidos, P - número maximo de pizzas que podem ser entregues.
    // tempo - tempo total para entrega do pedido, qtd - qtd de itens do pedido.
    int N, P;

    while(true){
        cin >> N;

        if(N == 0)  // condição de parada.
            break;

        cin >> P;

        int tempo[N];
        int qtd[N];

        for(int i = 0; i < N; i++)      // prenche vet tempo e vet qtd.
            cin >> tempo[i] >> qtd[i];

        cout << calculaLista(N, P, tempo, qtd) << " min." << endl;
    }

    return 0;
}
