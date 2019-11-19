#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct DVD_Record {
  int ID;
  char name[32];
  char length[3];
};

typedef struct DVD_Record DVD;

int main(int argc, char ** argv) {

  DVD dvd;
  FILE *pFile;
  bool present = false;

  if (argc >2)
  {
    printf("Error:Can only specify one ID!\n!");
    return 1;
  }
  printf("ID,Name,TotalLength\n");
  pFile = fopen("data.dat","r");

  if (pFile == NULL)
  {
    printf("Error: File does not exist.\n");
    return 1;
  }

  if (argc == 2)
  {
    while((fread(&dvd,sizeof(struct DVD_Record),1,pFile)) != 0)
    {
      if ( dvd.ID == atoi(argv[1]) )
      {
        printf("%d,%s,%s \n",dvd.ID,dvd.name,dvd.length);
        present = true;
      }
    }

  }

  if (argc == 1)
  {
    while((fread(&dvd,sizeof(struct DVD_Record),1,pFile)) != 0)
    {
      printf("%d,%s,%s \n",dvd.ID,dvd.name,dvd.length);
    }
  }
  if (argc == 2 && present == false)
  {
    printf("Error: ID does not exist!\n");
  }
  fclose(pFile);
  return 0;
}
