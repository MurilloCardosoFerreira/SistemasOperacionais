#include <stdio.h>
#include <stdlib.h>

int main() 
{
  FILE *file;
  char buffer[128];
  int lineCount = 1;
  size_t bytesRead;
  int i;

  // Abre o arquivo em modo leitura
  file = fopen("lab2_ex2.txt", "r");

  // Verifica se o arquivo foi aberto com sucesso
  if (file == NULL) 
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  // Lê o arquivo em partes de 128 bytes
  while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) 
  {
    // Conta o número de quebras de linha (\n) no buffer
    for (i = 0; i < bytesRead; i++) 
    {
      if (buffer[i] == '\n') 
      {
        lineCount++;
      }
    }
  }

  // Fecha o arquivo
  fclose(file);

  // Exibe o número total de linhas
  printf("Número total de linhas: %d\n", lineCount);

  return 0;
}
