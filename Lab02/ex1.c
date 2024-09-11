#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *file;
    char buffer[1024];

    // Abre o arquivo em modo leitura
    file = fopen("lab2_ex1.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Lê o conteúdo do arquivo para o buffer
    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        // Exibir o conteúdo lido na tela
        printf("%s", buffer);
    }

    // Fecha o arquivo
    fclose(file);
  
    return 0; // Encerra o programa com sucesso
}
