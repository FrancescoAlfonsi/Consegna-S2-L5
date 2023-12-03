#include <stdio.h>
#include <stdlib.h> // per exit()

void menu();
void moltiplica();
void dividi();
void ins_string();
short int valida_short_int();
int valida_intero();

int main(){
  char scelta={'\0'};
  menu();
  scanf(" %c", &scelta);
  
  switch (scelta){
  case 'A':
  case 'a':
    moltiplica();
    break;
  case 'B':
  case 'b':
    dividi();
    break;
  case 'C':
  case 'c':
    ins_string();
    break;
  default:
    printf("Scelta non valida.\n");
    exit(EXIT_FAILURE);}
  return 0;}

void menu(){
  printf("Benvenuto, sono un assistente digitale, posso aiutarti a sbrigare alcuni compiti\n");
  printf("Come posso aiutarti?\n");
  printf("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\n");}

void moltiplica(){
  short int a, b;
  printf("Inserisci i due numeri da moltiplicare:");
  a=valida_short_int();
  b=valida_short_int();
  short int prodotto = a * b;
  printf("Il prodotto tra %d e %d e': %d\n", a, b, prodotto);}

void dividi(){
  int a, b;
  printf("Inserisci il numeratore:");
  a=valida_intero();
  printf("Inserisci il denominatore:");
  b=valida_intero();
  if (b == 0) {
    printf("Errore: Divisione per zero non consentita.\n");
    exit(EXIT_FAILURE);}
  int divisione = a / b;
  printf("La divisione tra %d e %d e': %d\n", a, b, divisione);}

void ins_string(){
    char stringa[10];
    printf("N.B.: Il massimo di caratteri consentiti per la stringa è 10");
    printf("\nInserisci la stringa:");
    getchar(); // Elimina il carattere 'a capo' lasciato nel buffer dalla scelta effettuata in menu();
    fgets(stringa, sizeof(stringa), stdin); // fgets per evitare buffer overflow
    printf("Hai inserito la stringa: %s\n", stringa);}

short int valida_short_int(){
  short int numero;
  while(1){
    printf("\n Inserisci un numero: ");
    if (scanf("%hd",&numero)==1){
      break;}
    else{
      while (getchar()!='\n');
      printf("\n\n Lettere non accettate, inserire un numero.\n");}}
  return numero;}

int valida_intero(){
  int numero;
  while(1){
    printf("\n Inserisci un numero: ");
    if (scanf("%d",&numero)==1){
      break;}
    else{
      while (getchar()!='\n');
      printf("\n\n Lettere non accettate, inserire un numero.\n");}}
  return numero;}