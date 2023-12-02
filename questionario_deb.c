#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

#define BOLD_ON  "\e[1m"
#define BOLD_OFF   "\e[m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

void presentazione();
void presentazione_in_do();
int prima_domanda();
int seconda_domanda();
int terza_domanda();
int quarta_domanda();
int quinta_domanda();
int valida_intero();
void valida_stringa();
int solo_lettere(const char *str);



int main() {
  int punteggio=0, sciagure=0, gioca=0;
  presentazione();
  do{
    int a=0,b=0,c=0,d=0,e=0;
    presentazione_in_do();
    bool controllo=true;
    while(controllo){
      printf("\n\n Iniziare una nuova partita?\n\n 1. Sì\t 2. Grida Jumanji\n\n ");
      gioca=valida_intero();
      if(gioca!=1 && gioca!=2){
	printf("\n\n Sono accettati soltanto i numeri 1 e 2 in risposta alla domanda.");
	printf("\n Sarete riportati alla domanda di scelta inizio partita.");
	printf("\n Scegliete: 1 per iniziare una nuova partita o 2 per uscire dal gioco.");}
      else{
	controllo=false;
	system("clear");
	punteggio=0;
	sciagure=0;
	if(gioca==1){
	  char giocatore[30];
	  valida_stringa(giocatore);
	  printf("\n\n Benvenuto in Jumanji, %s.",giocatore);
	  printf("\n Iniziamo con le domande.");
	  a=prima_domanda(); if(a==2)punteggio++; if(a==3)sciagure++;
	  b=seconda_domanda(); if(b==1)punteggio++; if(b==2)sciagure++;
	  c=terza_domanda(); if(c==2)sciagure++; if(c==3)punteggio++;
	  d=quarta_domanda(); if(d==1)punteggio++; if(d==2)sciagure++;	  
	  e=quinta_domanda(); if(e==2)punteggio++; if(e==1)sciagure++;
	  printf("\n\n Il tuo punteggio, %s, e': %d; ti sono state invece inflitte %d sventure.\n\n ",giocatore,punteggio,sciagure);}
	else
	  return 0;}}}
  while(gioca==1);
  return 0;}

void presentazione(){
  printf(RED BOLD_ON "\n\n\t\t\t  Jumanji\t\t\t\n" BOLD_OFF RESET);  
  printf("\n Un gioco che sa trasportar chi questo mondo vuol lasciar.");
  printf("\n Questo gioco vi proporrà cinque domande.");
  printf("\n Ogni risposta esatta vale un punto.");
  printf("\n Ogni risposta errata e' fonte di sventura.");
  printf("\n Alcune risposte sono considerate ne' corrette ne' errate.");
  printf("\n Queste risposte non porteranno sventure ne' alzeranno il punteggio.");}

void presentazione_in_do(){
  printf(BOLD_ON "\n\n Avventurosi attenzione. Non cominciate se non intendete finire." BOLD_OFF);
  printf(BOLD_ON "\n Ogni sconvolgente conseguenza del gioco scomparirà solo quando" BOLD_OFF);
  printf(BOLD_ON "\n un giocatore raggiunto Jumanji gridato forte il nome avrà." BOLD_OFF); }

int prima_domanda (){
  printf("\n\n Chi non deve nominare mai piu' Pappalardo\n");
  printf("\n 1. Mia madre\t2. La madre di Zequila\t3. Mark Caltagirone\n\n ");
  int risposta;
  risposta=valida_intero();
  if (risposta==1){
    printf("\n Anche, ma non totalmente corretto. Zero punti e zero sciagure.\n\n");
    return 1;}
  else if (risposta==2){
    printf("\n Coretto. Ma non nominarla maiiiiii. Maiiii. Ti spacco la faccia.\n\n");
    return 2;}
  else if (risposta==3){ 
    printf("\n Risposta errata. Nella giungla dovrai stare, finche' un 5 o un 8 non compare.\n\n");
    return 3;}
  else{
    printf("\n\n Primo avvertimento:");
    printf("\n Attenzione, Trovatore, la domanda accetta in risposta soltanto i numeri 1, 2 e 3.");
    printf("\n Per ora soltanto un richiamo, i prossimi errori non saranno altrettanto ben accetti.");
    printf("\n Proviamo di nuovo.\n");
    prima_domanda();}}

