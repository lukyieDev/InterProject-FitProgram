#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

	bool validarInputFloat(const char *input){
		int i = 0;

		// Verificar se o primeiro caractere é um sinal de menos (opcional para números negativos)
		if (input[i] == '-')
			i++;

		// Verificar se os caracteres seguintes são dígitos ou ponto decimal
		while (input[i] != '\0'){
			if ((input[i] < '0' || input[i] > '9') && input[i] != '.'){
				return false; // Caractere inválido encontrado
			}
			i++;
		}

		return true; // A entrada é um número float válido
	}

int main(){
	float peso, altura, imc, pesoIdeal;
	int idade;
	char nome[20], genero[2], genString[20], input[100], objetivo[2], objString[20], atividadeFisica[2], atvString[50];

	printf("Digite o seu nome:\n\n");
	scanf("%[^\n]%*c", &nome);

	printf("Digite a sua idade:\n\n");
	scanf("%s", &input);

	while (!validarInputFloat(input)){
		printf("Idade invalida, digite uma idade valida:\n\n");
		scanf("%s", &input);
	}

	idade = strtof(input, NULL);

	printf("Agora vamos precisar saber o seu peso e altura para determinar o seu IMC.\n\n");
	printf("Informe seu peso Kg: \nEx: 70.5Kg\n\n");
	scanf("%s", &input);

	while (!validarInputFloat(input)){
		printf("Peso invalida, digite uma peso valida:\n\n");
		scanf("%s", &input);
	}

	peso = strtof(input, NULL);
	printf("Informe sua altura:\n Ex: 1.70m\n\n");
	scanf("%s", &input);

	while (!validarInputFloat(input)){
		printf("Altura invalida, digite uma altura valida:\n\n");
		scanf("%s", &input);
	}

	altura = strtof(input, NULL);
	imc = peso / (altura * altura);

	if (imc <= 18.5){
		printf("Abaixo do peso!\n\n");
		printf("1-Alimente-se com mais frequencia\n");
		printf("2-consumir mais calorias do que gasta\n");
		printf("3-adicione calorias extras e saudaves em seu prato\n");
		printf("4-faca exercicios fisicos para o desenvolvimento muscular\n");
	}else if (imc >= 18.6 && imc < 24.9){
		printf("Peso normal!\n\n");
	}else if (imc >= 25 && imc < 29.9){
		printf("sobrepeso!\n\n");
		printf("1- crie uma rotina alimentar saudavel\n");
		printf("2- se alimente sempre, mas em pequena porcao\n");
		printf("3- hidrate-se\n");
	}else if (imc >= 30 && imc < 34.9){
		printf("obesidade grau 1!\n\n");
		printf("sobrepeso!\n\n");
		printf("1- crie uma rotina alimentar saudavel\n");
		printf("2- se alimente sempre, mas em pequena porcao\n");
		printf("3- hidrate-se\n");
	}else if (imc >= 35 && imc <= 39.9){
		printf("obesidade grau 2!\n\n");
		printf("sobrepeso!\n\n");
		printf("1-crie uma rotina alimentar saudavel\n");
		printf("2-se alimente sempre, mas em pequena porcao\n");
		printf("3-hidrate-se\n");
	}else{
		printf("Obesidade Grau 3!\n\n");
		printf("sobrepeso!\n\n");
		printf("1- crie uma rotina alimentar saudavel\n");
		printf("2- se alimente sempre, mas em pequena porcao\n");
		printf("3- hidrate-se\n");
	}

	printf("Seu imc e:%.1f\n\n", imc);

	do{

		printf("Escolha o seu genero:\n\n");
		printf("Digite 1 para Masculino;\n");
		printf("Digite 2 para Feminino;\n");
	    scanf("%s", &genero);
		
		if (strcmp(genero, "1") == 0){
			printf("Masculino\n\n");
			strcpy(genString, "Masculino");
		
			pesoIdeal = (72.7*altura) - 58;
			printf("Seu peso ideal e:%.1fKg\n\n",pesoIdeal);
		}else if (strcmp(genero, "2") == 0){
			printf("Feminino\n\n");
			strcpy(genString, "Feminino");	
			pesoIdeal = (62.1*altura) - 44.7;
			printf("Seu peso ideal e:%.1f\n\n",pesoIdeal);
		}else{
			printf("Voce nao digitou uma opcao valida!\n");
		}
	} while ((strcmp(genero, "1") != 0) && (strcmp(genero, "2") != 0));		

    do{
    	printf("Escolha seu objetivo em nossa academia:\n\n");
    	printf("Digite 1 para hipertrofia\n");
    	printf("Digite 2 para emagrecimento\n");
    	printf("Digite 3 para bem estar e saude\n");
    	scanf("%s", &objetivo);
		
        if (strcmp(objetivo, "1") ==0){
	    	printf("hipertrofia\n\n");
		    strcpy(objString, "hipertrofia");
	    }else if(strcmp(objetivo, "2") == 0){
		    printf("emagrecimento\n\n");
	    	strcpy(objString, "emagrecimento");
    	}else if(strcmp(objetivo, "3") ==0 ){ 
       	 	printf("bem estar e saude\n\n");
        	strcpy(objString, "bem estar e saude");
	    }else{
    		("voce nao digitou uma opcao valida!\n");
    	}
    } while ((strcmp(objetivo, "1") != 0) && (strcmp(objetivo, "2") != 0) && (strcmp(objetivo, "3") != 0));

   do{
	   printf("Escolha seu nivel de atividade fisica:\n\n");
	   printf("Digite 1 se voce nao pratica nenhuma atividade fisica\n");
   	   printf("Digite 2 se voce pratica atividades fisicas de 1 a 2 vezes na semana\n");
	   printf("Digite 3 se voce pratica atividades fisicas 4 vezes ou mais na semana\n");
	   scanf("%s", &atividadeFisica);
	
      if (strcmp(atividadeFisica, "1") == 0){
   	   	 	printf("nenhuma atividade fisica\n\n");
	    	strcpy(atvString, "nenhuma atividade fisica");
      }else if(strcmp(atividadeFisica, "2") == 0){ 
        	printf("atividade fisica 1 a 2 vezes na semana\n\n");
        	strcpy(atvString, "atividade fisica 1 a 2 vezes na semana");
	  }else if(strcmp(atividadeFisica, "3") == 0){
        	printf("atividade fisica 4 vezes ou mais na semana\n\n");
        	strcpy(atvString, "atividade fisica 4 vezes ou mais na semana");
	  }
   } while ((strcmp(atividadeFisica, "1") != 0) && (strcmp(atividadeFisica, "2") != 0) && (strcmp(atividadeFisica, "3") != 0));

    printf("Aqui estao informados:\n\n");
   	printf("Nome: %s\n", nome);
	printf("Idade: %d anos\n", idade);
	printf("Genero escolhido: %s\n", genString);
	printf("Peso: %.1f Kg\n", peso);
	printf("Altura: %.2f m\n", altura);
	printf("Seu peso ideal e: %.1fKg\n", pesoIdeal);
	printf("Objetivo escolhido: %s\n", objString);
	printf("Nivel de atividade fisica escolhida: %s\n",atvString);
	printf("Seu imc deu:%.1f\n", imc);
	system("pause");
	return 0;
}