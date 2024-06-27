#include <iostream>
#include <string>   
#include <cstdlib>
using namespace std;

//Este programa é um jogo da forca
int main()
{
    int vidas = 6, tam = 0, saida = 0,tentativas=1;
    int repete1 = -1, repete2 = -1, repete3 = -1, repete4 = -1, letra_certa = -1;
    char palavra[100], segredo[100];
    char alfabeto[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }, mostra_alfa[26];
    char letra;
    bool confirma = false;
    do {

        cout << "digite uma palavra para a forca: ";
        cin >> palavra;

        cout << "\na palavra e " << palavra;
        tam = 0;
        for (int i = 0;palavra[i] != '\0';i++) {
            tam++;
        }
        cout << "\n\nesta certo?";
        cout << "\n1-sim 2-nao\n";
        cin >> saida;

        for (int i = 0;i < 100;i++) {
            if (i < tam) {
                segredo[i] = '-';
            }
            else {
                segredo[i] = '\0';
            }
        }
        for (int i = 0;i < 100;i++) {
            if (i < tam) {
                palavra[i] = palavra[i];
            }
            else {
                palavra[i] = '\0';
            }

        }

    } while (saida != 1);
    do {

        saida = 0;
        confirma = true;

        system("cls");
       
        if (tentativas!=1) {
            for (int i = 0;i < tam;i++) {
                if (letra_certa == i)
                    segredo[i] = letra;
                else if (repete1 == i)
                    segredo[i] = letra;
                else if (repete2 == i)
                    segredo[i] = letra;
                else if (repete3 == i)
                    segredo[i] = letra;
                else if (repete4 == i)
                    segredo[i] = letra;
            }
            cout << "a palavra e ";
            for (int i = 0;i < tam;i++) {
                cout << segredo[i];
            }
            cout << "\nletras ja utilizadas:";
            for (int i = 0;i < 26;i++) {  
                if (letra == alfabeto[i]) {
                    mostra_alfa[i] = letra;
                }
            }
            for (int i=0;i < 26;i++) {
                for(int j =0;j<26;j++)
                    if (mostra_alfa[j] == alfabeto[i]) {
                        cout << mostra_alfa[i]<<" ";
                    }
            }

        }
        cout << "\nvidas restantes " << vidas << "\n";

        if (strcmp(palavra, segredo) == 0) {
            cout << "\nvoce ganhou\n";
            vidas = -99;
        }
        
        else {
            cout << "\n a palavra tem " << tam << " letras";

            cout << "\ndigite uma letra ";
            cin >> letra;

            repete1 = -1, repete2 = -1, repete3 = -1, repete4 = -1, letra_certa = -1;
            for (int i = 0;i < tam;i++) {
                if (letra == palavra[i]) {
                    if (letra_certa == -1) {
                        letra_certa = i;
                        confirma = false;
                    }
                    else if (repete1 == -1) {
                        confirma = false;
                        repete1 = i;
                    }
                    else if (repete2 == -1) {
                        confirma = false;
                        repete2 = i;
                    }
                    else if (repete3 == -1) {
                        repete3 = i;
                        confirma = false;
                    }
                    else if (repete4 == -1) {
                        confirma = false;
                        repete4 = i;
                    }
                }
            }
                if (confirma) {
                    vidas--;
                    confirma =true;
                }
                tentativas++;
                if ((strcmp(palavra, segredo) == 1 && vidas==0)) {
                    cout << "\nVoce perdeu a palavra correta era: " << palavra;
                }
        }
    } while (vidas > 0);
    cout << "\n\n";
    system("pause");
}