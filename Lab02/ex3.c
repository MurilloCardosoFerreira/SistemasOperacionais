#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int fd_origem, fd_destino;
    char buffer[128];
    ssize_t bytesRead, bytesWritten;

    // Abrir o arquivo de origem em modo leitura (O_RDONLY)
    fd_origem = open("lab2_ex3_origem.txt", O_RDONLY);
    if (fd_origem == -1) 
    {
        perror("Erro ao abrir o arquivo de origem");
        return 1;
    }

    // Abrir ou criar o arquivo de destino em modo escrita (O_WRONLY | O_CREAT | O_TRUNC)
    fd_destino = open("lab2_ex3_destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_destino == -1)
    {
        perror("Erro ao abrir o arquivo de destino");
        close(fd_origem); // Fechar o arquivo de origem antes de sair
        return 1;
    }

    // Loop para ler do arquivo de origem e escrever no arquivo de destino
    while ((bytesRead = read(fd_origem, buffer, sizeof(buffer))) > 0)
      {
        bytesWritten = write(fd_destino, buffer, bytesRead);
        if (bytesWritten != bytesRead) 
        {
            perror("Erro ao escrever no arquivo de destino");
            close(fd_origem);
            close(fd_destino);
            return 1;
        }
    }

    // Verificar se houve algum erro na leitura
    if (bytesRead == -1) 
    {
        perror("Erro ao ler o arquivo de origem");
    }

    // Fechar os arquivos
    close(fd_origem);
    close(fd_destino);

    return 0;
}
