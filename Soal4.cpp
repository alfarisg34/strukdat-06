/*	Nama program	: Soal4
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 16 04 2019
	Deskripsi		: 
********************************************************************/
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct Contact{
    char nama[10];
    char phone[12];
    Contact* next;
};

struct Index{
    char index[1];
    Index* next;
    Contact* nextContact;
};

typedef Index *pointerIn;
typedef Contact *pointerCon;
typedef pointerIn ListIn;

void createListIn(ListIn &First){
    First = NULL;
}

void createElementIn(pointerIn &pBaru){
    pBaru = new Index;
    cout << "Index : "; cin >> pBaru->index;
    pBaru->next = NULL;
    pBaru->nextContact = NULL;
}

void createElementContact(pointerCon &pBaru){
    pBaru = new Contact;
    cout << "Nama   : "; cin >> pBaru->nama;
    cout << "Phone  : "; cin >> pBaru->phone;
    pBaru->next = NULL;
}

void traversalIn(ListIn First){
 pointerIn pBantu;
 pBantu=First;
 while(pBantu!=NULL){
  cout<<"Index : "<<pBantu->index<<endl;
  pBantu=pBantu->next;
 }
}

void insertLastIn(ListIn& First, pointerIn pBaru){
 pointer last;
 if (First==NULL){
  First=pBaru;
 }
 else {
  last=First;
  while (last->next!=NULL){
   last=last->next;
  }
  last->next=pBaru;
 }
}

void deleteFirstIn(ListIn &First, pointerIn &pHapus){
    if(First == NULL){                          //list kosong
        pHapus = NULL;
        cout << "Data Kosong!" << endl;
    } else if (First->next == NULL){            //list dengan satu isi
        pHapus = First;
        First = NULL;
    } else {                                    //list banyak isi
        pHapus = First;
        First = First->next;
        pHapus->next=NULL;
    }
}

void linearSearch(ListIn First,char key[20],int& status,pointerIn& pCari){
 status=0;
 pCari=First;
 while(status==0 && pCari!=NULL){
  if(strcmp(pCari->index,key)==0){
   status=1;
  }
  else{
   pCari=pCari->next;
  }
 }
}

void insertFirstContact(ListIn &First, char key[20], pointerCon pBaru){
    pointerIn pIn;
 int ketemu;
 cout<<"Masukan Index yang di cari : "; cin>>key;
 linearSearch(First,key,ketemu,pIn);
 if(ketemu){
  cout<<"Ditemukan Index : "<<pIn->index<<endl;
  if(pIn->nextContact==NULL){
   pIn->nextContact=pBaru;
  }
  else{
   pBaru->next=pIn->nextContact;
   pIn->nextContact=pBaru;
  }
 }
 else{
  cout<<"Index tidak di temukan"<<endl;
 }
}

void deleteFirstContact(ListIn &First, char key[20], pointerCon &pHapus){
    int ketemu;
 pointerIn pIn;
 cout<<"Masukan Index yang di cari: "; cin>>key;
 linearSearch(First,key,ketemu,pIn);
  if(ketemu){
  cout<<"Ditemukan index : "<<pIn->index;
  if(pIn->nextContact==NULL){
   cout<<"Tidak ada yang di hapus"<<endl;
  }
  else if(pIn->nextContact->next==NULL){
   pHapus=pIn->nextContact;
   pIn->nextContact=NULL;
  }
  else{
   pHapus=pIn->nextContact;
   pIn->nextContact=pIn->nextContact->next;
   pHapus->next=NULL;
   
  }
 }
 else{
  cout<<"Index tidak di temukan"<<endl;
 }
 cout <<endl;
}

void traversalIndexContact(ListIn First){
    pointerIn pBantuIn;
    pointerCon pBantuCon;
    cout << "Traversal Index Contact" << endl;
    pBantuIn = First;
    while (pBantuIn != NULL)
    { //loop Index
        cout << pBantuIn->index <<endl;
        pBantuCon = pBantuIn->nextContact;
        while (pBantuCon != NULL)
        { //loop Contact
            cout << " " << pBantuCon->nama << " : " << pBantuCon->phone <<endl;
            pBantuCon = pBantuCon->next;
        }
        pBantuIn = pBantuIn->next;
    }
}

int main()
{
 pointerIn p;
 pointerCon q;
 ListIn a;
 int pil;
 char ketemu[20];
 createListIn(a);
  do{
  cout << "Menu" <<endl;
  cout << "1.  Insert Index" <<endl;
  cout << "2.  Insert/Update Contact" <<endl;
  cout << "3.  Delete Index" <<endl;
  cout << "4.  Delete Contact" <<endl;
  cout << "5.  Traversal Index" <<endl;
  cout << "6.  Traversal Index Contact" <<endl; 
  cout << "7.  Exit" <<endl;
  cout << "Pilih : "; cin >> pil;
  switch (pil){
   case 1 :
   system("cls");
   createElementIn(p);
   insertLastIn(a,p);
   break;
   case 2 :
   system("cls");
   createElementContact(q);
   insertFirstContact(a,ketemu,q);
   break;
   case 3 :
   system("cls");
   deleteFirstIn(a,p);
   break;
   case 4 :
   system("cls");
   deleteFirstContact(a,ketemu,q);
   break;
   case 5 :
   system("cls");
   traversalIn(a);
   break;
   case 6 :
   system("cls");
   traversalIndexContact(a);
   break;
   case 7 :
   cout << "^^Terima Kasih Telah Menggunakan Program Ini^^";
   break;
   default :
   cout << "^^ANGKA YANG ANDA INPUT SALAH^^" <<endl;
            cout << "^^Tekan <Enter> Untuk Mengulang^^";
            getch();
   break;
  }
 }while (pil!=7);
}