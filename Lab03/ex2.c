#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid = fork();  // Cria um processo filho

    if (pid < 0) 
    {
        // Se ocorrer um erro ao criar o processo filho
        printf("Erro ao criar o processo filho!\n");
        return 1;
    }

    if (pid == 0) 
    {
        // Este bloco será executado pelo processo filho
        printf("Este é o processo filho. PID: %d\n", getpid());

        // Loop que imprime uma mensagem 5 vezes com 1 segundo de intervalo
        for (int i = 0; i < 5; i++) 
        {
            printf("Processo filho imprimindo %d vez(es)\n", i + 1);
            sleep(1);  // Pausa por 1 segundo
        }

        exit(0);  // Finaliza o processo filho
    } 
    else 
    {
        // Este bloco será executado pelo processo pai
        printf("Este é o processo pai. PID: %d, PID do filho: %d\n", getpid(), pid);

        // O pai espera que o processo filho termine usando wait()
        wait(NULL);

        // Após o término do processo filho, o pai imprime uma mensagem
        printf("Processo filho terminou.\n");
    }

    return 0;
}
