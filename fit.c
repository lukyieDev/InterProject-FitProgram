#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "portuguese");
	float peso, altura, imc, pesoIdeal, tmb, continuar;
	int idade, i = 0;
	char nome[20], genero[2], genString[20], idadeVer[100], pesoVer[100], alturaVer[100], continuarVer[100], objetivo[2], objString[20], atividadeFisica[2], atvString[50];

do{
	system("cls");
	printf("Digite o seu nome:\n");
	scanf("%[^\n]%*c", &nome);
	printf("\nDigite a sua idade:\n");
	scanf("%s", &idadeVer);
	fflush(stdin);
// Verificar se o primeiro caractere é um sinal de menos (opcional para números negativos)
	if (idadeVer[i] == '-'){
			i++;
	}
	// Verificar se os caracteres seguintes são dígitos ou ponto decimal
	while (idadeVer[i] != '\0'){
		while ((idadeVer[i] < '0' || idadeVer[i] > '9') && idadeVer[i] != ','){
		printf("\nIdade inválida, digite uma idade válida:\n");
		scanf("%s", &idadeVer);
		}
		i++;
	}
	idade = strtof(idadeVer, NULL);

	printf("\nAgora vamos precisar saber o seu peso e altura para determinar o seu IMC.\n\n");
	printf("\nInforme seu peso Kg: \nEx: 70,5Kg\n");
	scanf("%s", &pesoVer);
	fflush(stdin);
	i = 0;
	if (pesoVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes são dígitos ou ponto decimal
	while (pesoVer[i] != '\0'){
		while ((pesoVer[i] < '0' || pesoVer[i] > '9') && pesoVer[i] != ','){
		printf("\nPeso inválido, digite um peso válido:\n");
		scanf("%s", &pesoVer);
		}
		i++;
	}
	peso = strtof(pesoVer, NULL);
	
	printf("\nInforme sua altura:\n Ex: 1,70m\n");
	scanf("%s", &alturaVer);
	fflush(stdin);
	i = 0;
	if (alturaVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes são dígitos ou ponto decimal
	while (alturaVer[i] != '\0'){
		while ((alturaVer[i] < '0' || alturaVer[i] > '9') && alturaVer[i] != ','){
		printf("\nAltura inválido, digite uma altura válida:\n");
		scanf("%s", &alturaVer);
		}
		i++;
	}
	altura = strtof(alturaVer, NULL);

	do{

		printf("Escolha o seu gênero:\n\n");
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
			printf("Você não digitou uma opção válida!\n");
		}
	} while ((strcmp(genero, "1") != 0) && (strcmp(genero, "2") != 0));		

    do{

    	printf("Escolha seu objetivo em nossa academia:\n\n");
    	printf("Digite 1 para Hipertrofia\n");
    	printf("Digite 2 para Emagrecimento\n");
    	printf("Digite 3 para Bem estar e saúde\n");
    	scanf("%s", &objetivo);
		
        if (strcmp(objetivo, "1") ==0){
	    	printf("Hipertrofia\n\n");
		    strcpy(objString, "hipertrofia");
	    }else if(strcmp(objetivo, "2") == 0){
		    printf("Emagrecimento\n\n");
	    	strcpy(objString, "emagrecimento");
    	}else if(strcmp(objetivo, "3") ==0 ){ 
       	 	printf("Bem estar e saúde\n\n");
        	strcpy(objString, "bem estar e saude");
	    }else{
    		("Você não digitou uma opção válida!\n");
    	}
    } while ((strcmp(objetivo, "1") != 0) && (strcmp(objetivo, "2") != 0) && (strcmp(objetivo, "3") != 0));

   do{
	   printf("Escolha seu nível de atividade física:\n\n");
	   printf("Digite 1 se você não pratica nenhuma atividade física\n");
   	   printf("Digite 2 se você pratica atividades físicas de 1 a 2 vezes na semana\n");
	   printf("Digite 3 se você pratica atividades físicas 4 vezes ou mais na semana\n");
	   scanf("%s", &atividadeFisica);
	
      if (strcmp(atividadeFisica, "1") == 0){
   	   	 	printf("Nenhuma atividade fisica\n\n");
	    	strcpy(atvString, "nenhuma atividade fisica");
      }else if(strcmp(atividadeFisica, "2") == 0){ 
        	printf("Atividade física 1 a 2 vezes na semana\n\n");
        	strcpy(atvString, "Atividade física 1 a 2 vezes na semana");
	  }else if(strcmp(atividadeFisica, "3") == 0){
        	printf("atividade fÍsica 4 vezes ou mais na semana\n\n");
        	strcpy(atvString, "atividade fisica 4 vezes ou mais na semana");
	  }
   } while ((strcmp(atividadeFisica, "1") != 0) && (strcmp(atividadeFisica, "2") != 0) && (strcmp(atividadeFisica, "3") != 0));

		if(strcmp(genero, "1") == 1 && idade<29){
	tmb = 15.057 * peso + 692.2; //Calculo do tmb para homem jovem
    }if(strcmp(genero, "1") == 1 && idade>30 && idade<59){
	tmb = 11.472 * peso + 873.1;//Calculo do tmb para homem adulto
	}if(strcmp(genero, "1") == 1 && idade>=60){
	tmb = 11.711 * peso + 587;//Calculo do tmb para homem idoso
	}if(strcmp(genero, "2") == 2 && idade<29){
	tmb = 14.818 * peso + 486.6;//Calculo do tmb para mulher jovem
	}if(strcmp(genero, "2") == 2 && idade>30 && idade<59){
	tmb = 8.126 * peso + 845.6;//Calculo do tmb para adulto mulher
	}if(strcmp(genero, "2") == 2 && idade>=60){
	tmb = 9.082 * peso + 658.5;//Calculo do tmb para mulher idos
	}
	printf("\nSua Taxa Metabólica Basal(TMB) é: %.2f calorias por dia!\n", tmb);
	
	imc = peso / (altura * altura);
	printf("Seu IMC é: %.1f\n\n", imc);
	if (imc <= 18.5){
		printf("Abaixo do peso!\n\n");
		printf("1-Alimente-se com mais frequência\n");
		printf("2-Consumir mais calorias do que gasta\n");
		printf("3-Adicione calorias extras e saudáveis em seu prato\n");
		printf("4-Faça exercícios físicos para o desenvolvimento muscular\n");
	}else if (imc >= 18.6 && imc < 24.9){
		printf("Peso normal!\n\n");
	}else if (imc >= 25 && imc < 29.9){
		printf("Sobrepeso!\n\n");
		printf("1- Crie uma rotina alimentar saudável\n");
		printf("2- Se alimente sempre, mas em pequena porção\n");
		printf("3- Hidrate-se\n");
	}else if (imc >= 30 && imc < 34.9){
		printf("Obesidade grau 1!\n");
		printf("Procure um profissional nutricionista!\n");
		printf("Sobrepeso!\n\n");
		printf("1- Crie uma rotina alimentar saudavel\n");
		printf("2- Se alimente sempre, mas em pequena porcao\n");
		printf("3- Hidrate-se\n");
	}else if (imc >= 35 && imc <= 39.9){
		printf("Obesidade grau 2!\n\n");
		printf("Procure um profissional nutricionista!\n");
		printf("Sobrepeso!\n\n");
		printf("1-Crie uma rotina alimentar saudável\n");
		printf("2-Se alimente sempre, mas em pequena porção\n");
		printf("3-Hidrate-se\n");
	}else{
		printf("Obesidade Grau 3!\n");
		printf("Procure um profissional nutricionista!\n");
		printf("Sobrepeso!\n\n");
		printf("1- Crie uma rotina alimentar saudavel\n");
		printf("2- Se alimente sempre, mas em pequena porção\n");
		printf("3- Hidrate-se\n");
	}
	
    printf("Aqui estão informadas:\n\n");
   	printf("Nome: %s\n", nome);
	printf("Idade: %d anos\n", idade);
	printf("Gênero escolhido: %s\n", genString);
	printf("Peso: %.2fKg\n", peso);
	printf("Altura: %.2fM\n", altura);
	printf("Seu peso ideal e: %.2fKg\n", pesoIdeal);
	printf("Objetivo escolhido: %s\n", objString);
	printf("Nível de atividade física escolhida: %s\n",atvString);
	printf("Seu IMC deu:%.2f\n", imc);
	printf("Seu TMB deu:%.2f\n", tmb);
	
	if(imc < 24.9 && idade<29 && strcmp(objetivo, "1") ==1 && strcmp(atividadeFisica, "1") == 1){
		
	}else if(imc < 24.9 && idade>=30 && idade<=59 && strcmp(objetivo, "1") ==0 && strcmp(atividadeFisica, "1") == 0) 
	
	printf("\nEscolha '1' para sair do programa ou '2' para repetir todo o processo\n");
    scanf(" %s", &continuarVer);
    fflush(stdin);
    i = 0;
    if (continuarVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes são dígitos ou ponto decimal
	while (continuarVer[i] != '\0'){
		while ((continuarVer[i] < '0' || continuarVer[i] > '9') && continuarVer[i] != '.'){
		printf("Opcao invalida, digite uma opcao valida:\n\n");
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