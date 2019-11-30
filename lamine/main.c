#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct date{int j,m,a;}date;
bool bissextile(int a){
    if(a >= 1900 || a <= 2100){if(a % 4 == 0 || a % 400 == 0){return true;}else{if(a % 100 != 0)return false;};};};
int diff(date date1,date date2){
int i=0;
while((date1.j!=date2.j)||(date1.m!=date2.m)||(date1.a!=date2.a)){
switch(date1.m){
case 1:case 3:case 5:case 7: case 8:case 10: if(date1.j==31){date1.j=1; date1.m=date1.m+1;
i=i+1;

}else{date1.j=date1.j+1; i=i+1;
};break;
case 4: case 6:case 9:case 11:if(date1.j==30){date1.j=1; date1.m=date1.m+1;
i=i+1;

}else{date1.j=date1.j+1; i=i+1;
};break;
case 2: if (bissextile(date1.a)==true){
if(date1.j==29){date1.j=1; date1.m=date1.m+1;
i=i+1;
}else{date1.j=date1.j+1; i=i+1;}}
else{if(date1.j==28){date1.j=1; date1.m=date1.m+1;
i=i+1;
}else{date1.j=date1.j+1; i=i+1;}
};break;
case 12:
if(date1.j==31){date1.j=1; date1.m=1; date1.a=date1.a+1;
i=i+1;
}else{date1.j=date1.j+1; i=i+1;
};break;



};
}

return i;}
typedef struct horaire{int hr,mn;}horaire;
typedef struct Avion{
    char nom_vol[500];
    date Date_Arriver,Date_Depart;
    horaire Heure_Arriver,Heure_Depart;}Avion;
Avion cree(){int b=0,bis=0;Avion R;
    printf("Enter le nom de l'avion\n");gets(R.nom_vol);
    while(b==0){b=1;
    printf("Entrer la date d'atterissage\n");printf("jour:\n");scanf("%d",&R.Date_Arriver.j);
     printf("mois:\n");scanf("%d",&R.Date_Arriver.m);
      printf("annee:\n");scanf("%d",&R.Date_Arriver.a);
      if(R.Date_Arriver.a<0)b=0;
      if(R.Date_Arriver.m<1||R.Date_Arriver.m>12)b=0;
    if((R.Date_Arriver.a%4==0&&R.Date_Arriver.a!=100)||R.Date_Arriver.a%400==0)bis=1;
    switch(R.Date_Arriver.m){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:if(R.Date_Arriver.j<1||R.Date_Arriver.j>31)b=0;break;
        case 4:case 6:case 9:case 11 :if(R.Date_Arriver.j<1||R.Date_Arriver.j>30)b=0;break;
        case 2:{if(R.Date_Arriver.j<1||R.Date_Arriver.j>29)(b=0);if(bis==0&&R.Date_Arriver.j==29)b=0;break;}
}}b=0;
    while(b==0){b=1;
    printf("Entrer l'heure de conexion(format 24h)\n");
    printf("heure:\n");scanf("%d",&R.Heure_Arriver.hr);
    printf("minute:\n");scanf("%d",&R.Heure_Arriver.mn);if(R.Heure_Arriver.hr<0||R.Heure_Arriver.hr>23||R.Heure_Arriver.mn<0||R.Heure_Arriver.mn>59)b=0;}b=0;
    while(b==0){b=1;
   printf("Enter la date depart\n");printf("jour:\n");
    scanf("%d",&R.Date_Depart.j);printf("mois:\n");
     scanf("%d",&R.Date_Depart.m);printf("annee:\n");
      scanf("%d",&R.Date_Depart.a);
      if(R.Date_Depart.a<0)b=0;
      if(R.Date_Depart.m<1||R.Date_Depart.m>12)b=0;
    if((R.Date_Depart.a%4==0&&R.Date_Depart.a!=100)||R.Date_Depart.a==400)bis=1;
    switch(R.Date_Depart.m){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:if(R.Date_Depart.j<1||R.Date_Depart.j>31)b=0;break;
        case 4:case 6:case 9:case 11 :if(R.Date_Depart.j<1||R.Date_Depart.j>30)b=0;break;
        case 2:{if(R.Date_Depart.j<1||R.Date_Depart.j>29)(b=0);if(bis==0&&R.Date_Depart.j==29)b=0;break;}}}b=0;
        while(b==0){b=1;
    printf("Entrer l'heure de deconexion(format 24h)\n");
    printf("heure:\n");
    scanf("%d",&R.Heure_Depart.hr);
    printf("minute:\n");
    scanf("%d",&R.Heure_Depart.mn);
    if(R.Heure_Depart.hr<0||R.Heure_Depart.hr>23||R.Heure_Depart.mn<0||R.Heure_Depart.mn>59)b=0;}b=0;
    return R;
}
horaire incre (horaire T1,int k){int i;
for(i=1;i<=k;i++){
        T1.mn=T1.mn+1;
if(T1.mn==60){
        T1.mn=0;T1.hr=T1.hr+1;}if(T1.hr==24){T1.hr=0;T1.mn=0;}
}return T1;}
bool egal(horaire a,horaire b){
bool j=false,i=false;
if(a.hr==b.hr){j=true;}
if(a.mn==b.mn){i=true;}
if((i==true)&&(j==true))return true;
 else return false;
}
int main()
{   int T,J,M=6,L,K,O,i,p,l;L=0;K=0;O=0;l=0;horaire H,C,D,F;
C.hr=5;C.mn=0;D.hr=20;D.mn=0;F.hr=0;F.mn=0;
Avion A;A=cree();H=A.Heure_Arriver;J=diff(A.Date_Arriver,A.Date_Depart);T=0;i=0;p=0;
while((!(egal(H,A.Heure_Depart))||(i<J))&&l<=90){H=incre(H,1);if(egal(H,F)){i=i+1;};l=l+1;}
if(l>90){H=incre(A.Heure_Arriver,90);J=diff(A.Date_Arriver,A.Date_Depart);
while(!(egal(H,A.Heure_Depart))||(i<J)){H=incre(H,1);p=p+1;
        if(egal(H,C)){L=L+p;p=0;}
        if(egal(H,D)){K=K+p;p=0;}
        if(egal(H,F)){O=O+p;p=0;}
        if(egal(H,F)){i=i+1;}}
       while(p!=0){H=incre(H,1);
        if(egal(H,C)){L=L+p;p=0;}
        if(egal(H,D)){K=K+p;p=0;}
        if(egal(H,F)){O=O+p;p=0;}
        if(egal(H,F)){i=i+1;}}}
    printf("%d\n%d\n%d",L,K,O);/* L K O sont les conteur de minute dans chaque interval*/




}


