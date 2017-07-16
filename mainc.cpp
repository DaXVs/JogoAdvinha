#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void modosorteio();
int main() {
	
	system("title Jogo - Advinha   By:: Daniel Xavier");
	int num, chances, chute, cont, escolha;
	char resp;

	inicio:
	system("cls");
    cout << "QUAL MODO VOCE DESEJA JOGAR?\n-MODO: SORTEADO PELO PC- [Digite 1]\n-MODO: ESCOLHIDO PELO USUARIO- [Digite 2]\n-SAIR [DIGITE 0]\n";
    cin >> escolha;
    switch (escolha) {
        case 1:
            modosorteio(); //chamando função do modo sorteio.
            goto finish; //quando a função terminar, ela irá pra essa linha, que logo irá para onde está o 'finish:' na linha 82.
        break;
        case 2:
            goto iniciojogo;
        break;
        case 0:
        	goto fecharjogo;
        break;
        default:
            cout << "\nO valor digitado nao corresponde a nenhuma das opcoes!\n\n";
            system("pause");
            system("cls");
            goto inicio;
    }

	iniciojogo:
    system("cls");
	cout << "\t\t\t\t-JOGO DE ADVINHACAO-" << endl;

	cout << "Quantas chances voce quer dar para que seu(a) amigo(a) descubra o numero digitado: ";
	cin >> chances;
	cout << "\nDigite um numero no qual voce queira que seu(a) amigo(a) descubra: ";
	cin >> num;
	system("cls");

	for(cont=0; cont<chances; cont++) {
		system("pause");
		system("cls");
		cout << "Voce tem " << (chances - cont) << " chances para acertar o numero que foi\n"
			<< "digitado pelo(a) seu(a) amigo(a)!\n" << endl;
		cout << "Digite o seu " << (cont + 1) << "o chute: ";
		cin >> chute;
		if(chute == num) {
			cout << "Parabens, voce acertou o numero!!\n" << endl;
			break;
		}
		else {
			if(chute > num) {
				cout << "Errado! Dica: Chute um numero menor! \n\n";
				if(chances - cont == 2){
                    if(num%2==0) {
                        cout << "DICA BONUS! O numero e PAR!\n\n";
                    }
                    else{
                        cout << "DICA BONUS! O numero e IMPAR!\n\n";
                    }
				}
			}
			else {
				cout << "Errado! Dica: Chute um numero maior! \n\n";
				if(chances - cont == 0){
                    if(num%2==0) {
                        cout << "DICA BONUS! O numero e PAR!\n\n";
                    }
                    else{
                        cout << "DICA BONUS! O numero e IMPAR!\n\n";
                    }
				}
			}
		}
	}

	cout << "\nNumero digitado pelo(a) seu(a) amigo(a): " << num << endl;

    finish: //quando a funçao modosorteio() terminar de ser chamada, virá para cá, por causa do 'goto finish;' digitado na linha 21.
    cout << "\nQuer jogar novamente? [S/N]: ";
	cin >> resp;
	if(resp == 'S' || resp =='s' )
		goto inicio;

    system("cls");
	cout << "\n\n\t\t\tOBRIGADO POR JOGAR!!";
	fecharjogo:
	cout << "\n\n\tFEITO POR: Daniel Xavier";
	cout << "\n\n\tSISTEMA UTILIZADO: Code::Blocks\n";
	cout << "\n\n\tCORRECOES FEITAS UTILIZANDO: DEV-C++\n\n";
	return 0;
}

void modosorteio() {
	int chancesmodo, nummodo, chutemodo, maiornum;
	system("cls");
	cout << "\t\t\t\t-JOGO DE ADVINHACAO-" << endl;
    srand(time(0)); //utiliza-se a biblioteca/classe 'ctime', pois pega números doo horário do sistema.
	cout << "Digite quantas chances voce quer ter para descobrir o numero sorteado: ";
	cin >> chancesmodo;
	cout << "Digite qual o maior numero que podera ser sorteado: ";
	cin >> maiornum;
	nummodo = 1+(rand()%maiornum); //utiliza-se a biblioteca/classe 'csdtlib', gerando assim números aleatórios.
	system("cls");

	for(int contmodo=0; contmodo<chancesmodo; contmodo++) {
		system("pause");
		system("cls");
		cout << "Voce tem " << (chancesmodo - contmodo) << " chances para acertar o numero que foi\n"
			<< "sorteado pelo PC.\n" << endl;
		cout << "Digite o seu " << (contmodo + 1) << "o chute: ";
		cin >> chutemodo;
		if(chutemodo == nummodo) {
			cout << "Parabens, voce acertou o numero!!\n" << endl;
			break;
		}
		else {
			if(chutemodo > nummodo) {
				cout << "Errado! Dica: Chute um numero menor! \n\n";
				if(chancesmodo - contmodo == 2){
                    if(nummodo%2==0) {
                        cout << "DICA BONUS! O numero e PAR!\n\n";
                    }
                    else{
                        cout << "DICA BONUS! O numero e IMPAR!\n\n";
                    }
				}
			}
			else {
				cout << "Errado! Dica: Chute um numero maior! \n\n";
				if(chancesmodo - contmodo == 2){
                    if(nummodo%2==0) {
                        cout << "DICA BONUS! O numero e PAR!\n\n";
                    }
                    else{
                        cout << "DICA BONUS! O numero e IMPAR!\n\n";
                    }
				}
			}
		}
	}

	cout << "\nNumero sorteado pelo PC: " << nummodo << endl;
}
