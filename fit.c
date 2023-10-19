#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

int main(){
setlocale(LC_ALL, "portuguese_Brazil");
	float peso, altura, imc, pesoIdeal, tmb, continuar;
	int idade, nomeVer = 0, i = 0;
	char nome[20], genero[2], genString[20], idadeVer[100], pesoVer[100], alturaVer[100], continuarVer[100], objetivo[2], objString[20], atividadeFisica[2], atvString[50];

do{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
	printf("");	printf("\t Bem Vindo a UBfit!"); printf("");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n________________________________________________________________________________________\n");
		printf("\nPor favor digite seu nome e sua idade!");	
		printf("\n\tDigite o seu nome: ");
		scanf("%[^\n]%*c", &nome);
	while(nome[i] != '\0' && nomeVer != 1){    
        if((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || isspace(nome[i])){
            i++;
			nomeVer = 0;
        }else{
            printf("Por favor digite somente letras.");
            printf("\n\tDigite o seu nome: ");
			scanf("%[^\n]%*c", &nome);

        }
    }
		printf("\tDigite a sua idade: ");
		scanf("%s", idadeVer);
		fflush(stdin);
		i = 0;
	// Verificar se o primeiro caractere e um sinal de menos (opcional para numeros negativos)
	if (idadeVer[i] == '-'){
			i++;
	}
	// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (idadeVer[i] != '\0'){
		while(idadeVer[i] < '0' || idadeVer[i] > '9'){
		printf("Idade invalida, digite uma idade valida: ");
		scanf("%s", idadeVer);
		}
		i++;
	}
	idade = strtof(idadeVer, NULL);
	printf("________________________________________________________________________________________\n");
	printf("\nPrecisamos saber o seu peso e altura para calcular o seu IMC.\n");
	printf("\tInforme seu peso Kg(Ex: 70,5Kg): ");
	scanf("%s", &pesoVer);
	fflush(stdin);
	i = 0;
	if (pesoVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (pesoVer[i] != '\0'){
		while ((pesoVer[i] < '0' || pesoVer[i] > '9') && pesoVer[i] != ','){
		printf("\nPeso invalido, digite um peso valido: ");
		scanf("%s", &pesoVer);
		}
		i++;
	}
		peso = strtof(pesoVer, NULL);
		printf("\tInforme sua altura(Ex: 1,70m): ");
		scanf("%s", &alturaVer);
		fflush(stdin);
		i = 0;
	if(alturaVer[i] == '-'){
			i++;
	}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (alturaVer[i] != '\0'){
		while ((alturaVer[i] < '0' || alturaVer[i] > '9') && alturaVer[i] != ','){
		printf("\nAltura invalido, digite uma altura valida:");
		scanf("%s", &alturaVer);
		}
		i++;
	}
	altura = strtof(alturaVer, NULL);
	do{
		printf("________________________________________________________________________________________\n\n");
		printf("Precisamos saber seu genero para calcular o seu peso ideal:");
		printf("\n\tDigite 1 para Masculino ou 2 para Feminino: ");
    	scanf("%s", &genero);
		if (strcmp(genero, "1") == 0){
			printf("\tGenero: Masculino.\n");
			strcpy(genString, "Masculino");
			pesoIdeal = (72.7*altura) - 58;
			printf("\tSeu peso ideal e: %.1fKg\n",pesoIdeal);
		}else if (strcmp(genero, "2") == 0){
			printf("Genero: Feminino\n");
			strcpy(genString, "Feminino");	
			pesoIdeal = (62.1*altura) - 44.7;
			printf("\tSeu peso ideal e:%.1f\n",pesoIdeal);
		}else{
			printf("Voce nao digitou uma opcao valida!\n");
		}
	}while((strcmp(genero, "1")!= 0)&&(strcmp(genero, "2")!= 0));
    do{
		printf("\n________________________________________________________________________________________\n");
    	printf("Escolha qual o seu objetivo em nossa academia:");
    	printf("\n\tDigite 1 para Hipertrofia");
    	printf("\n\tDigite 2 para Emagrecimento");
    	printf("\n\tDigite 3 para Bem estar e saude");
		printf("\n\tDigite aqui: ");
    	scanf("%s", &objetivo);
        if (strcmp(objetivo, "1") ==0){
	    	printf("\tHipertrofia\n");
		    strcpy(objString, "Hipertrofia");
	    }else if(strcmp(objetivo, "2") == 0){
		    printf("\tEmagrecimento\n");
	    	strcpy(objString, "Emagrecimento");
    	}else if(strcmp(objetivo, "3") ==0 ){ 
       	 	printf("\tBem estar e saude\n");
        	strcpy(objString, "Bem estar e saude");
	    }else{
    		("\nVoce nao digitou uma opcao valida!");
    	}
    } while ((strcmp(objetivo, "1") != 0) && (strcmp(objetivo, "2") != 0) && (strcmp(objetivo, "3") != 0));
   do{
	   printf("________________________________________________________________________________________\n\n");	
	   printf("Qual o seu nivel de atividade fisica:\n\n");
	   printf("Digite 1 não pratica nenhuma atividade fisica\n");
   	   printf("Digite 2 pratica atividades fisicas 1 a 2 vezes na semana\n");
	   printf("Digite 3 pratica atividades fisicas 4 vezes ou mais na semana\n");
	   printf("\tDigite aqui: ");
	   scanf("%s", &atividadeFisica);
	
      if (strcmp(atividadeFisica, "1") == 0){
   	   	 	printf("\tNenhuma atividade fisica\n\n");
	    	strcpy(atvString, "Nenhuma atividade fisica");
      }else if(strcmp(atividadeFisica, "2") == 0){ 
        	printf("Atividade fisica 1 a 2 vezes na semana\n\n");
        	strcpy(atvString, "Atividade fisica 1 a 2 vezes na semana");
	  }else if(strcmp(atividadeFisica, "3") == 0){
        	printf("atividade fisica 4 vezes ou mais na semana\n\n");
        	strcpy(atvString, "Atividades físicas 4 vezes ou mais na semana");
	}
   } while ((strcmp(atividadeFisica, "1") != 0) && (strcmp(atividadeFisica, "2") != 0) && (strcmp(atividadeFisica, "3") != 0));
		if(strcmp(genero, "1") == 0 && idade<29){
	tmb = 15.057 * peso + 692.2; //Calculo do tmb para homem jovem
    }if(strcmp(genero, "1") == 0 && idade>30 && idade<59){
	tmb = 11.472 * peso + 873.1;//Calculo do tmb para homem adulto
	}if(strcmp(genero, "1") == 0 && idade>=60){
	tmb = 11.711 * peso + 587;//Calculo do tmb para homem idoso
	}if(strcmp(genero, "2") == 0 && idade<29){
	tmb = 14.818 * peso + 486.6;//Calculo do tmb para mulher jovem
	}if(strcmp(genero, "2") == 0 && idade>30 && idade<59){
	tmb = 8.126 * peso + 845.6;//Calculo do tmb para adulto mulher
	}if(strcmp(genero, "2") == 0 && idade>=60){
	tmb = 9.082 * peso + 658.5;//Calculo do tmb para mulher idos
	}
	printf("\nSua Taxa Metabolica Basal(TMB) e: %.2f calorias por dia!\n", tmb);
	imc = peso / (altura * altura);
	printf("Seu IMC e: %.1f\n\n", imc);
	if (imc <= 18.5){
		printf("Voce esta abaixo do peso!\n\n");
	}else if (imc >= 18.6 && imc < 24.9){
		printf("Seu peso esta normal!\n\n");
	}else if (imc >= 25 && imc < 29.9){
		printf("Voce esta com Sobrepeso!\n\n");
	}else if (imc >= 30 && imc < 34.9){
		printf("Voce esta com Obesidade grau 1!\n\n");
	}else if (imc >= 35 && imc <= 39.9){
		printf("Voce esta com Obesidade grau 2!\n\n");
	}else{
		printf("Voce esta com Obesidade Grau 3!\n\n");
	}
	if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Hidrate-se\n");
		printf("3-Alimente-se com frequencia\n");
		printf("4-Consumir mais calorias do que gasta\n");
		printf("5-Adicione calorias extras e saudaveis em seu prato\n");
		printf("6-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Alimente-se com frequencia\n");
		printf("2-Hidrate-se\n");
		printf("3-Consumir mais calorias do que gasta\n");
		printf("4-Adicione calorias extras e saudaveis em seu prato\n");
		printf("5Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1-Se exercite mais\n");
		printf("2-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("4-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("1- Crie uma rotina alimentar saudavel\n");
		printf("3- Se alimente sempre, mas em pequena porcao\n");
		printf("3- Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1- Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porcao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("Procure um profissional nutricionista!\n");
		printf("1-Crie uma rotina alimentar saudavel\n");
		printf("3-Se alimente sempre, mas em pequena porçao\n");
		printf("3-Hidrate-se\n");
	}
	printf("________________________________________________________________________________________\n\n");
    printf("Aqui estao informacoes:\n");
   	printf("\tNome: %s\n", nome);
	printf("\tIdade: %d anos\n", idade);
	printf("\tGenero escolhido: %s\n", genString);
	printf("\tPeso: %.2fKg\n", peso);
	printf("\tAltura: %.2f\n", altura);
	printf("\tSeu peso ideal e: %.2fKg\n", pesoIdeal);
	printf("\tObjetivo escolhido: %s\n", objString);
	printf("Nivel de atividade fisica escolhida: %s\n",atvString);
	printf("\tSeu IMC deu:%.2f\n", imc);
	printf("\tSeu TMB deu:%.2f\n", tmb);	
    printf("________________________________________________________________________________________\n\n");
	printf("\nEscolha '1' para sair do programa ou '2' para repetir todo o processo\n");
    scanf(" %s", &continuarVer);
    fflush(stdin);
    i = 0;
    if (continuarVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (continuarVer[i] != '\0'){
		while ((continuarVer[i] < '0' || continuarVer[i] > '9') && continuarVer[i] != '.'){
		printf("Opcao invalida, digite uma opçao valida:\n\n");
		scanf("%s", &continuarVer);
		fflush(stdin);
		}
		i++;
	}
	continuar = strtof(continuarVer, NULL);
}while(continuar == 2);
	system("cls");
	system("pause");
	return 0;
}