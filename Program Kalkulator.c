#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>



int main() 
{ 
  int pilihan;
  char ch_x[5][100] ={"1.Menampilkan IP Address dari komputer anda","2.Kalkulator untuk IP Address","3.Hapus Data","4.Mengenai Program","5.Exit"};
  int argc;
  int SubnetMask;
  void loader();
  system("COLOR 2F");
	{
	loader ();
	system("cls");
	printf("\n");
	printf("\n");
	int x;
	FILE *file;
	file = fopen("judul.txt", "r");
	if (file) {
    while ((x = getc(file)) != EOF)
        putchar(x);
    fclose(file);
	printf("\n");
	printf("\n\n						Loading Completed");
	Sleep(1000);
	system("cls");
	goto menu;
	}
	menu:

	
	system ("cls");
	int position = 1;
	int keyPressed = 0;
	
	#define MAX 5
	#define MIN 1
	
	while (keyPressed !=13){
	system ("cls");
	printf("\t=======================================================================\n");
  printf("\t================ Simple IP Subnet Calculator By Lunnardo and Leonardus ================\n");
  printf("\t=======================================================================\n\n");
	arrowHere (1,position); printf ("%s", ch_x[0]);
	arrowHere (2,position); printf ("%s", ch_x[1]);
	arrowHere (3,position); printf ("%s", ch_x[2]);
	arrowHere (4,position); printf ("%s", ch_x[3]);
	arrowHere (5,position); printf ("%s", ch_x[4]);
	
	keyPressed = getch ();
	if (keyPressed == 80 && position != MAX ){
		position++;	
	}
	else if (keyPressed == 72 && position != MIN){
		position--;
	}
	else if (keyPressed == 80 && position != 4){
		position = 1;
	}
	else if (keyPressed == 72 && position != 0){
		position = 5;
	}
	else {
		position == position;
	}
}
switch (position){
case 1 : IP(); break;
case 2 : menghitung(); break;
case 3 : Hapus(); break;
case 4 : Bantuan(); break;
case 5 : Exit(); break;

}
return 0;
}
}

void arrowHere (int realposition, int arrowposition){
	
			if (realposition == arrowposition){
				printf ("\n\n----->>>");
			}
			else {
				printf ("\n\n\t");
			}
}


void loader()
{
	int i, x;
	system("cls");
	printf("\n");
	printf("\n");
	FILE *file;
	file = fopen("judul.txt", "r");
	if (file) {
    while ((x = getc(file)) != EOF)
        putchar(x);
    fclose(file);
}
	printf("\n");
	printf("\n						Please Wait Loading....\n");
	printf("						");
	for (i=0; i<25; i++){
		Sleep(50);
		printf("%c", 219);
		
	}
} 

int IP(){
	int pilihanip;
	int menu;
	FILE *out=fopen("Data.csv","a");
    fprintf(out,"IP Address,subnet,host,blocksize\n");
    fclose(out);
    system("cls");
    system("c:\\windows\\system32\\ipconfig"); 
    system("pause");
    system("cls");
	Exit ();
	return (0);
}



