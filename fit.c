#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
int main(){
	setlocale(LC_ALL,"Portuguese");	
	float peso, altura, imc, pesoIdeal, tmb, continuar;
	int idade, nomeVer = 0, i = 0;
	char nome[20], genero[2], genString[20], idadeVer[100], pesoVer[100], alturaVer[100], continuarVer[100], objetivo[2], objString[20], atividadeFisica[2], atvString[50];

do{
	system("cls");
	printf("");	printf("\t\t\t\t\x1b[31;47mBem Vindo ao FitFlex\033[0m!");
	printf("");
	printf("\n\t_____________________________________________________________________________________________\n");
		printf("\n\t\tPor favor digite seu nome e idade abaixo!");	
		printf("\n\t\t\tDigite o seu nome: ");
		scanf("%[^\n]%*c", &nome);
	while(nome[i] != '\0' && nomeVer != 1){    
        if((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || isspace(nome[i])){
            i++;
			nomeVer = 0;
        }else{
            printf("\t\tPor favor digite somente letras.");
            printf("\n\t\t\tDigite o seu nome: ");
			scanf("%[^\n]%*c", &nome);
        }
    }
		printf("\t\t\tDigite a sua idade: ");
		scanf("%s", idadeVer);
		fflush(stdin);
		i = 0;
	// Verificar se o primeiro caractere e um sinal de menos (opcional para numeros negativos)
	if (idadeVer[i] == '-'){
			i++;
	}
	// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while(idadeVer[i] != '\0'){
		while((idadeVer[i] < '0' || idadeVer[i] > '9')&&(idadeVer[i] >= 'a' && idadeVer[i] <= 'z' || idadeVer[i] >= 'A' && idadeVer[i] <= 'Z')){
			printf("\t\tIdade inválida, digite uma idade válida: ");
			scanf("%s", idadeVer);
			fflush(stdin);
		}
		i++;
	}
	idade = strtof(idadeVer, NULL);
	printf("\t_____________________________________________________________________________________________\n\n");
	printf("\t\tAgora preciso saber o seu peso e altura para determinar o seu IMC.\n");
	printf("\t\t\tInforme seu peso Kg(Ex: 70,5): ");
	scanf("%s", &pesoVer);
	fflush(stdin);
	i = 0;
	if (pesoVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (pesoVer[i] != '\0'){
		while ((pesoVer[i] < '0' || pesoVer[i] > '9')&&(pesoVer[i] >= 'a' && pesoVer[i] <= 'z'  || pesoVer[i] >= 'A' && pesoVer[i] <= 'Z') && pesoVer[i] != ','){
		printf("\t\tPeso inválido, digite um peso válido(Ex: 70,5): ");
		scanf("%s", &pesoVer);
		}
		i++;
	}
		peso = strtof(pesoVer, NULL);
		printf("\t\t\tInforme sua altura(Ex: 1,70): ");
		scanf("%s", &alturaVer);
		fflush(stdin);
		i = 0;
	if(alturaVer[i] == '-'){
			i++;
	}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (alturaVer[i] != '\0'){
		while ((alturaVer[i] < '0' || alturaVer[i] > '9')&&(alturaVer[i] >= 'a' && alturaVer[i] <= 'z'  || alturaVer[i] >= 'A' && alturaVer[i] <= 'Z') && alturaVer[i] != ','){
		printf("\t\tAltura inválida, digite uma altura válida(Ex: 1,70): ");
		scanf("%s", &alturaVer);
		}
		i++;
	}
	altura = strtof(alturaVer, NULL);
		printf("\t_____________________________________________________________________________________________\n\n");
		printf("\t\tAgora preciso saber seu genero para calcular seu peso ideal:\n");
	do{
		printf("\t\t\tDigite '1' para Masculino ou '2' para Feminino: ");
    	scanf("%s", &genero);
		if (strcmp(genero, "1") == 0){
			printf("\t\t\tGenero Masculino.\n");
			strcpy(genString, "Masculino");
			pesoIdeal = (72.7*altura) - 58;
			printf("\t\t\tSeu peso ideal é:%.1fKg\n",pesoIdeal);
		}else if (strcmp(genero, "2") == 0){
			printf("\t\t\tGenero Feminino.\n");
			strcpy(genString, "Feminino");	
			pesoIdeal = (62.1*altura) - 44.7;
			printf("\t\t\tSeu peso ideal é:%.1f\n",pesoIdeal);
		}else{
			printf("\t\t\tVoce não digitou uma opção válida!\n");
		}
	}while((strcmp(genero, "1")!= 0)&&(strcmp(genero, "2")!= 0));
		printf("\t_____________________________________________________________________________________________\n\n");
    	printf("\t\tEscolha abaixo qual alternativa mais se aproxima de seu objetivo em nossa academia:");
    	printf("\n\t\t\tDigite 1 para Hipertrofia");
    	printf("\n\t\t\tDigite 2 para Emagrecimento");
    	printf("\n\t\t\tDigite 3 para Bem estar e saude\n");
    do{
		printf("\t\t\tDigite aqui: ");
    	scanf("%s", &objetivo);
        if (strcmp(objetivo, "1") ==0){
	    	printf("\t\t\tHipertrofia\n");
		    strcpy(objString, "Hipertrofia");
	    }else if(strcmp(objetivo, "2") == 0){
		    printf("\t\t\tEmagrecimento\n");
	    	strcpy(objString, "Emagrecimento");
    	}else if(strcmp(objetivo, "3") ==0 ){ 
       	 	printf("\t\t\tBem estar e saude\n");
        	strcpy(objString, "Bem estar e saude");
	    }else{
    		printf("\t\t\tVoce não digitou uma opção valida!\n");
    	}
    } while ((strcmp(objetivo, "1") != 0) && (strcmp(objetivo, "2") != 0) && (strcmp(objetivo, "3") != 0));
		printf("\t_____________________________________________________________________________________________\n\n");
		printf("\t\tAgora escolha seu nível de atividade física:\n");
	    printf("\t\t\tDigite 1 se voce não pratica nenhuma atividade física\n");
   	    printf("\t\t\tDigite 2 se voce pratica atividades físicas de 1 a 2 vezes na semana\n");
		printf("\t\t\tDigite 3 se voce pratica atividades físicas 4 vezes ou mais na semana\n");
   do{
	   printf("\t\t\tDigite aqui: ");
	   scanf("%s", &atividadeFisica);
      if (strcmp(atividadeFisica, "1") == 0){
   	   	 	printf("\t\t\tNenhuma atividade física\n");
	    	strcpy(atvString, "Nenhuma atividade física");
      	}else if(strcmp(atividadeFisica, "2") == 0){ 
        	printf("\t\tAtividade física 1 a 2 vezes na semana\n");
        	strcpy(atvString, "Atividade física 1 a 2 vezes na semana");
	  	}else if(strcmp(atividadeFisica, "3") == 0){
        	printf("\t\tatividade física 4 vezes ou mais na semana\n");
        	strcpy(atvString, "Atividade física 4 vezes ou mais na semana");
		}else{
			printf("\t\t\tVoce não digitou uma opção valida!\n");
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
	printf("\t\tSua Taxa Metabolica Basal(TMB) é: %.2f calorias por dia!\n", tmb);
	imc = peso / (altura * altura);
	printf("\t\t\tSeu IMC é: %.1f\n", imc);
	if (imc <= 18.5){
		printf("\t\t\tVoce está abaixo do peso!");
	}else if (imc >= 18.6 && imc < 24.9){
		printf("\t\t\tSeu peso está normal!");
	}else if (imc >= 25 && imc < 29.9){
		printf("\t\t\tVoce está com Sobrepeso!");
	}else if (imc >= 30 && imc < 34.9){
		printf("\t\t\tVoce está com Obesidade grau 1!");
	}else if (imc >= 35 && imc <= 39.9){
		printf("\t\t\tVoce está com Obesidade grau 2!");
	}else{
		printf("\t\t\tVoce está com Obesidade Grau 3!");
	}
	printf("\n\t\tAqui estão 3 dicas para ajudar você em seu objetivo.\n");
	if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-É importante obter orientações de um médico ou nutricionista para garantir que suas escolhas sejam seguras e eficazes.\n");
		printf("\t\t2-Concentre-se em alimentos nutritivos como proteinas magras, carboidratos complexos e gorduras saudaveis.\n");
		printf("\t\t3- Inicie um programa de treinamento de força como levantamento de peso.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Consulte um profissional de saude.\n");
		printf("\t\t2-Concentre-se em uma alimentação saudável e equilibrada.\n");
		printf("\t\t3-Comece com exercicios leves como caminhadas diárias e aumente gradualmente conforme se sentir mais confortável\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Agende uma consulta com um nutricionista para avaliar sua saude atual e discutir opções para ganhar peso de maneira saudável.\n");
		printf("\t\t2-Concentre-se em uma dieta que inclua uma variedade de alimentos nutritivos.\n");
		printf("\t\t3-Incorporar exercícios leves como caminhadas, alongamentos ou ioga pode ser benéfico para sua saúde.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequência de treinos para 3-4 vezes por semana para estimular o crescimento.\n");
		printf("\t\t2-Priorize uma dieta rica em proteínas magras e calorias adequadas para sustentar o crescimento muscular.\n");
		printf("\t\t3-Desenvolva um plano de treinamento estruturado com foco em exercícios compostos e progressão de intensidade.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequência de exercícios para 3-5 vezes por semana combinando aeróbicos e exercícios de resistência.\n");
		printf("\t\t2-Adote uma dieta equilibrada com foco em alimentos nutritivos evitando processados e açucares.\n");
		printf("\t\t3-Monitore as calorias e crie um déficit controlado com orientação de um profissional para perder peso com segurança.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Faça atividade física 3-5 vezes por semana para melhorar sua saúde.\n");
		printf("\t\t2-Priorize alimentos naturais como frutas, vegetais e proteínas magras evitando produtos processados.\n");
		printf("\t\t3-Busque orientação médica para criar um plano de saúde personalizado e atingir seus objetivos com segurança.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Consuma mais calorias, priorizando proteínas, carboidratos saudáveis e gorduras para promover o crescimento muscular.\n");
		printf("\t\t2-Foque em exercícios de musculação variados e aumente gradualmente a carga para estimular o crescimento muscular.\n");
		printf("\t\t3-Priorize o sono adequado e permita que seus músculos descansem entre os treinos para otimizar o crescimento muscular.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha uma dieta equilibrada focando em alimentos nutritivos e controlando calorias.\n");
		printf("\t\t2-Integre treinos intervalados de alta intensidade para aumentar a queima de calorias.\n");
		printf("\t\t3-Priorize a hidratação adequada e o descanso para suportar a recuperação muscular.\n");
	}else if(imc <=18.5 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Mantenha uma alimentação balanceada com foco em proteínas magras, vegetais e grãos integrais.\n");
		printf("\t\t2-Cuide da recuperação com alongamento, sono de qualidade e descanso ativo para evitar lesões.\n");
		printf("\t\t3-Mantenha a hidratação e o equilíbrio de eletrólitos para uma saúde ideal com exercícios frequentes.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Comece o treinamento de resistência gradualmente, aumentando a carga ao longo do tempo.\n");
		printf("\t\t2-Priorize uma dieta rica em proteínas para apoiar o crescimento muscular.\n");
		printf("\t\t3-Considere a orientação de um profissional para um plano personalizado de treino e nutrição.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Inicie atividades leves como caminhadas e evolua gradualmente.\n");
		printf("\t\t2-Adote uma dieta equilibrada com controle de porções.\n");
		printf("\t\t3-Consulte um profissional de saúde para orientações personalizadas.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Comece com atividades leves como caminhadas regulares.\n");
		printf("\t\t2-Adote uma dieta rica em vegetais, proteínas magras e fibras.\n");
		printf("\t\t3-Realize check-ups médicos regulares para monitorar sua saúde.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequência dos treinos para pelo menos 3-4 vezes por semana.\n");
		printf("\t\t2-Priorize exercícios de resistência e musculação para estimular o crescimento muscular.\n");
		printf("\t\t3-Consuma uma dieta rica em proteínas e calorias controladas para apoiar o ganho de massa muscular.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequência de exercícios para pelo menos 3-5 vezes/semana para queimar mais calorias.\n");
		printf("\t\t2-Priorize atividades aeróbicas como corrida, natação ou ciclismo para acelerar a perda de peso.\n");
		printf("\t\t3-Adote uma dieta equilibrada, com ênfase em alimentos ricos em fibras e proteínas.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente a frequência de exercícios para pelo menos 3-5 vezes/semana para melhorar sua saúde geral.\n");
		printf("\t\t2-Conclua atividades variadas como caminhadas, ioga e musculação para promover a saúde cardiovascular e muscular.\n");
		printf("\t\t3-Mantenha uma alimentação balanceada e rica em vegetais, proteínas magras e grãos integrais.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Priorize uma dieta rica em proteínas magras como frango, peixe e ovos para apoiar o crescimento muscular.\n");
		printf("\t\t2-Realize exercícios de resistência como musculação variando os exercícios regularmente.\n");
		printf("\t\t3-Assegure-se de descansar adequadamente entre os treinos e obter sono de qualidade.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha uma dieta equilibrada com foco em alimentos integrais, vegetais, proteínas magras e evite excesso de calorias vazias.\n");
		printf("\t\t2-Varie seus treinos incluindo exercícios de alta intensidade e aeróbicos para maximizar a queima de calorias.\n");
		printf("\t\t3-Monitore seu progresso, ajustando sua dieta e rotina de exercícios conforme necessário.\n");
	}else if(imc >= 18.6 && imc < 24.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Continue com sua rotina regular de exercícios mantendo um equilíbrio entre cardio e musculação.\n");
		printf("\t\t2-Priorize uma alimentação balanceada rica em nutrientes incluindo frutas, vegetais, proteínas magras e grãos integrais.\n");
		printf("\t\t3-Cuide da recuperação garantindo um sono de qualidade gerenciando o estresse e incluindo atividades de relaxamento como ioga.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Inicie um programa de treinamento de resistência para construir músculos.\n");
		printf("\t\t2-Ajuste sua alimentação para incluir uma quantidade adequada de proteínas, carboidratos e gorduras saudáveis para apoiar o crescimento.\n");
		printf("\t\t3-Consulte um médico para garantir que sua saúde esteja em ordem antes de iniciar um novo programa de treinamento e dieta.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Comece com atividades leves como caminhadas e aumente gradualmente a intensidade e a frequência para queimar calorias.\n");
		printf("\t\t2-Adote uma dieta equilibrada rica em vegetais proteínas magras e evite alimentos processados e açucarados.\n");
		printf("\t\t3-Considere a ajuda de um nutricionista para criar um plano personalizado de perda de peso e estabelecer metas realistas.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Inicie um programa de atividade física leve a moderada como caminhadas, natação ou ciclismo com a orientação de um profissional de saúde.\n");
		printf("\t\t2-Adote uma dieta balanceada com foco em alimentos naturais, como frutas, vegetais, proteÃ­nas magras e grãos inteiros.\n");
		printf("\t\t3-Mantenha um estilo de vida ativo no dia a dia como optar por escadas em vez de elevadores fazer pausas para esticar-se no trabalho.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequência dos treinos para pelo menos 3-4 vezes por semana para estimular o crescimento muscular de maneira mais eficaz.\n");
		printf("\t\t2-Concentre-se em exercícios de resistência, como levantamento de peso, e inclua uma variedade de grupos musculares em seus treinos.\n");
		printf("\t\t3-Mantenha uma dieta rica em proteínas para apoiar a recuperação muscular e o crescimento.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente a frequência dos exercícios para pelo menos 3-4 vezes por semana para acelerar a queima de calorias.\n");
		printf("\t\t2-Priorize treinos que combinem exercícios aeróbicos como corrida ou natação com exercícios de resistência para construir músculos e aumentar o metabolismo.\n");
		printf("\t\t3-Mantenha uma alimentação balanceada com foco em alimentos naturais e evite o consumo excessivo de calorias, gordura saturadas e açúcares refinados.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente a frequência dos exercícios para pelo menos 3-4 vezes por semana para melhorar sua saúde geral.\n");
		printf("\t\t2-Inclua uma variedade de atividades como caminhadas, natação ou ioga para promover a resistência e saúde cardiovascular.\n");
		printf("\t\t3-Adote uma alimentação equilibrada rica em frutas, vegetais, grãos integrais e proteínas magras.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Priorize uma dieta rica em proteínas magras, frango, peixe, ovos e leguminosas para apoiar o crescimento muscular.\n");
		printf("\t\t2-Realize treinamentos como levantamento de pesos com ênfase na progressão de cargas e variedade de exercícios.\n");
		printf("\t\t3-Certifique-se de descansar adequadamente entre os treinos e dormir o suficiente para ter uma recuperação adequada. \n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Mantenha um déficit calórico controlado consumindo menos calorias do que queima para promover a perda de peso de forma saudável.\n");
		printf("\t\t2-Inclua uma combinação de exercícios aeróbicos e treinamento de resistência em sua rotina pois isso ajudará queimar calorias e preservar a massa muscular.\n");
		printf("\t\t3-Priorize uma dieta balanceada com alimentos ricos em nutrientes como frutas, vegetais proteínas magras e grãos inteiros e evite alimentos processados.\n");
	}else if(imc>=25.0 && imc<29.9 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Mantenha uma rotina consistente de exercícios incluindo atividades aeróbicas e de resistência.\n");
		printf("\t\t2-Adote uma alimentação balanceada com ênfase em alimentos naturais como frutas, verduras, proteínas magras e grãos inteiros.\n");
		printf("\t\t3-Priorize o sono de qualidade e o gerenciamento do estresse para otimizar sua saúde.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-É essencial obter avaliação médica para garantir que sua saúde está em ordem antes de iniciar o treinamento para hipertrofia.\n");
		printf("\t\t2-Inicie com um programa de treinamento supervisionado para garantir que está fazendo os exercícios corretamente e de forma segura.\n");
		printf("\t\t3-Para promover o ganho de massa muscular mantenha uma dieta rica em proteínas magras, carboidratos complexos e gorduras saudáveis.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Consulte um médico ou nutricionista para criar um plano de emagrecimento personalizado e seguro.\n");
		printf("\t\t2-Estabeleça metas realistas e comece com pequenas mudanças na alimentação.\n");
		printf("\t\t3-Gradualmente introduza atividades físicas e aumente a frequência e intensidade conforme sua condição física melhore.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "1") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Inicie com atividades leves como caminhadas curtas e gradualmente aumente a intensidade e duração do exercício.\n");
		printf("\t\t2-Consulte um médico para avaliar sua saúde geral e receber orientação sobre um programa de exercícios seguro.\n");
		printf("\t\t3-Adote uma dieta balanceada com foco em alimentos naturais e nutritivos controlando o consumo de calorias.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Aumente a frequência semanal de treinos para pelo menos 4-5 vezes com foco em exercícios de resistência e musculação.\n");
		printf("\t\t2-Consuma uma dieta equilibrada e rica em proteínas para promover o crescimento muscular evitando excesso de calorias.\n");
		printf("\t\t3-Considere a orientação de um fisioterapeuta para desenvolver um programa de treinamento adequado para minimizar riscos de lesões.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Aumente gradualmente a frequência de exercícios para pelo menos 150 minutos de atividade moderada por semana.\n");
		printf("\t\t2-Ajuste sua alimentação para criar um déficit calórico,\n reduzindo a ingestão de calorias.\n");
		printf("\t\t3-Consulte um nutricionista para desenvolver um plano personalizado de perda de peso e acompanhe seu progresso regularmente.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "2") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Aumente gradualmente a frequência dos exercícios para atingir pelo menos 150 minutos de atividade moderada por semana.\n");
		printf("\t\t2-Adote uma dieta balanceada, rica em vegetais, fibras e proteínas magras, evitando alimentos processados e ricos em açúcares.\n");
		printf("\t\t3-Monitore sua saúde com exames médicos regulares para controlar fatores de risco como pressão arterial e níveis de glicose.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "1") ==0)){
		printf("\t\t1-Mantenha uma rotina de exercícios consistente focando em treinamento de resistência para promover o crescimento muscular.\n");
		printf("\t\t2-Consuma uma dieta equilibrada e rica em proteínas para sustentar o crescimento muscular.\n");
		printf("\t\t3-Certifique-se de descansar adequadamente para permitir que seus músculos se recuperem e cresçam.\n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "2") ==0)){
		printf("\t\t1-Continue com a rotina de exercícios frequente priorizando exercícios aeróbicos e de resistência para queimar calorias.\n");
		printf("\t\t2-Adote uma alimentação saudável e equilibrada com ênfase em porções controladas e alimentos ricos em nutrientes.\n");
		printf("\t\t3-Considere trabalhar com um nutricionista ou personal trainer para criar um plano de emagrecimento personalizado. \n");
	}else if(imc>=30 && (strcmp(atividadeFisica, "3") == 0) && (strcmp(objetivo, "3") ==0)){
		printf("\t\t1-Continue com a prática regular de atividades físicas, focando em exercícios aeróbicos e de resistência.\n");
		printf("\t\t2-Adote uma alimentação equilibrada com redução de calorias e ênfase em alimentos saudáveis como frutas, vegetais, proteínas magras e grãos inteiros.\n");
		printf("\t\t3-Mantenha o acompanhamento médico e se necessário consulte um nutricionista para criar um plano de emagrecimento seguro.\n");
}
	printf("\t________________________________________________________________________________________\n\n");
    printf("\t\t\tAqui estao informacoes:\n");
   	printf("\t\t\tNome: %s\n", nome);
	printf("\t\t\tIdade: %d anos\n", idade);
	printf("\t\t\tGenero escolhido: %s\n", genString);
	printf("\t\t\tPeso: %.2fKg\n", peso);
	printf("\t\t\tAltura: %.2f\n", altura);
	printf("\t\t\tObjetivo escolhido: %s\n", objString);
	printf("\t\t\tNivel de atividade fisica escolhida: %s\n",atvString);	
	printf("\t\t\tSeu peso ideal é: %.2fKg\n", pesoIdeal);
	printf("\t\t\tSeu IMC deu:%.2f\n", imc);
	printf("\t\t\tSeu TMB deu:%.2f\n", tmb);
    printf("\t________________________________________________________________________________________\n");
	printf("\n\t\tEscolha '1' para sair do programa ou '2' para repetir todo o processo: ");
    scanf(" %s", &continuarVer);
    fflush(stdin);
    i = 0;
    if (continuarVer[i] == '-'){
			i++;
		}
		// Verificar se os caracteres seguintes sao digitos ou ponto decimal
	while (continuarVer[i] != '\0'){
		while ((continuarVer[i] < '0' || continuarVer[i] > '9') && continuarVer[i] != '.'){
		printf("\t\tOpção inválida, digite uma opção válida: ");
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