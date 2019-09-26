/****************
Aluno(a): Exodo Jaffar
Aluno(a): Joao Augusto
Turma: 228 - B
Data: 12/09/19
*/

#include <stdio.h>
#include <stdlib.h>
/*
if(Ferrou == 1){
	printf("\nFerrou\n");
}
*/

int comparaPalavras(char palavra[], char palavra2[]){
	int tamanho = contaLetras(palavra), i, acertos=0;
	for(i = 0; i<tamanho; i++){
		if(palavra[i] == palavra2[i]){
			acertos++;
		}
	}
	if(acertos == tamanho){
		return 1;
	}else{
		return 0;
	}
}

void inicilizaVetor(char vetor[], int tamanhoVetor, char preenchimento) {
	int i;
	for(i = 0; i<20; i++){
		if(i<tamanhoVetor){
			vetor[i] = preenchimento; 
		}else{
			vetor[i] = '\0';
		}
	}
}

void letraErrada(char vetorErrado[], int posicao, char letra){
	vetorErrado[posicao] = letra;
}

void desenhaBoneco(int vida){
if(vida==0){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|         \n");
printf("|         \n");
printf("|__       \n");
}
if(vida==1){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|        o    \n");
printf("|             \n");
printf("|__           \n");
}
if(vida==2){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|        O    \n");
printf("|        |    \n");
printf("|__           \n");
}
if(vida==3){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|        O   \n");
printf("|       /|  \n");
printf("|__          \n");
}
if(vida==4){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|        O   \n");
printf("|       /|\\  \n");
printf("|__         \n");
}
if(vida==5){
printf(" ________\n");
printf("|        |\n");
printf("|        |\n");
printf("|        O   \n");
printf("|       /|\\  \n");
printf("|__     /    \n");
}

int contaLetras(char vetor[]){
	int cont, i;
	i = cont = 0;
	while(vetor[i]!= '\0') {
		cont++;
		i++;
	}
	
	return cont;
}


void substuiLetras(char vetor[], char palavra[], char letra){
	int i = 0;
	while(palavra[i] != '\0'){
		if(palavra[i] == letra){
			vetor[i] = letra;
		}
		i++;
	}
}


int jogada(char palavra[], char letra){
	int i;
	
	for(i =0; palavra[i] != '\0'; i++){
		
		if(letra == palavra[i]){
			return 1;
		}	
		
	}
	
	return 0;
}

void exibirVetor(char vetor[], int tamanho){
	//char letra;	system("cls");
	for (int i = 0; i < tamanho; ++i){
		printf("%c", vetor[i]);
	}
	printf("\n");
}



int main(){
	
	int terminado = 0, qletras, erros = 0, i, Ntentativa = 0, finalAcerto = 0;
	
	char letraErradas[20], letra[20], palavra[20], dica[20], riscos[20];
	
	// Le palavra
	printf("Jogador 1 \nDigite uma palavra:");
	scanf("\n%s", &palavra);
	
	// Le dica
	printf("\nDigite a dica:");
	scanf("\n%s", &dica);
	
	// Atrubui a qletras
	qletras = contaLetras(palavra);

	// Inicializa os vetores
	inicilizaVetor(riscos, qletras, '-') ;
	inicilizaVetor(letraErradas, 20, '\0');
	// Inicio o jogo
	while(erros<5){
	
		terminado = 0;

		system("cls");

		printf("Letras que foram erradas : ");
		exibirVetor(letraErradas, erros+1);

		printf("A palavra tem %d letras\n", qletras);

		printf("Dica : ");
		exibirVetor(dica, contaLetras(dica));
		
		/*
			LOCAL PARA O BONECO
		*/
		
		exibirVetor(riscos, qletras);

		printf("Digita uma letra:\n");

		// Le a letra
		scanf("\n%s", &letra);
		if(contaLetras(letra) == 1){
		
			if (jogada(palavra, letra[0]) != 1){
				erros++;
				letraErrada(letraErradas, erros, letra[0]);
			}
			
			substuiLetras(riscos, palavra, letra[0]);
		}
		else{
			finalAcerto = comparaPalavras(palavra, letra);
			break;
		
		}
	
		for(i =0; i<qletras;i++){
			if (riscos[i] == '-'){
				terminado++;
			}		
		}
			
		if(terminado == 0){
			break;
		}

		Ntentativa++;
	}

	system("cls");
	if(finalAcerto == 1){
		printf("Voce venceu o jogo!!\n A palavra era: %s", palavra);
	}else if(terminado == 0){
		printf("Voce venceu o jogo em %d jogadas\n A palavra era: %s", Ntentativa, palavra);
		
	}else{
		printf("Voce perdeu o jogo :(\nA palavra era: %s", palavra);
	}
	
	scanf("%c");
	return 0;
}
	
	
	
	

//	while(QErros <6){	
		
//
	

