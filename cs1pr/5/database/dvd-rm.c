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
  FILE *pTemp;
  bool Exists = false;

  if (argc < 2 || argc > 2)
  {
    printf("Error: Need to specify ID of one DVD to remove!\n");
    return 1;
  }

  if ( atoi(argv[1]) < 0 || atoi(argv[1]) > 60000 )
  {
    printf("Error: ID must be between 0 and 60000\n");
    return 1;
  }

  pFile = fopen("data.dat","r");
  if (pFile == NULL)
  {
    printf("Error: File does not exist.\n");
    return 1;
  }


  while((fread(&dvd,sizeof(struct DVD_Record),1,pFile)) != 0)
  {
    if( dvd.ID == atoi(argv[1]) )
    {
      Exists = true;
    }
  }

  if (Exists == false)
  {
     printf("Error: DVD does not exist!\n");
  }
  else
  {
    rewind(pFile);
    pTemp = fopen("data.tmp","w");
    while((fread(&dvd,sizeof(struct DVD_Record),1,pFile)) != 0)
    {
      if( dvd.ID != atoi(argv[1]) )
      {
        fwrite(&dvd,sizeof(struct DVD_Record),1,pTemp);
      }
    }
    if (Exists == true)
    {
      printf("Deleted %s\n", argv[1]);
    }
  fclose(pFile);
  fclose(pTemp);
  remove("data.dat");
  rename("data.tmp","data.dat");
  return 0;
 }
}
