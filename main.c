#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct komsuil{
    int plaka;
    struct komsuil *next;
}komsuil;

typedef struct il{
    int komsuadet;
	int plaka;
	char iladi[20];
	char bolgeadi[2];
	struct il* next;
	struct komsuil *komsular;
}il;

il *basnode = NULL;
komsuil * komsubas = NULL;



void yazdir()
{
	 FILE *ad;
    ad = fopen("output.txt", "w");
    if(ad!=NULL){
    il * iter6 = basnode;

   while(iter6->next != NULL){
     komsuil * iter7 =iter6->komsular ;
          fprintf(ad,"%s ,%d ,%s ,%d ---> ",iter6->iladi,iter6->plaka,iter6->bolgeadi,iter6->komsuadet);
         while(iter7->next != NULL){

           fprintf(ad,"%d-",iter7->plaka);
         iter7=iter7->next;
        }
         fprintf(ad,"%d",iter7->plaka);
         fputs("\n  |\n",ad);
       iter6=iter6->next;
     }
     fprintf(ad,"%s ,%d ,%s ,%d ---> ",iter6->iladi,iter6->plaka,iter6->bolgeadi,iter6->komsuadet);
      komsuil * iter7 =iter6->komsular ;
         while(iter7->next != NULL){

           fprintf(ad,"%d-",iter7->plaka);
         iter7=iter7->next;
        }
         fprintf(ad,"%d",iter7->plaka);
         fclose(ad);
    }
    else
        printf("Yazdirmak icin dosya olusturamadik \n\n");

    printf("Yazdirma islemi basariyla gerceklesti \n\n");
}


il isimbul(char iladi [20])
{
	il *iter = basnode;
	while(iter!=NULL){
		if(strcmp(iladi,iter->iladi) == 0){
				printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);
			return * iter;
		}
		iter = iter->next;
	}
	printf("Bu isimde bir sehir yok eklemek ister misiniz...\n1-Ekle \n2-Ana menu ");

       int secim=0;
                char ada[2];
                char ili[20];
                int pla;
       scanf("%d",&secim);
          fflush(stdin);
            switch(secim)
           {
         case 1:

              printf("Eklemek istediginiz ilin bolgesini giriniz.\n"); scanf("%s",&ada);

              printf("Eklemek istediginiz ilin adini giriniz.\n"); scanf("%s",&ili);

              printf("Eklemek istediginiz ilin plakasini giriniz.\n"); scanf("%d",&pla);



               il *yeniil;
            il *ara;
           yeniil = (il*)malloc(sizeof(il));
           komsuil *kom;
           kom = (komsuil*)malloc(sizeof(komsuil));
kom->plaka=0;
kom->next=NULL;
            yeniil->plaka = pla;
            strcpy(yeniil->iladi,ili);
            strcpy(yeniil->bolgeadi,ada);
            yeniil->komsuadet =0;

            yeniil->komsular=kom;

            yeniil->next = NULL;
            ara = basnode;



        while(ara->next != NULL)
            ara = ara->next;

        ara->next= yeniil;




             break;

         case 2:

               printf("\n\n   Ana menu \n\n");


             break;
           }
}

il plakabul(int plaka)
{
	il * iter = basnode;
	while(iter!=NULL)
	{
		if(plaka == iter->plaka ){

	            printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);
			return * iter;
		}
		iter = iter->next;
	}
	printf("Bu isimde bir sehir yok eklemek ister misiniz...\n1-Ekle \n2-Ana menu ");

       int secim=0;
                char ada[2];
                char ili[20];
                int pla;
       scanf("%d",&secim);
          fflush(stdin);
            switch(secim)
           {
         case 1:

              printf("Eklemek istediginiz ilin bolgesini giriniz.\n"); scanf("%s",&ada);

              printf("Eklemek istediginiz ilin adini giriniz.\n"); scanf("%s",&ili);

              printf("Eklemek istediginiz ilin plakasini giriniz.\n"); scanf("%d",&pla);



               il *yeniil;
            il *ara;
           yeniil = (il*)malloc(sizeof(il));
           komsuil *kom;
           kom = (komsuil*)malloc(sizeof(komsuil));
kom->plaka=0;
kom->next=NULL;
            yeniil->plaka = pla;
            strcpy(yeniil->iladi,ili);
            strcpy(yeniil->bolgeadi,ada);
            yeniil->komsuadet =0;

            yeniil->komsular=kom;

            yeniil->next = NULL;
            ara = basnode;



        while(ara->next != NULL)
            ara = ara->next;

        ara->next= yeniil;




             break;

         case 2:

               printf("\n\n   Ana menu \n\n");


             break;
           }

}

void esitkomsu(int komsuadet)
{
	il * iter = basnode;
	while(iter!=NULL)
	{
		if(iter->komsuadet == komsuadet){
			    printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);
		}
		iter = iter->next;
	}
}
void kucukkomsu(int komsuadet)
{
	il * iter = basnode;
	while(iter!=NULL)
	{
		if(iter->komsuadet < komsuadet){
                printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);
		}
		iter = iter->next;
	}
}

void bolgeyazdir(char bolgeadi[2])
{
	il * iter = basnode;
	while(iter!=NULL)
	{
		if(strcmp(iter->bolgeadi,bolgeadi) == 0){
		        printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);
		}
		iter = iter->next;
	}
}

void buyukkomsular(int komsuadet)
{
	il * iter = basnode;
	while(iter!=NULL)
	{
		if(iter->komsuadet > komsuadet){
		        printf("%d,", iter->plaka);
				printf("%s,", iter->iladi);
				printf("%s,", iter->bolgeadi);
				printf("%d\n\n",iter->komsuadet);

		}
		iter = iter->next;
	}
}


