#include<iostream>
#include <string.h>
using namespace std;
int pangkat(int n,int x) {
    int nilai=1,i;
    for (i=0;i<x;i++) {
        nilai=nilai*n;
    }
    return nilai;
}
void fungsi_convert_biner(int desimal)
{
    if(desimal>0)
    {
        fungsi_convert_biner(desimal/2);
        cout<<desimal%2;
    }
}
int convert_biner_desimal(char str[],int x)
{
    int i,desimal = 0;

    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] - '0' != 1 ) && (str[i] - '0' != 0))
        {
            return 1;
        }
    }
    //end of checking, all is right

    for (i =0; i <  strlen(str) ; i++)
    {
        if (str[i] - '0' == 1) {
            desimal = desimal + pangkat(2,strlen(str)-1-i);
        }
    }
    x = desimal;
    return x;

}
int convert_oktal_desimal(char str[],int x)
{
    int i,desimal=0;

    //checking
    if ((strlen(str) >= 6) && (str[0] > 49)) {
        return 1;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (!((str[i] > 47 ) && (str[i] < 56)))
        {
            return 1;
        }
    }
    //end of checking, all is right
    for (i =0; i <  strlen(str) ; i++)
    {
        desimal = desimal + (str[i] - '0') * pangkat(8,strlen(str)-1-i);
    }
    x = desimal;
    return x;
}
int convert_hexa_desimal(char str[],int x)
{
    int i,desimal=0;

    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if (! ( ((str[i] > 47 ) && (str[i] < 58)) || ((str[i] > 96 ) && (str[i] < 103)) || ((str[i] > 64 ) && (str[i] < 71)) ))
        {
            return 1;
        }
    }
    //end of checking, all is right
    for (i =0; i < strlen(str) ; i++)
    {
        if ((str[i] >= '0' ) && (str[i] <= '9')) {
            desimal = desimal + (str[i] - '0') * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > '@' ) && (str[i] < 'G')) {
            desimal = desimal + (str[i] - 55) * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > 96 ) && (str[i] < 'g')) {
            desimal = desimal + (str[i] - 87) * pangkat(16,strlen(str)-1-i);
        }
    }
    x = desimal;
    return x;
    }

int main(){
    int pilihan,desimal;
    char oktal[6],biner[16],hexa[4];
    cout<<"\nNama   : Gusti Gagas Samudra";
    cout<<"\nNIM    : 19051397022";
    cout<<"\nPRODI  : D4 Manajemen Informatika";
    cout<<"\n\n==========  Masukan Basis Angka  ==========\n";
    cout<<"1. Desimal\n";
    cout<<"2. Biner\n";
    cout<<"3. Oktal\n";
    cout<<"4. Heksadesimal\n";
    cout<<"Pilihan: ";
    cin>>pilihan;
    switch(pilihan){
        case 1:
            cout<<"Masukan angka desimal Maksimal (6553) :";
            cin>>desimal;
            cout<<"Biner :";
            fungsi_convert_biner(desimal);
            cout<<endl;
            cout<<"Oktal :";
            cout<<oct<<desimal<<endl;
            cout<<"Hexadesimal :";
            cout<<hex<<desimal<<endl;
            break;
        case 2:
            cout<<"Masukan angka biner (Maksimal 16 bit): ";
            cin>>biner;
            desimal=convert_biner_desimal(biner,desimal);
            cout<<"Desimal :";
            cout<<dec<<desimal<<endl;

            cout<<"Oktal :";
            cout<<oct<<desimal<<endl;

            cout<<"Hexadesimal :";
            cout<<hex<<desimal<<endl;
            break;
        case 3:
            cout<<"Masukan angka Oktal (Maksimal 177777): ";
            cin>>oktal;
            desimal=convert_oktal_desimal(oktal,desimal);
            cout<<"Desimal :";
            cout<<dec<<desimal<<endl;
            cout<<"Biner :";
            fungsi_convert_biner(desimal);
            cout<<endl;
            cout<<"Hexadesimal :";
            cout<<hex<<desimal<<endl;
            break;
        case 4:
            cout<<"Masukan angka hexa (Maksimal FFFF): ";
            cin>>hexa;
            desimal=convert_hexa_desimal(hexa,desimal);
            cout<<"Desimal :";
            cout<<dec<<desimal<<endl;
            cout<<"Biner :";
            fungsi_convert_biner(desimal);
            cout<<endl;
            cout<<"Oktal :";
            cout<<oct<<desimal<<endl;
            break;
        default:
            //
            break;
    }




    return 0;
}