int seconda_domanda(){
  printf("\n Cosa doveva fare Mara Venier col disco regalato da Ornella Vanoni?\n ");
  printf("\n 1. Scelofanarlo \t2. Celofanarlo \t3. Nessuno l'ha mai capito\n\n ");
  int risposta;
  risposta=valida_intero();
  if (risposta==1){	  
    printf("\n Corretto. Ora va', e scelofanalo\n\n");
    return 1;}
  else if (risposta==2){
    printf("\n Risposta errata. Ha zanne aguzze. Vi vuole assaggiare. Non vi conviene... temporeggiare.\n\n");
    return 2;}
  else if (risposta==3){
    printf("\n Vero, ma non la esattamente la risposta che volevamo. Zero punti.\n\n");
    return 3;}
  else{
    printf("\n\n Secondo avvertimento:");
    printf("\n Richiamo da parte di Germano Mosconi:");
    printf(RED "\n Ma che ooh. Ma chi è quel mona che non sa nemmeno digitare un numero?" RESET);
    printf("\n Siamo pero' buoni e ti diamo un'altra possibilita'.\n");
    seconda_domanda();}}

int terza_domanda(){
  printf("\n Grazie a cosa vinsero battaglia le Amazzoni?\n ");
  printf("\n 1. La loro fuga\t2. La loro foga\t3. La loro figa\n\n ");
  int risposta;
  risposta=valida_intero();
  if (risposta==3){	  
    printf("\n Esattamente la risposta che ci piace. Guadagni un punto.\n\n");
    return 3;}
  else if (risposta==1){
    printf(" Risposta corretta, ma non sarai mai memorabile come il signor Giancarlo. Zero Punti per te.\n\n");
    return 1;}
  else if (risposta==2){
    printf("\n Risposta errata. Un cacciatore dalla giungla è venuto... ti fa sentire un bambino sperduto.\n\n ");
    return 2;}
  else{
    printf("\n\n Terzo avvertimento:");
    printf(RED "\n Signora, i numeri. Signoraaaaaaaaaaaaa." RESET);
    printf("\n Solo numeri, o al massimo limoni. E di numeri solo 1, 2 o 3.");
    printf("\n Qualsiasi altra cosa, prolunghera' solo la tua permanenza in questo gioco.");
    printf("\n Vuoi continuare con questo loop? O vogliamo andare avanti?\n");
    terza_domanda();}}

int quarta_domanda(){
  printf("\n Quale presidente si è finto morto per non rispondere alle domande della Perego?\n ");
  printf("\n 1. Andreotti\t2. PIER Silvio Berlusconi \t3. Truce Baldazzi\n\n ");
  int risposta=0;
  risposta=valida_intero();
  if (risposta==1){  
   printf("\n Un punto davvero meritato.\n\n");
   return 1;}
  else if (risposta==2 || risposta==3){
   printf("\n Risposta errata. Si mette male la missione, scimmie rallentano la spedizione.\n\n ");
   return 2;}
  else{
    printf("\n\n Quarto avvertimento:");
    printf("\n Serio? Non hai acora capito che devi digitare soltanto 1, 2 o 3?");
    printf("\n Cosa? Dici che vedi rabbia nelle mie risposte?");
    printf(RED "\n Ma quale rabbia? Che cazzo di rabbia mi diceeee?" RESET);
    printf("\n Vabbe', Proviamo di nuovo.\n");
    quarta_domanda();}}

int quinta_domanda(){
  printf("\n Ultima domanda. Due risposte saranno considerate corrette, una sola ti ricoprira' di sventura.");
  printf("\n \n Fa schiuma ma non e' sapone. Cos'e'?\n");
  printf("\n 1. La birra\t2. La borra \t3. Rosario Muniz\n\n ");
  int risposta=0;
  risposta=valida_intero();
  if (risposta==2||risposta==3){	  
    printf("\n Complimenti, risposta errata ma non per il nostro gioco. Guadagni un punto.\n");
    printf("\n Gioco Terminato!\n");
    return 2;}
  else if (risposta==1){
    printf("\n Risposta errata. Basterà un pizzico per farti grattare, con mille starnuti ti farà dimenare.\n\n ");
    printf("\n Gioco Terminato!\n");
    return 1;}
  else{
    printf("\n\n Quinto e ultimo avvertimento:");
    printf("\n Ok, mi hai tolto ogni speranza.");
    printf("\n Come consiglia il poeta:");
    printf(BOLD_ON "\n Non raginero' piu' di te, ma guardo e passo" BOLD_OFF);
    printf("\n Ecco a te un altro tentativo:\n");
    quinta_domanda();}}

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

void valida_stringa(char giocatore[]){
  while(1){
    printf("\n Inserisci il tuo nome: ");
    if(scanf("%28s",giocatore)==1 && solo_lettere(giocatore)){
      break;}
    else{
      while (getchar() != '\n');
      printf("\n Input non valido, inserire un nome valido (solo lettere e piu' corto di 30 lettere).\n");}}}

int solo_lettere(const char *str){
  while(*str){
    if(!isalpha(*str)){
      return 0;}
    str++;}
  return 1;}
