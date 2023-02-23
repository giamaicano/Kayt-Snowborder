#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;

struct caratt{

    string cogn;
    int x[40],y[40],n_mat[10];

};

void carica_s(caratt ct[]){

    ifstream fin("Cognomi.txt");
    int r;
    char rc;
    string app,v[70];

    srand(time(NULL));

    for(int i=0;i<50;i++)
    {
        getline(fin,v[i]);
    }

    for(int t=0;t<20;t++)
    {
      r = rand()%50;
      ct[t].cogn = v[r];
    }

    for(int c=0;c<20;c++){

        for(int h=0;h<9;h++)
        {
            r = rand()%9;
            ct[c].n_mat[h] = r;
            //cout<<ct[c].n_mat[h];
        }
        //cout<<endl;
    }

    for(int cp=0;cp<20;cp++)
    {
        for(int co=0;co<30;co++)
        {
            ct[cp].x[co] = rand()%100;
            ct[cp].y[co] = rand()%100;
            //cout<<ct[cp].x[co];
            //cout<<ct[cp].y[co];
            //cout<<" ";

        }
        //cout<<endl;
    }

    fin.close();

}


void carica_f(caratt ct[])
{
    ofstream fout("Partecipanti.txt");

    for(int i=0;i<20;i++)
    {
        fout<<ct[i].cogn<<"  ";

        for(int m=0;m<9;m++)
        {
           fout<<ct[i].n_mat[m];

        }
        fout<<"  ";

        for(int cc=0;cc<30;cc++)
        {
            fout<<ct[i].x[cc]<<";";
            fout<<ct[i].y[cc]<<" ";
        }


    fout<<endl;

    }




    fout.close();
}


void leggi(){
    ifstream fin("Partecipanti");
    string app;


    fin.close();
}



int main()
{
    caratt ct[100];

    carica_s(ct);
    carica_f(ct);




    return 0;
}
