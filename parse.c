#include "shell.h"

/*
    parse . particiona o comando (armazenado em ptrLinha) em argumentos
    exemplo ptrLinha -> "ls  -l /etc/passwd & "
    O string contem caracteres e espaços e é terminado com um \0
*/

int parse (char *buf, char **args)
{
  int cnt = 0;
  while ('\0' != *buf)
    {
      /* saltar whitespace. Substituimos whitespace por um \0 */
      while (isspace ((unsigned char) *buf))
        *buf++ = '\0';

      *args++ = buf;/* salvaguarda argumento */
      cnt++;

      /* salta sobre os caracteres do argumento ou encontrar o fim da linha*/
      while ((*buf != '\0') && (!isspace ((unsigned char) *buf)))
        buf++;
    }
  *args = (char *) NULL;/* Inserir o ultimo argumento igual a NULL */
  return cnt;
}