int menghitung(int argc, int SubnetMask) {
    int a;
    int IP1, IP2, IP3, IP4, CIDR, bitborrowed, bitremained, subnet, host, mask, blocksize;
    int x[]={IP1,IP2,IP3,IP4};
    char class;
    FILE *fptr;
	FILE *out=fopen("Data.csv","a");
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("| Tolong masukkan IP Address dengan format \"0.0.0.0\": |\n");
    printf("-----------------------------------------------------\n");
    scanf("%i.%i.%i.%i", &IP1, &IP2, &IP3, &IP4);
    system("cls");

    do
    {
        if((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0))
        {
            printf("------------------------------------------------------------\n");
            printf("| Perhatian!! IP Address invalid, tolong masukkan IP Address yang valid: |\n");
            printf("------------------------------------------------------------\n");
            scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
        }
    }while((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0));

            printf("---------------------------------------------\n");
            printf("| Masukkan CIDR dalam format decimal CIDR: |\n");
            printf("---------------------------------------------\n");
            scanf("%d", &CIDR);
        do{

            if(CIDR > 32 || CIDR == 0)
            {
                printf("--------------------------------------------\n");
                printf("| CIDR salah, tolong masukkan CIDR yang benar: |\n");
                printf("--------------------------------------------\n\n");
                scanf("%d", &CIDR);
            }
        }while(CIDR > 32);
         
    if(IP1 <=170) {
        class = 'A';
    }else if(IP1 <=190) {
        class = 'B';
    }else {
        class = 'C';
    }
    
    switch (class) {
        case 'A':
            if(CIDR >= 8) {
                bitborrowed = CIDR - 8; 
            }else {
                bitborrowed = 8 - CIDR;
            }
            break;
        case 'B':
            if(CIDR >= 16) {
                bitborrowed = CIDR - 16;
            }else {
                bitborrowed = 16 - CIDR;
            }
            break;
        case 'C':
            if(CIDR >= 24) {
                bitborrowed = CIDR - 24;
            }else {
                bitborrowed = 24 -CIDR;
            }
    }
    
    switch (class) {
        case 'A':
            bitremained = 32 - CIDR;
            break;
        case 'B':
            bitremained = 32 -CIDR;
            break;
        case 'C':
            bitremained = 32 -CIDR;
            break;
    }
    
    subnet = pow(2,bitborrowed);
    
    host = pow(2, bitremained)-2;
    
    switch(bitborrowed) {
        case 1:
            blocksize = 128;
            break;
        case 2:
            blocksize = 64;
            break;
        case 3:
            blocksize = 32;
            break;
        case 4:
            blocksize = 16;
            break;
        case 5:
            blocksize = 8;
            break;
        case 6:
            blocksize = 4;
            break;
        case 7:
            blocksize = 2;
            break;
        case 8:
            blocksize = 1;
            break;
    }
    system("cls");

    printf("=====================================================\n");
    printf("=============== Berikut hasil dari perhitungan kami: ================\n");
    printf("=====================================================\n\n");
    printf("---------------------------------------\n");
    printf("IP anda adalah %i.%i.%i.%i/%i berada di kelas %c\n", IP1,IP2,IP3,IP4,CIDR,class);
    printf("---------------------------------------\n");
    printf("Angka bit borrowed anda adalah:\t%d \n", bitborrowed);
    printf("---------------------------------------\n");
    printf("Angka dari bits remained adalah:%d \n", bitremained);
    printf("---------------------------------------\n");
    printf("Subnet:\t%d \n", subnet);
    printf("---------------------------------------\n");
    printf("host:\t%d \n", host);
    printf("---------------------------------------\n");
    printf("blocksize:\t%d \n", blocksize);
    printf("---------------------------------------\n");
    subnetmask(CIDR);
    printf("\n---------------------------------------\n");
        	fprintf(out,"%i.%i.%i.%i, %d, %d, %d\n",IP1,IP2,IP3,IP4,subnet,host,blocksize);
                fclose(out);

    system("pause");
    Exit();
    return (0);
}


