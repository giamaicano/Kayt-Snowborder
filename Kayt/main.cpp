
/*!
\file main.cpp
\brief programma per il calcolo del podio di una gara di kayt-snowboarding
\author Luciani Giovanni
\date 27/02/2023
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <math.h>

using namespace std;


/*!
\struct caratt
\brief struct che contiene il cognome, il numero di matricola e le coordinate di ciascun partecipante alla gara
*/
struct caratt{
/*!
\var cong
\brief variabile che contiene il cognome di ogni partecipante alla gara
\var x
\brief vettore utilizzato per contenere tutte le coordinate x di ogni singolo partecipante
\var y
\brief vettore utilizzato per contenere tutte le coordinate y di ogni singolo partecipante
\var n_mat
\brief vettore utilizzato per contenere il numero di matricola per l'identificazione di ogno singolo partecipante
*/
    string cogn;
    float x[40],y[40],n_mat[10];

};

/*!

\fn carica_s
\brief funzione utilizzata per riempire tutte le variabili presenti nella struct
\param ct
\brief parametro vettore di tipo struct
*/

void carica_s(caratt ct[]){

/*!
\var fin
\brief variabile utilizzata per creare il canale lettura sul file Cognomi.txt
\var r
\brief variabile utilizzata per contenere i numeri randomizzati
\var i
\brief variabile utilizzata come contatore
\var v
\brief variabile vettore utilizzata per contenere i cognomi presenti nel file Cognomi.txt
*/

    ifstream fin("Cognomi.txt");
    int r,i=0;
    string v[70];

    srand(time(NULL));


//!\brief ciclo utilizzato per inserire tutti i cognomi dei partecipanti nel vettore

    while(fin.eof()){

        getline(fin,v[i]);
        i++;
    }

//!\brief ciclo utilizzato per selezionare un numero predefinito di atleti per la gara


    for(int t=0;t<20;t++)
    {
      r = rand()%50;
      ct[t].cogn = v[r];
    }

//!\brief ciclo utilizzato per scorrere tutti gli atleti selezionati

    for(int c=0;c<20;c++){
//!\brief ciclo utilizzato per riempire il vettore n_mat con numeri casuali
        for(int h=0;h<9;h++)
        {
            r = rand()%9;
            ct[c].n_mat[h] = r;
        }
    }

//!\brief ciclo utilizzato per scorrere tutti gli atleti selezionati
    for(int cp=0;cp<20;cp++)
    {
//!\brief ciclo utilizzato per riempire entrambi i vettori delle coordinate di ogni singolo atleta partecipante alla gara
        for(int co=0;co<30;co++)
        {
            ct[cp].x[co] = rand()%101;
            ct[cp].y[co] = rand()%101;
        }

    }

//!\brief chiusura del cananale di collegamento con il file
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


void visp(caratt ct[]){

    for(int i=0;i<20;i++)
    {
        cout<<ct[i].cogn<<"  ";

        for(int i1=0;i1<9;i1++)
            cout<<ct[i].n_mat[i1];

            cout<<"  ";

        for(int i2=0;i2<30;i2++)
            cout<<ct[i].x[i2]<<";"<<ct[i].y[i2]<<" ";


            cout<<endl;
    }


}


void calckm(caratt ct[] ,float vp[]){



    for(int i=0;i<20;i++)
        {
            vp[i] = 0;
            for(int k=0;k<30;k++)
            {
                if(k<29)
                vp[i] += sqrt(pow((ct[i].x[k+1] - ct[i].x[k]),2) + pow((ct[i].y[k+1] - ct[i].y[k]),2));

            }

        }


    for(int i=0;i<20;i++)
    {
        cout<<ct[i].cogn<<"  ";

        for(int i1=0;i1<9;i1++)
            cout<<ct[i].n_mat[i1];

            cout<<"  "<<vp[i];

            cout<<endl;
    }


}



void calcp(caratt ct[] , float vp[]){

    float pp=0,ss=0,tt=0;
    int cont;


       cout<<endl<<endl<<"Il podio della gara di kay-snowboarding e': "<<endl;



    for(int p=0;p<20;p++)
    {
        //cout<<pp<<endl;
        if(pp < vp[p])
        {

          pp = vp[p];
          cont = p;

        }

    }
    cout<<ct[cont].cogn<<"  ";

    for(int i=0;i<9;i++)
    {
        cout<<ct[cont].n_mat[i];
    }
    cout<<"  "<<vp[cont]<<"km"<<endl;




    for(int s=0;s<20;s++)
    {
        if(ss < vp[s] && vp[s] < pp){

                ss = vp[s];
                cont = s;

        }
    }
    cout<<ct[cont].cogn<<"  ";

    for(int i=0;i<9;i++)
    {
        cout<<ct[cont].n_mat[i];
    }
    cout<<"  "<<ss<<"km"<<endl;




    for(int t=0;t<20;t++)
    {
        if(tt < vp[t] && vp[t] < ss)
        {

            tt = vp[t];
            cont = t;

        }
    }
    cout<<ct[cont].cogn<<"  ";

    for(int i=0;i<9;i++)
    {
        cout<<ct[cont].n_mat[i];
    }
    cout<<"  "<<tt<<"km"<<endl;


}


void menu(){
caratt ct[100];
float vp[50];

int sc;

    do
    {
        cout << endl<<" MENU'" << endl;
        cout << "1) Visualizzazione della lista dei partecipanti e delle rispettive informazioni sulla gara" << endl
             << "2) Visualizza i km percorsi da ogni partecipante" << endl
             << "3) Visualizza il podio della gara" << endl
             << "4) Esci.. " << endl<<endl
             << ">> ";
            cin>>sc;

            switch(sc)
            {
                case 1:
                    carica_s(ct);
                    carica_f(ct);
                    visp(ct);

                    break;

                case 2:
                calckm(ct,vp);
                    break;

                case 3:
                    calcp(ct,vp);
                    break;

            }


    }while(sc!=4);



}



int main()
{
    menu();


    return 0;
}
