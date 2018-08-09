#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Variaveis globais
char tela[100000] = "";
char dica[100] = "";
char palavra[50] = "";
char espaco[50] = "";
char ltrsErradas[24] = "testes";
char acertos[150] = "";
char msg[40];
int erros = 0;

// funcao que sera utilizado para sortear as palavras de arquivo txt
void sortearPalavra() {

	strcpy_s(palavra, 50, "carro");
	strcpy_s(dica, 100, "locomocao sobre rodas muito utilizada");
}


// procedimento para zerar variaveis para um novo jogo
int newGame() {
	sortearPalavra();
	erros = 0;
	sprintf_s(msg, 40, "%s", "  ");
	memset(ltrsErradas, '\0', strlen(ltrsErradas));
	memset(acertos, '\0', strlen(acertos));
	memset(espaco, '_', strlen(palavra));
	return 0;
}


// procedimento para preencher os espaços da palavra invisivel
int completaEspacos() {
	for (int c = 0; c < 150; c++){
		if (acertos[c] != '-' && acertos[c] != '#') {
			for (int i = 0; i < sizeof(palavra) - 2; i++) {
				if ((acertos[c] == palavra[i]) && (espaco[i] == '_'))
				{
					espaco[i] = palavra[i];
				}
			}
		}
	}
	return 0;
}


// funcao para verificar quantos espaços livres faltam
int verfEspacos() {
	int ocorencias = 0;
	for (int c = 0; c < strlen(espaco); c++) {
		if (espaco[c] == '_') ocorencias++;
	}
	return ocorencias;
}

// funcao para revelar a palavra final
int revelarPalavra() {
	for (int c = 0; c < strlen(palavra); c++) {
		espaco[c] = palavra[c];
	}

	return 0;
}

// funcao para desenhar a forca na tela de acordo com o numero de erros;
int desenharTela(int erros) {
	// zera a variavel char[] tela
	strcpy_s(tela, 100000, "");

	// preenche a variavel char[] tela desenhando o homem da forca e adicionando as informações de maneira tabulada.
	switch (erros)
	{
		case 0:
			strcat_s(tela, 100000, "\t\t\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n\t\t\tPalavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n");
			strcat_s(tela, 100000, msg);
			break;
		case 1:
			strcat_s(tela, 100000, "         **\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n        ****\n");
			strcat_s(tela, 100000, "         **\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n");
			strcat_s(tela, 100000, msg);
			break;
		case 2:
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "        ****\n");
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "      ********\n");
			strcat_s(tela, 100000, "      ********\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n      ********\n");
			strcat_s(tela, 100000, "      ********\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n");
			strcat_s(tela, 100000, "      ********\t");
			strcat_s(tela, 100000, msg);
			break;
		case 3:
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "        ****\n");
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "    **********\n");
			strcat_s(tela, 100000, "   ***********\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n  *** ********\n");
			strcat_s(tela, 100000, " ***  ********\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n***   ********\t");
			strcat_s(tela, 100000, msg);
			break;
		case 4:
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "        ****\n");
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "    ************\n");
			strcat_s(tela, 100000, "   **************\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n  *** ******** ***\n");
			strcat_s(tela, 100000, " ***  ********  ***\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n***   ********   ***\t");
			strcat_s(tela, 100000, msg);
			break;
		case 5:
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "        ****\n");
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "    ************\n");
			strcat_s(tela, 100000, "   **************\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n  *** ******** ***\n");
			strcat_s(tela, 100000, " ***  ********  ***\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n***   ********   ***\t");
			strcat_s(tela, 100000, msg);
			strcat_s(tela, 100000, "      ***\n");
			strcat_s(tela, 100000, "      ***\n");
			strcat_s(tela, 100000, "      ***\n");
			strcat_s(tela, 100000, "      ***\n");
			strcat_s(tela, 100000, "      ***\n");
			break;
		case 6:
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "        ****\n");
			strcat_s(tela, 100000, "         **\n");
			strcat_s(tela, 100000, "    ************\n");
			strcat_s(tela, 100000, "   **************\t");
			strcat_s(tela, 100000, "Tentativas: ");
			strcat_s(tela, 100000, ltrsErradas);
			strcat_s(tela, 100000, "\n  *** ******** ***\n");
			strcat_s(tela, 100000, " ***  ********  ***\t");
			strcat_s(tela, 100000, "Palavra: ");
			strcat_s(tela, 100000, espaco);
			strcat_s(tela, 100000, "\n***   ********   ***\t");
			strcat_s(tela, 100000, msg);
			strcat_s(tela, 100000, "      ***  ***\n");
			strcat_s(tela, 100000, "      ***  ***\n");
			strcat_s(tela, 100000, "      ***  ***\n");
			strcat_s(tela, 100000, "      ***  ***\n");
			strcat_s(tela, 100000, "      ***  ***\n");
			break;
		default:
			break;
	}
	// printa a variavel char[] tela;
	printf("%s", tela);
	return 0;
}


