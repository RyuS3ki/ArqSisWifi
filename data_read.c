#include <stdio.h>

int data_read(char *teclado){

  ssize_t bytes_teclado;
  size_t num_bytes;
  char *teclado;

  num_bytes = 0;
  teclado = NULL;
  bytes_teclado = getline(&teclado, &num_bytes, stdin);

  return bytes_teclado;
}
