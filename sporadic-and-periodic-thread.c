#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void* PrintHelloInterval(void* threadid) { //funcao thread periodica
	int interval = 200;
	
	long id;
	id = (long)threadid;	//conversao de void pra long
	
	while (1) {
		printf("Thread %ld says Hello periodically in %dms!\n", id, interval);
		Sleep(interval);
	}
	
	pthread_exit(NULL); //finalizacao da thread periodica
}

void* PrintKey(void* threadid) {//funcao thread esporadica
	long id;
	id = (long)threadid;	//conversao de void pra long
	
	while (1) {
		printf("\nThread %ld said you pressed the %c key sporadically!\n\n", id, getch());
	}
	
	pthread_exit(NULL); //finalizacao da thread esporadica
}

int main() {
	pthread_t t1, t2; //criando t1 e t2 do tipo thread
	int create; //variavel que recebe o retorno da funcao pthread_create()
	long num; //identificador da thread
	
	puts("Pressione qualquer tecla para ativar a thread esporadica!\n");
	
	num = 1;
	printf("Main: criando a thread %ld\n", num);
	create = pthread_create(&t2, NULL, PrintHelloInterval, (void*)num);
	pthread_join(t1, NULL);
	
	num = 2;
	printf("Main: criando a thread %ld\n\n", num);
	create = pthread_create(&t1, NULL, PrintKey, (void*)num);
	pthread_join(t2, NULL);
	
	printf("Main: finalizando\n");
	
	return 0;
}
