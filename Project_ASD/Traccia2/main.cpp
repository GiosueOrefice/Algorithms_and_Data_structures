#include<iostream>
#include <fstream>
#include <ctime>
#include <Graph.h>
#include <Disjoint.h>

using namespace std;

Graph* Lettura_Dati_Input();
void Creazione_Nodi_Archi(Graph &g,int N,int P);

void HybridSort_Arco(int p,int r,vector <Arco*> G_E);
int Randomized_Partition(int p,int r,vector <Arco*> G_E);
void Insertion_Sort(int p,int r,vector <Arco*> G_E);
int Randomized_Partition(int p,int r,vector <Arco*> G_E);
int Partition(int p,int r,vector <Arco*> G_E);

vector <Arco*> Kruskal(Graph &G);
void Stampa_Soluzione(vector <Arco*> A);

int main()
{
    vector <Arco*> Soluzione;
    Graph *G=Lettura_Dati_Input();

    Soluzione=Kruskal(*G);
    Stampa_Soluzione(Soluzione);

    return 0;
}

Graph* Lettura_Dati_Input(){
    int N,P;
    int u,v,C;
    int pos_elem_riga=0,cont_pos_riga=0;
    Graph *g;
    fstream file;

    file.open("input.txt",ios::in);
    if(file.is_open()){
        while(pos_elem_riga<2){
            if(pos_elem_riga==0)
                file>>N;
            else file>>P;
                pos_elem_riga++;
                }

        if(N<2 || N>1000){
            cout<<"**ERRORE: IL NUMERO DI VERTICI DEVE ESSERE COMPRESO TRA 2 E 1000**"<<endl;
            exit(1);}

        if(P<1 || P>10000){
            cout<<"**ERRORE: IL NUMERO DI ARCHI DEVE ESSERE COMPRESO TRA 1 E 10000**"<<endl;
            exit(1);}

        pos_elem_riga=0;
        g=new Graph(N,P);

        for(int i=0;i<N;i++)
        g->addNode(new Node(i+1));

        while(!file.eof()){
            if(pos_elem_riga==0)
                file>>u;

            else if(pos_elem_riga==1)
                file>>v;

            else {
                file>>C;
                cont_pos_riga++;

                if(u>N || v>N || u<1 || v<1){
                    cout<<"ERRORE: I VERTICI DEVONO ESSERE NUMERATI DA 1 A N"<<endl;
                    cout<<"MODIFICARE ARCO N° "<<cont_pos_riga<<endl;
                    exit(1);}

                if(C<0){
                    cout<<"ERRORE: IL COSTO DEGLI ARCHI DEVE ESSERE >=0"<<endl;
                    cout<<"MODIFICARE ARCO N° "<<cont_pos_riga<<endl;
                    exit(1);}

                g->addArco(new Arco(g->getNode(u-1),g->getNode(v-1),C));
                pos_elem_riga=-1;
                }

            pos_elem_riga++;}

        if(g->GetG_E().size()!=P){
            cout<<"NUMERO DI ARCHI DIVERSO DA QUELLI SCRITTI NELLA PRIMA RIGA";
            exit(1);}

        for(int i=0;i<P-1;i++){
            for(int j=i+1;j<P;j++){
                if(g->getArco(i)->Getu()==g->getArco(j)->Getu() && g->getArco(i)->Getv()==g->getArco(j)->Getv()){
                    cout<<"ERRORE: L'ARCO "<<i+1<<" E' UGUALE ALL'ARCO "<<j+1<<endl;
                    cout<<"ARCO "<<i<<endl;
                    g->getArco(i)->PrintArco(); cout<<endl;
                    cout<<"ARCO "<<j<<endl;
                    g->getArco(j)->PrintArco();
                    exit(1);

                    }

                if(g->getArco(i)->Getu()==g->getArco(j)->Getv() && g->getArco(i)->Getv()==g->getArco(j)->Getu()){

                    cout<<"ERRORE: L'ARCO "<<i+1<<" E' UGUALE ALL'ARCO "<<j+1<<endl;
                    cout<<"ARCO "<<i<<endl;
                    g->getArco(i)->PrintArco(); cout<<endl; cout<<"ARCO "<<j<<endl; g->getArco(j)->PrintArco();

                    exit(1);

                    }
                    }}

        file.close();}
    else {cout<<"ERRORE APERTURA FILE"<<endl; exit(1);}

    return g;
}

vector <Arco*> Kruskal(Graph &G){
    vector <Arco*> A;
    Disjoint x;

    for(auto v:G.GetG_V())
        x.makeSet(v);

    HybridSort_Arco(0,G.getP()-1,G.GetG_E());
        for(auto e:G.GetG_E()){
            if(x.FindSet(x.GetSet(e->Getu()->getData()-1))!=x.FindSet(x.GetSet(e->Getv()->getData()-1))){
                    if(e->GetPeso()>0)
                    A.push_back(e);
                    x.Union(x.GetSet(e->Getu()->getData()-1),x.GetSet(e->Getv()->getData()-1));
                            }
                        }
        return A;
    }

void HybridSort_Arco(int p,int r,vector <Arco*> G_E){
    int q;
    if(p-r+1>10){
        q=Randomized_Partition(p,r,G_E);
        HybridSort_Arco(p,q-1,G_E);
        HybridSort_Arco(q+1,r,G_E);}

    else Insertion_Sort(p,r,G_E);

}

void Insertion_Sort(int p,int r,vector <Arco*> G_E){
    int i,j;
        for(i=p;i<=r;i++)
    {
        Arco x(G_E[i]->Getu(),G_E[i]->Getv(),G_E[i]->GetPeso());
        j=i-1;
        while (j>=0 && G_E[j]->GetPeso()>x.GetPeso())
            {
                G_E[j+1]->SetArco(G_E[j]->Getu(),G_E[j]->Getv(),G_E[j]->GetPeso());
                j--;
            }
            G_E[j+1]->SetArco(x.Getu(),x.Getv(),x.GetPeso());
    }
}

int Randomized_Partition(int p,int r,vector <Arco*> G_E){
    srand(time(NULL));
    int i=rand()%(r-p)+p+1;
    swap(G_E[r],G_E[i]);
    return Partition(p,r,G_E);
    }

int Partition(int p,int r,vector <Arco*> G_E){
    int x=G_E[r]->GetPeso();
    int i=p-1;
    for(int j=p;j<r;j++){
        if(G_E[j]->GetPeso()<=x){
            i=i+1;
            swap(G_E[i],G_E[j]);}
    }
     swap(G_E[i+1],G_E[r]);
     return i+1;
}

void Stampa_Soluzione(vector <Arco*> A){

    if(A.size()==0)
        cout<<"NESSUN PONTE DA COSTRUIRE"<<endl;

    else {
        int totale=0;
        cout<<"E' sufficiente ricostruire "<<A.size()<<" ponti:"<<endl;
        for(auto e:A){
            e->PrintArco();
            totale=totale+e->GetPeso();
                    }
        cout<<"Totale Costo: "<<totale<<endl;}
}
