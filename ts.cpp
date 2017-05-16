#include <stdio.h>


//prototipyi functsiy
int ZastBeg();
void ViewDB();
void CreateDB();
void AddToDB();
void SearchInDB();
void SortDB();
int Exit();
void ZastEnd();
int Get(int min, int max);


struct record
{
int num;
char surn[15];
char name[12];
char otch[17];
char ul[20];
int dom;
int kv;
int tel;
int ats;
};


//------------------------------------------MENU-------------------------------


int Menu()
{
clrscr();
printf("*Menu*");
printf("\n-> Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
int p = 1;
int m = getch();
if(m == 13) ViewDB();

do{
if(m == 80) p++;
if(m == 72) p--;

do{
if(p<=0) p = p+6;
}while (p<=0);
do{
if(p>=7) p = p-6;
}while (p>=7);

if(p == 1){
clrscr();
printf("*Menu*");
printf("\n-> Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
if(p == 2){
clrscr();
printf("*Menu*");
printf("\n Prosmotr bazi dannih");
printf("\n-> Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
if(p == 3){
clrscr();
printf("*Menu*");
printf("\n Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n-> Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
if(p == 4){
clrscr();
printf("*Menu*");
printf("\n Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n-> Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
if(p == 5){
clrscr();
printf("*Menu*");
printf("\n Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n-> Sortirovka bazi dannih");
printf("\n Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
if(p == 6){
clrscr();
printf("*Menu*");
printf("\n Prosmotr bazi dannih");
printf("\n Sozdanie bazi dannih");
printf("\n Dobavlenie zapisi v bazu dannih");
printf("\n Poisk zapisi po kluchu");
printf("\n Sortirovka bazi dannih");
printf("\n-> Vihod iz programmi");
printf("\n\n\nPeremeschenie - strelki vverh i vniz");
printf("\nVibor punkta menu - <Enter>");
m = getch();
}
}while(m!=13);
return p;
}


//---------------------------------------ZAST_BEG------------------------------


int ZastBeg()
{
printf("\n\n Programma 'Telefonniy spravochnik'");
printf("\n Avtor: top_secret_information =)");
printf("\n\n\n\n <Esc> - vihod, prodolzhit' - lubaya drugaya klavisha");
int c = getch();
return c;
}


//--------------------------------------ZAST_END-------------------------------


void ZastEnd()
{
clrscr();
printf("\n\n Programma 'Telefonniy spravochnik'");
printf("\n Uspeshno zavershena. Blagodaru za eyo ispol'zovanie");
printf("\n\n\n\n Nazhmite lubuju klavishu dlja vihoda v OS");
getch();
}


//---------------------------------------EXIT----------------------------------


int Exit()
{
clrscr();
printf("\n\n Deistvitel'no viyti iz programmi?");
printf("\n\n <Enter> - viyti v OS, <Esc> - prodolzhit' rabotu s programmoj");
int c;
do
{
c = getch();
}while(c != 13 && c != 27);
return c;
}


//---------------------------------------MAIN----------------------------------


int main()
{
if(ZastBeg() != 27)
{
int z;

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
else break;
}
}while(z == 1);
}

else ZastEnd();
return 0;
}


//---------------------------------------VIEWDB--------------------------------


void ViewDB()
{
FILE *f=fopen("db.txt", "rb");
FILE *num=fopen("num.txt", "rb");

if(f == NULL || num == NULL)
{
clrscr();
printf("\nNe udayotsja otkrit' fail bazyi dannih");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
}

else
{
struct record recz[100];

int i, kol;

//poluchenie kol-va zapisej
fread((int*)&kol, 1, sizeof(kol), num);

//zapolnenie massiva zapisjami iz faila
for(i=0;i<kol;i++)
{
fseek(f, sizeof(recz[i])*i, 0);
fread((char*)&recz[i], 1, sizeof(recz[i]), f);
}

//prosmotr zapisej iz poluchennogo massiva
int a, k = 0;

do
{
clrscr();
printf("*Prosmotr bazi dannih*");
printf("\n\nZapis' #%i", recz[k].num);
printf("\nFIO -> %s %s %s", recz[k].surn, recz[k].name, recz[k].otch);
printf("\nAdres -> ul.%s, d.%i, kv.%i", recz[k].ul, recz[k].dom, recz[k].kv);
printf("\nNomer telefona -> %i", recz[k].tel);
printf("\nATS -> %i", recz[k].ats);


if(kol == 1) //v baze vsego 1 zapis'
{
printf("\n\nBol'she zapisej ne naideno");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
k = 101;
}

else
{
if(k == 0)
{
printf("\n\nStrelka vniz - sled. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 80 && a != 27);
if(a == 80) k++;
else k = 101;
}

else
{
if(k == kol - 1)
{
printf("\n\nStrelka vverh - pred. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 27);
if(a == 72) k--;
else k = 101;
}

else
{
if(k > 0 && k < kol)
{
printf("\n\nStrelki vverh/vniz - listanie po zapisyam: pred/sled");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 80 && a != 27);
if(a == 80) k++;
if(a == 72) k--;
if(a == 27) k = 101;
}
}
}
}
}while(k != 101);
}

fclose(f);
fclose(num);

int z;

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
else break;
}
}while(z == 1);

ZastEnd();
}


//--------------------------------------CREATEDB-------------------------------


void CreateDB()
{
clrscr();
printf("Vyi deistvitel'no hotite sozdat' novuju bazu dannih?");
printf("\n<Enter> - da, <Esc> - net");
int d;
do
{
d = getch();
}while(d != 13 && d != 27);

if(d == 13)
{
FILE *f=fopen("db.txt", "wb");
FILE *num=fopen("num.txt", "wb");

struct record rec[100];

int i, j;

for(i = 0; i < 100; i++)
{
clrscr();
printf("*Sozdanie bazi dannih*\n\n");
rec[i].num = i+1;


//podtverzhdenniy vvod familii

printf("\nFamilija (do 15 simvolov) -> ");
fscanf(stdin, "%s", &rec[i].surn);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli familiju: '%s'. <Esc> - povtorniy vvod. ", rec[i].surn);
printf("\n<Enter> - familija vvedena verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &rec[i].surn);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy vvod imeni

printf("\n\nImya (do 12 simvolov) -> ");
fscanf(stdin, "%s", &rec[i].name);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli imya: '%s'. <Esc> - povtorniy vvod. ", rec[i].name);
printf("\n<Enter> - imya vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &rec[i].name);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy vvod otchestva

printf("\n\nOtchestvo (do 17 simvolov) -> ");
fscanf(stdin, "%s", &rec[i].otch);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli otchestvo: '%s'. <Esc> - povtorniy vvod. ", rec[i].otch);
printf("\n<Enter> - otchestvo vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &rec[i].otch);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy vvod nazvanija ulitsyi

printf("\n\nAdres: ulitsa (do 20 simvolov) -> ");
fscanf(stdin, "%s", &rec[i].ul);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli ulitsu: '%s'. <Esc> - povtorniy vvod. ", rec[i].ul);
printf("\n<Enter> - nazvanie ulitsi vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &rec[i].ul);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera doma

printf("\n\nAdres: #doma (do 3 znakov) -> ");
rec[i].dom = Get(1, 999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #doma: '%d'. <Esc> - povtorniy vvod. ", rec[i].dom);
printf("\n<Enter> - nomer doma vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
rec[i].dom = Get(1, 999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera doma

printf("\n\nAdres: #kvartiryi (do 3 znakov)-> ");
rec[i].kv = Get(1, 999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #kvartiri: '%d'. <Esc> - povtorniy vvod. ", rec[i].kv);
printf("\n<Enter> - nomer kvartiri vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
rec[i].kv = Get(1, 999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera telefona

printf("\n\nTel. nomer (do 7 znakov) -> ");
rec[i].tel = Get(1, 9999999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #telefona: '%d'. <Esc> - povtorniy vvod. ", rec[i].tel);
printf("\n<Enter> - nomer telefona vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
rec[i].tel = Get(1, 9999999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera ats

printf("\n\nNomer ATS (tseloe chislo ot 1 do 9) -> ");
rec[i].ats = Get(1, 9);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #ATS: '%d'. <Esc> - povtorniy vvod. ", rec[i].ats);
printf("\n<Enter> - nomer ATS vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
rec[i].ats = Get(1, 999);
}
}while(j == 27);


fwrite((char*)&rec[i], 1, sizeof(rec[i]), f);
printf("\n\n<Enter> - prodolzhit', <Esc> - vihod v menu\n");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j == 27)
{
int kol = i + 1;
fwrite((int*)&kol, 1, sizeof(kol), num);
break;
}
}
clrscr();
fclose(f);
fclose(num);
}

int z;

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
else break;
}
}while(z == 1);

ZastEnd();
}


//--------------------------------------ADDTODB--------------------------------


void AddToDB()
{
clrscr();
printf("Vyi deistvitel'no hotite dobavit' novuju zapis' v bazu dannyih?");
printf("\n<Enter> - da, <Esc> - net");
int d, z;
do
{
d = getch();
}while(d != 13 && d != 27);

if(d == 13)
{
FILE *f=fopen("db.txt", "ab");
FILE *num=fopen("num.txt", "r+b");

int c;

if(num == NULL)
{
fclose(f); //
clrscr();
printf("\nBaza dannih ne suschestvuet");
printf("\n<Esc> - sozdanie bazi dannih, <Enter> - vihod v menu");
do
{
c = getch();
}while(c != 13 && c != 27);

if(c == 27) CreateDB();
}

//esli file s bazoj naiden
else
{
int kol;

fread((int*)&kol, 1, sizeof(kol), num);

if(kol == 100)
{
printf("Baza dannih zapolnena. Dobavlenie zapisi nevozmozhno.");
printf("Nazhmite lubuju klavishu dlja vihoda v menu");
getch();

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
}
}while(z == 1);

ZastEnd();
}


struct record newrec;

int j;

clrscr();
printf("*Dobavlenie zapisi v bazu dannyih*\n\n");
newrec.num = kol + 1;

//podtverzhdenniy vvod familii

printf("\nFamilija (do 15 simvolov) -> ");
fscanf(stdin, "%s", &newrec.surn);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli familiju: '%s'. <Esc> - povtorniy vvod. ", newrec.surn);
printf("\n<Enter> - familija vvedena verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &newrec.surn);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy vvod imeni

printf("\n\nImya (do 12 simvolov) -> ");
fscanf(stdin, "%s", &newrec.name);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli imya: '%s'. <Esc> - povtorniy vvod. ", newrec.name);
printf("\n<Enter> - imya vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &newrec.name);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy vvod otchestva

printf("\n\nOtchestvo (do 17 simvolov) -> ");
fscanf(stdin, "%s", &newrec.otch);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli otchestvo: '%s'. <Esc> - povtorniy vvod. ", newrec.otch);
printf("\n<Enter> - otchestvo vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &newrec.otch);
fflush(stdin);
}
}while(j == 27);

//podtverzhdenniy vvod nazvanija ulitsyi

printf("\n\nAdres: ulitsa (do 20 simvolov) -> ");
fscanf(stdin, "%s", &newrec.ul);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli ulitsu: '%s'. <Esc> - povtorniy vvod. ", newrec.ul);
printf("\n<Enter> - nazvanie ulitsi vvedeno verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
fscanf(stdin, "%s", &newrec.ul);
fflush(stdin);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera doma

printf("\n\nAdres: #doma (do 3 znakov) -> ");
newrec.dom = Get(1, 999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #doma: '%d'. <Esc> - povtorniy vvod. ", newrec.dom);
printf("\n<Enter> - nomer doma vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
newrec.dom = Get(1, 999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera doma

printf("\n\nAdres: #kvartiryi (do 3 znakov)-> ");
newrec.kv = Get(1, 999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #kvartiri: '%d'. <Esc> - povtorniy vvod. ", newrec.kv);
printf("\n<Enter> - nomer kvartiri vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
newrec.kv = Get(1, 999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera telefona

printf("\n\nTel. nomer (do 7 znakov) -> ");
newrec.tel = Get(1, 9999999);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #telefona: '%d'. <Esc> - povtorniy vvod. ", newrec.tel);
printf("\n<Enter> - nomer telefona vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
newrec.tel = Get(1, 9999999);
}
}while(j == 27);


//podtverzhdenniy kontrolliruemiy vvod nomera ats

printf("\n\nNomer ATS (tseloe chislo ot 1 do 9) -> ");
newrec.ats = Get(1, 9);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #ATS: '%d'. <Esc> - povtorniy vvod. ", newrec.ats);
printf("\n<Enter> - nomer ATS vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
newrec.ats = Get(1, 9);
}
}while(j == 27);

fwrite((char*)&newrec, 1, sizeof(newrec), f);

kol++;

fseek(num, 0, 0);
fwrite((int*)&kol, 1, sizeof(kol), num);

fclose(f);
fclose(num);

printf("\n\nZapis' dobavlena");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
}
}

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
else break;
}
}while(z == 1);

ZastEnd();
}


//-----------------------------------SEARCHINDB--------------------------------


void SearchInDB()
{
FILE *f=fopen("db.txt", "rb");
FILE *num=fopen("num.txt", "rb");

int j, o;

if(f == NULL || num == NULL)
{
clrscr();
printf("\nNe udayotsja otkrit' fail bazyi dannyih");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
}

else
{
struct record recz[100];

int i, kol;

fread((int*)&kol, 1, sizeof(kol), num);

//zapolnenie massiva zapisjami iz faila
for(i=0;i<kol;i++)
{
fseek(f, sizeof(recz[i])*i, 0);
fread((char*)&recz[i], 1, sizeof(recz[i]), f);
}

clrscr();
printf("*Poisk zapisej po nomeru ATS*");

int sats; //kluch dlja poiska

printf("\n\nVvedite nomer ATS dlja poiska (tseloe chislo ot 1 do 9)-> ");
sats = Get(1, 9);
gotoxy(1,wherey()+1);
do
{
gotoxy(1,wherey()-2);
printf("Vyi vveli #ATS: '%i'. <Esc> - povtorniy vvod. ", sats);
printf("\n<Enter> - nomer ATS vveden verno. ");
do
{
j = getch();
}while(j != 13 && j != 27);
if(j != 13)
{
printf("\nVvedite zanovo ->");
sats = Get(1, 9);
}
}while(j == 27);

struct record srec[100];
int z, s = 0;

for(z=0;z<kol;z++)
{
if(recz[z].ats == sats)
{
srec[s] = recz[z];
s++;
}
}

if(s == 0) //esli ne naideno ni odnoj zapisi
{
clrscr();
printf("Zapisej s takim nomerom ATS ne naideno");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
}



else
{
int a;

i = 0;

do
{
clrscr();
printf("*Poisk zapisej s nomerom ATS = %i*", sats);
printf("\n\nZapis' #%i", srec[i].num);
printf("\nFIO -> %s %s %s", srec[i].surn, srec[i].name, srec[i].otch);
printf("\nAdres -> ul.%s, d.%i, kv.%i", srec[i].ul, srec[i].dom, srec[i].kv);
printf("\nNomer telefona -> %i", srec[i].tel);
printf("\nATS -> %i", srec[i].ats);

if(s == 1) //esli vsego odna zapis' sootvetstvuet usloviju poiska
{
printf("\n\nBol'she zapisej ne naideno");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
i = 101;
}

if(i == 0)
{
printf("\n\nStrelka vniz - sled. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 80 && a != 27);
if(a == 80) i++;
else i = 101;
}

else
{
if(i == s - 1)
{
printf("\n\nStrelka vverh - pred. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 27);
if(a == 72) i--;
else i = 101;
}

else
{
if(i > 0 && i < s)
{
printf("\n\nStrelki vverh/vniz - listanie po zapisyam: pred/sled");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 80 && a != 27);
if(a == 80) i++;
if(a == 72) i--;
if(a == 27) i = 101;
}
}
}

}while(i != 101);

fclose(f);
fclose(num);
}
}


do
{
o = 0;
int o = Menu();
switch(o)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
o = 1;
break;
}
}
}while(o == 1);

ZastEnd();
}


//-------------------------------------SORTDB----------------------------------


void SortDB()
{
FILE *f=fopen("db.txt", "rb");
FILE *num=fopen("num.txt", "rb");

int z;

if(f == NULL || num == NULL)
{
clrscr();
printf("\nNe udayotsja otkrit' fail bazi dannih");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
}

else
{
struct record recz[100];

int i, kol;

fread((int*)&kol, 1, sizeof(kol), num);

//zapolnenie massiva zapisjami iz faila
for(i=0;i<kol;i++)
{
fseek(f, sizeof(recz[i])*i, 0);
fread((char*)&recz[i], 1, sizeof(recz[i]), f);
}

int nums[100], atss[100];

for(i=0;i<kol;i++) //sozdanie massiva s nomerami ats iz bazi dannih
{
atss[i] = recz[i].ats;
}

for(i=0;i<kol;i++)
{
nums[i] = recz[i].num;
}

int j, n, tmp, ch = 0;

//sortirovka massiva s nomerami ats i sootv. peremeschenie nomerov zapisej
for(i=0;i<kol;i++)
{
n = i;
for(j=i+1;j<kol;j++)
{
if(atss[j] < atss[n])
{
n = j; //n - nomer min elementa
ch++; //ch - chislo naidennuih zapisej
}
}

tmp = atss[i];
atss[i] = atss[n];
atss[n] = tmp;

tmp = nums[i];
nums[i] = nums[n];
nums[n] = tmp;
}

int a, k = 0;

do
{
n = nums[k]-1;
clrscr();
printf("*Otsortirovannaja baza dannih*");
printf("\n\nZapis' #%i", recz[n].num);
printf("\nFIO -> %s %s %s", recz[n].surn, recz[n].name, recz[n].otch);
printf("\nAdres -> ul.%s, d.%i, kv.%i", recz[n].ul, recz[n].dom, recz[n].kv);
printf("\nNomer telefona -> %i", recz[n].tel);
printf("\nATS -> %i", recz[n].ats);


if(ch == 1) //esli vsego odna zapis' sootvetstvuet usloviju poiska
{
printf("\n\nBol'she zapisej ne naideno");
printf("\nNazhmite lubuju klavishu dlja vihoda v menu");
getch();
k = 101;
}


else
{
if(k == 0)
{
printf("\n\nStrelka vniz - sled. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 80 && a != 27);
if(a == 80) k++;
else k = 101;
}

else
{
if(k == kol - 1)
{
printf("\n\nStrelka vverh - pred. zapis' ");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 27);
if(a == 72) k--;
else k = 101;
}

else
{
if(k > 0 && k < kol)
{
printf("\n\nStrelki vverh/vniz - listanie po zapisyam: pred/sled");
printf("\n<Esc> - vihod v menu");
do
{
a = getch();
}while(a != 72 && a != 80 && a != 27);
if(a == 80) k++;
if(a == 72) k--;
if(a == 27) k = 101;
}
}
}
}
}while(k != 101);
}

fclose(f);
fclose(num);

do
{
z = 0;
int p = Menu();
switch(p)
{
case 1: ViewDB(); break;
case 2: CreateDB(); break;
case 3: AddToDB(); break;
case 4: SearchInDB(); break;
case 5: SortDB(); break;
case 6:
if(Exit() == 27)
{
z = 1;
break;
}
}
}while(z == 1);

ZastEnd();
}


//-------------------------------------GET-------------------------------------


int Get(int min, int max)
{
int i = 0;

fscanf(stdin, "%d", &i);
fflush(stdin);

while ((i==0)||(i>max)||(i<min))
{
gotoxy(1,wherey());
cprintf("Neverniy vvod, povtorite popitku (%d - %d): ", min,max);
fscanf(stdin, "%d", &i);
fflush(stdin);
}
return i;
}