int subnetmask(int CIDR)
{
	if(CIDR==0)
	{
		printf("Subnet Mask anda adalah : 0.0.0.0");
	}
	else if(CIDR==1)
	{
		printf("Subnet Mask anda adalah : 128.0.0.0");
	}
	else if(CIDR==2)
	{
		printf("Subnet Mask anda adalah : 192.0.0.0");
	}
	else if(CIDR==3)
	{
		printf("Subnet Mask anda adalah : 224.0.0.0");
	}
	else if(CIDR==4)
	{
	 printf("Subnet Mask anda adalah : 240.0.0.0");
	}
	else if(CIDR==5)
	{
		printf("Subnet Mask anda adalah : 248.0.0.0");
	}
	else if(CIDR==6)
	{
		printf("Subnet Mask anda adalah : 252.0.0.0");
	}
	else if(CIDR==7)
	{
		printf("Subnet Mask anda adalah : 254.0.0.0");
	}
	else if(CIDR==8)
	{
		printf("Subnet Mask anda adalah : 255.0.0.0");
	}
	else if(CIDR==9)
	{
		printf("Subnet Mask anda adalah : 255.128.0.0");
	}
	else if(CIDR==10)
	{
		printf("Subnet Mask anda adalah : 255.192.0.0");
	}
	else if(CIDR==11)
	{
		printf("Subnet Mask anda adalah : 255.224.0.0");
	}
	else if(CIDR==12)
	{
		printf("Subnet Mask anda adalah : 255.240.0.0"); 
	}
	else if(CIDR==13)
	{
		printf("Subnet Mask anda adalah : 255.248.0.0");
	}
	else if(CIDR==14)
	{
		 printf("Subnet Mask anda adalah : 255.252.0.0");
	}
	else if(CIDR==15)
	{
		 printf("Subnet Mask anda adalah : 255.254.0.0");
	}
	else if(CIDR==16)
	{
		printf("Subnet Mask anda adalah : 255.255.0.0"); 
	}
	else if(CIDR==17)
	{
		printf("Subnet Mask anda adalah : 255.255.128.0");
	}
	else if(CIDR==18)
	{
	  printf("Subnet Mask anda adalah : 255.255.192.0"); 
	}
		else if(CIDR==19)
	{
	 printf("Subnet Mask anda adalah : 255.255.224.0");
	}
	else if(CIDR==20)
	{
		printf("Subnet Mask anda adalah : 255.255.240.0");
	}
	else if(CIDR==21)
	{
		printf("Subnet Mask anda adalah : 255.255.248.0");
	}
	else if(CIDR==22)
	{
		printf("Subnet Mask anda adalah : 255.255.252.0");
	}
	else if(CIDR==23)
	{
		 printf("Subnet Mask anda adalah : 255.255.254.0");
	}
	else if(CIDR==24)
	{
		printf("Subnet Mask anda adalah : 255.255.255.0");
	}
	else if(CIDR==25)
	{
		printf("Subnet Mask anda adalah : 255.255.255.128");
	}
	else if(CIDR==26)
	{
	 printf("Subnet Mask anda adalah : 255.255.255.192");
	}
		else if(CIDR==27)
	{
		printf("Subnet Mask anda adalah : 255.255.255.224");
	}
	else if(CIDR==28)
	{
	printf("Subnet Mask anda adalah : 255.255.255.240");
	}
	else if(CIDR==29)
	{
		printf("Subnet Mask anda adalah : 255.255.255.248");
	}
	else if(CIDR==30)
	{
		printf("Subnet Mask anda adalah : 255.255.255.252");
	}
	else if(CIDR==31)
	{
		 printf("Subnet Mask anda adalah : 255.255.255.254");
	}
	else
	{
		printf("Subnet Mask anda adalah : 255.255.255.255");
	}
}

int Hapus() 
{ 
	system("cls");
	fopen("Data.csv","w");
	printf("Data Berhasil di Hapus!!!\n");
	system("pause");
	system("cls");
	Exit ();
	return (0);
} 

int Bantuan() {
	
	system("cls");
	printf("\n");
	printf("\n");
	printf ("|1.Kalkulator ini berfungs sebagai alat untuk menghitung subnetmask,Bitborrowed, Bitremained, host, dan block size\n");
	printf ("|2.hal hal yang diperlukan untuk menghitung adalah IP address anda dan CIDR\n");
	printf ("|3.CIDR sendiri bebas anda masukan karena kalkulator ini berfungsi untuk menghitung keadaan real dan keadaan simulasi\n");
	printf ("|4.dari IP Address anda,silakan mencoba\n");
	system("pause");
	system("cls");
	Exit ();
	return (0);
}

int Exit() {
	int pil;
	system("cls");
	printf ("Apakah anda ingin keluar?\n");
	printf ("1)TIDAK\n"); 
	printf ("2)YA\n");
	printf("masukkan pilihan : ");
			scanf("%d", &pil);
				if(pil==1){
					system("cls");
					main();
				}
				else if(pil==2){
				printf("!!!!!!!!!!!***TERIMAKASIH TELAH MENCOBA PROGRAM NYA***!!!!!!!!!!\n");
				system("pause");
				return 0;
}
}