int main()
{

    FILE *dosya;
    dosya = fopen("sehirler.txt", "r");


    char satir[100];


      if(dosya!=NULL){


        while(!feof(dosya)){


          char * k1;
          fscanf(dosya,"%s",&satir);
          k1 = strtok (satir,",");
          il mobil;
          mobil.plaka=atoi(k1);
          k1 = strtok (NULL, ",");
          strcpy(mobil.iladi,k1);
          k1 = strtok (NULL, ",");
          strcpy(mobil.bolgeadi,k1);


           int i=0;
           while (k1 != NULL)
		    {

		    	++i;

		        k1= strtok (NULL, ",");
		    }

          mobil.komsuadet=(i-1);


           il *yeniil;
            il *ara;
           yeniil = (il*)malloc(sizeof(il));

            strcpy(yeniil->iladi,mobil.iladi);
            yeniil->plaka = mobil.plaka;
            strcpy(yeniil->bolgeadi,mobil.bolgeadi);
            yeniil->komsuadet = mobil.komsuadet;
            yeniil->komsular= NULL;
            yeniil->next = NULL;
            ara = basnode;

        if(ara == NULL)
        {
        	ara = yeniil;
        	basnode = ara;

        }else {


        while(ara->next != NULL)
            ara = ara->next;

        ara->next= yeniil;

        }

    }

      }

      else{
            printf("Sehirler.txt ye ulasamadýk...");
    }
    fclose(dosya);
      FILE *dosya2;
    dosya2 = fopen("sehirler.txt", "r");

      while(!feof(dosya2)){

          komsuil * komsubas = NULL;
           char * k2;
          fscanf(dosya,"%s",&satir);


          k2 = strtok (satir,",");
          k2 = strtok (NULL, ",");
          k2 = strtok (NULL, ",");
          k2= strtok (NULL, ",");
       char *k3 = strtok (NULL, ",");
       char *k4 = strtok (NULL, ",");
       char *k5 = strtok (NULL, ",");
       char *k6 = strtok (NULL, ",");
       char *k7 = strtok (NULL, ",");
       char *k8 = strtok (NULL, ",");
       char *k9 = strtok (NULL, ",");
       char *k10 = strtok (NULL, ",");
       char *k11 = strtok (NULL, ",");
       char *k12 = strtok (NULL, ",");




                 il * iter = basnode;
                 while(iter!=NULL){


 if( k2!=NULL &&  strcmp(iter->iladi,k2) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k3!=NULL &&  strcmp(iter->iladi,k3) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k4!=NULL &&  strcmp(iter->iladi,k4) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k5!=NULL &&  strcmp(iter->iladi,k5) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k6!=NULL &&  strcmp(iter->iladi,k6) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k7!=NULL &&  strcmp(iter->iladi,k7) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k8!=NULL &&  strcmp(iter->iladi,k8) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k9!=NULL &&  strcmp(iter->iladi,k9) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k10!=NULL &&  strcmp(iter->iladi,k10) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k11!=NULL &&  strcmp(iter->iladi,k11) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }
 if( k12!=NULL &&  strcmp(iter->iladi,k12) == 0){

                         komsuil * mobilk, *arak;
                         mobilk = (komsuil*)malloc(sizeof(komsuil));
                         mobilk->plaka =iter->plaka;
                         mobilk->next=NULL;

                               arak =komsubas ;

        if(arak == NULL)
        {
        	arak = mobilk;
        	komsubas = arak;

        }else {


        while(arak->next != NULL)
            arak = arak->next;

        arak->next= mobilk;

        }


		               }


		iter = iter->next;
	}
      il * iter2 = basnode;

      while(iter2 != NULL){
        if(iter2->komsular==NULL){
            iter2->komsular=komsubas;
            break;
        }




        iter2 = iter2->next;
      }







      }
   fclose(dosya2);








             int secim=3;

         char iliniz[20];
          int k;
           char kaa[2];
        while(secim != 0)
         {
             printf("1-Sehir ismine gore sehir aramasi  \n2-Sehir plakasina gore sehir aramasi\n");
             printf("3-Gireceginiz sayisida komsusu olalar  \n4-Gireceginiz sayisidan fazla komsusu olalar \n");
             printf("5-Gireceginiz sayisidan az komsusu olalar  \n6-Gireceginiz bolgedeki olalar \n");
             printf("7-Sehirlerin duzenini .txt olarak yazdir \n0-Cikis\n");
             printf("\n     Secim Giriniz    \n");

             scanf("%d",&secim);
            switch(secim)
           {
         case 1:

              printf("Aramak istediginiz ilin adini giriniz.\n"); scanf("%s",&iliniz);
              il bulunani = isimbul(iliniz);

             break;

         case 2:

               printf("Aramak istediginiz ilin plaka kodunu giriniz.\n"); scanf("%d",&k);
               il bulunp= plakabul( k );

             break;

         case 3:

               printf("Komsu sayisi giriniz.\n"); scanf("%d",&k);
               esitkomsu( k );
             break;
         case 4:

               printf("Komsu sayisi giriniz.\n"); scanf("%d",&k);
               buyukkomsular( k );
             break;
         case 5:

               printf("Komsu sayisi giriniz.\n"); scanf("%d",&k);
               kucukkomsu( k );
             break;
         case 6:

              printf("Aramak istediðiniz ilin adini giriniz (AK)(GA)(EG)(DA)(KA)(IA)(MA).\n"); scanf("%s",&kaa);
              bolgeyazdir( kaa );
             break;
         case 7:

              yazdir();

             break;


           }
         }



    return 0;
}