// verifica se a letra existe na palavra;
int verificaLetra(char letra) {
	for (int c = 0; c < sizeof(palavra); c++) {
		if (palavra[c] == letra) {
			return 1;
		}
	}
	return 0;
}

// verifica se a letra ja existe na lista de acertos ou erros;
int verfLetraNova(char letra) {
	int result = 1;
	for (int c = 0; c < strlen(acertos); c++) {
		if (acertos[c] == letra) result = 0;
	}
	for (int i = 0; i < strlen(ltrsErradas); i++) {
		if (ltrsErradas[i] == letra) result = 0;
	}
	if (result == 0) {
		printf("\nA letra %c ja foi digitada!\n", letra);
		fflush(stdout);
	}
	return result;
}

// conta o numero de ocorrencias de uma letraa
int contaLetra(char letra) {
	int qtd = 0;
	for (int c = 0; c < sizeof(palavra); c++) {
		if (palavra[c] == letra) {
			qtd++;
		}
	}
	return qtd;
}

// preenche a lsita de letras corretas ou incorretas
int preenche(int cod, char letra) {
	if (cod == 1) {
		acertos[strlen(acertos)] = 45;
		acertos[strlen(acertos)] = letra;
		acertos[strlen(acertos)] = 45;
	}
	else if (cod == 2) {
		ltrsErradas[strlen(ltrsErradas)] = 45;
		ltrsErradas[strlen(ltrsErradas)] = letra;
		ltrsErradas[strlen(ltrsErradas)] = 45;
	}

	return 0;
}


// funcao principal, repsonsavel pela iteracao com usuario e verificacao logica do jogo;
int main() {
	newGame();
	int continua = 1;
	do {
		system("cls");
		char letra = "";
		if (verfEspacos() <= 0) {
			printf("PARABENS, VOCE ACERTOU!!\n\n");
			revelarPalavra();
			printf("A dica era: %s\n", dica);
			desenharTela(erros);
			erros = 10;
		}
		if (erros == 5) {
			printf("DICA: %s\n", dica);
		}
		if (erros == 6) {
			printf("VOCE PERDEU!!\n\n");
			revelarPalavra();
			desenharTela(erros);
		}
		if (erros < 6) {
			desenharTela(erros);
			do{
				printf("\n\n\nDigite uma letra: ");
				letra = getchar();
				letra = tolower(letra);
				getchar();
			} while (verfLetraNova(letra) != 1);
			if (verificaLetra(letra) == 1) {
				int qtd = contaLetra(letra);
				sprintf_s(msg, 40, "\tA palavra tem %d letras '%c'\n", qtd, letra);
 				preenche(1, letra);
			}
			else {
				sprintf_s(msg, 40, "\tA letra '%c' nao existe na palavra\n", letra);
				preenche(2, letra);
				erros++;
			}
			completaEspacos();
		}
		else{
			printf("Digite 1 para continuar e 0 para sair:\n");
			scanf_s("%d", &continua);
			getchar();
			if (continua == 1) {
				newGame();
			}
		}
	}while (continua == 1);
	return 0;
}