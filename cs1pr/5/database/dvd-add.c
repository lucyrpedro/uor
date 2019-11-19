#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct DVD_Record {
  int ID;
  char name[32];
  char length[3];
};

typedef struct DVD_Record DVD;

int main(int argc, char ** argv) {

  DVD dvd;
  FILE *pFile;
  bool Exists = false;
  int IDLast = 0;

  if (argc != 3)
  {
    printf("Error: Must state title and duration separated by a space.\n");
    return 1;
  }

  if ( atoi(argv[2]) <0 || atoi(argv[2]) > 150)
  {
    printf("Error: Duration needs to be between 0-150 minutes\n");
    return 1;
  }

  if (strlen(argv[1]) > 32)
  {
    printf("Error: Film title needs to be less than 32 characters\n");
    return 1;
  }

  pFile = fopen("data.dat","rb+");
  if (pFile == NULL)
  {
    pFile = fopen("data.dat","wb+");
  }

  while((fread(&dvd,sizeof(struct DVD_Record),1,pFile)) != 0)
  {
    if( (strcmp(dvd.name,argv[1])) == 0 )
    {
      Exists = true;
    }
    IDLast = dvd.ID;
  }

  if (Exists == false)
  {
    strcpy(dvd.name,argv[1]);
    strcpy(dvd.length, argv[2]);
    dvd.ID = IDLast + 1;
    fwrite(&dvd,sizeof(struct DVD_Record),1,pFile);
    printf("Added ID %d\n", dvd.ID);
  }
  else
  {
    printf("Error: DVD already exists!\n");
  }
  fclose(pFile);

  return 0;
}
