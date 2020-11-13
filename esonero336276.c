#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
char M[128],K[128],C[128],J[128];
int caso1();
int caso2();
time_t t;   //variabile tempo per il semerandomico
char caratteri_speciali[33][5]={"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SPACE"}; //Matrice per i caratteri speciali nell'intervallo [0-32]
int scelta,a;
int main()
{
  system("clear");
  printf("Inserisca una stringa M di 128 caratteri\nSe inserirà una stringa più lunga, tutti i caratteri in eccesso verranno scartati\n");
  fgets(M,129,stdin); /* con fgets viene chiesta una stringa da tastiera e vengono presi in considerazione solo i primi 128 caratteri*/
    fflush(stdin);
  system("clear");
  printf("Adesso le diamo l'opportunità di scegliere tra tre strade:\n*) Digitando (0) terminerà il programma\n*) Digitando (1) le sarà chiesto di inserire da tastiera la chiave K di cifratura \n*) Digitando (2) le sarà chierata una chiave di cifratura K personale:\n");
  char *mynewline=strchr(M,'\n');   //eliminazione del '\n' finale della stringa
  if(mynewline!=NULL)
  *mynewline='\0';
  for(int i=0;i<128;i++)
  J[i]=M[i];
  do                                                     //ciclo che permette di controllare se la scelta è stata effettuta per bene
  {
    if(scanf("%d",&scelta)!=1)
    {
      scelta=-1;
    }
    int c;
    while((c=getc(stdin))!='\n' && c!= EOF);
    system("clear");
    switch (scelta)                                      //Lo switch in base al valore di scelta fa eseguire il caso opportuno
    {
      case 0:
      system("clear");
      break;
      case 1:
      caso1();
      break;
      case 2:
      caso2();
      break;
      default:
      printf("Le ricordiamo che la scelta è tra 0, 1, 2\n");
    }
  }while(scelta<0 || scelta>2);
}

int caso1()
{
  int lun=strlen(M);
  printf("Benissimo ha scelto di inserire lei la chiave di cifratura K\nLa informiamo che questa chiave deve contenere come minimo %d caratteri e massimo 128\n",lun);
  do
  {
    fgets(K,129,stdin);
      fflush(stdin);
    system("clear");                                                                  //pulisco la schermata per lasciare solo l operazione che si sta facendo al momento
      if(strlen(K)<lun)
      printf("La preghiamo di inserire nuovamente la chiave K [%d-128]\n",lun);
  } while(strlen(K)<lun);
  for(int i=1;i<lun;i++)
  C[i]=M[i]^K[i];             //operazione oxr tra caratteri corrispettivi
  C[0]=J[0]^K[0];
  printf("La stringa cifrata C è:\n");
  for(int i=0;i<lun;i++)
  {
    if(C[i]<33)
    printf("%s ",caratteri_speciali[(int)C[i]]);
    else
    printf("%c ",C[i]);
  }
  printf("\nLa chiave M era:\n");
  for(int i=0;i<lun;i++)
  printf("%c",J[i]);
  printf("\nLa chiave K era:\n");
  printf("%s",K);
  return 0;
}

int caso2()
{
  int lun=strlen(M);
  system("clear");                                     //pulisco la schermata per lasciare solo l operazione che si sta facendo al momento
  printf("\nLa stringa M da lei inserita era:\n");
  for(int i=0;i<lun;i++)
  printf("%c",M[i]);
  srand((unsigned)time(&t));
  for(int i=0;i<lun;i++)
  {
    a=33+rand()%94;                                      //ritorna un numero da 0 a 127
    K[i]=a;
  }
  printf("\nLa chiave K è:\n");
  for(int i=0;i<lun;i++)                           //stampo la chiave K
  printf("%c",K[i]);
  for(int i=0;i<lun;i++)
  C[i]=M[i]^K[i];                                      //faccio l operatore ^ tra il carattere i-esimo e carattere i-esimo delle due stringhe attraerso un ciclo for
  printf("\nLa stringa cifrata C è:\n");
  for(int i=0;i<lun;i++)
  {
    if(C[i]<33)
    printf(" %s ",caratteri_speciali[(int)C[i]]);
    else
    printf("%c ",C[i]);
  }
  printf("\n");                                  //stampo la stringa c con un ciclo for per evidenziare meglio ogni carattere e la sua posizione                                      //utilizzando la proprietà del ^ ritorno alla stringa M
  return 0;
}
