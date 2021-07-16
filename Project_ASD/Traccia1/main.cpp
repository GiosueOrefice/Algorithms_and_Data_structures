#include <iostream>
#include <fstream>
#include <HashTable.h>

using namespace std;
void LetturaFile(HashTable &x,Disjoint &y);

int main()
{
    HashTable x(40);
    Disjoint y;
    int key;
    string value;

    LetturaFile(x,y);

    int scelta;
    do{
        cout<<"**MENU**"<<endl;
        cout<<"[0]USCIRE"<<endl;
        cout<<"[1]MAKESET"<<endl;
        cout<<"[2]FINDSET"<<endl;
        cout<<"[3]UNION"<<endl;
        cout<<"[4]STAMPA HASHING"<<endl;

        cout<<"Inserisci scelta: ";
        cin>>scelta;

        switch(scelta){
            case 0: {
                exit(1); break;}

            case 1:{
                cout<<endl<<"Inserisci key: "; cin>>key;
                fflush(stdin);
                cout<<"Inserisci Value (Per la stringa vuota digitare: /0 ): ";
                getline(cin,value);
                if(value=="/0")
                    value="";

                x.Insert(y.makeSet(new Set(key,value)));
                cout<<"MAKESET AVVENUTA"<<endl; break;}

            case 2:{
                        cout<<endl<<"Inserisci key: ";
                        cin>>key;
                        cout<<"Inserisci Value (Per la stringa vuota digitare: /0 ): ";
                        fflush(stdin);
                        getline(cin,value);
                        if(value=="/0")
                            value="";
                        if(x.Search(key,value)){
                            cout<<"PARENT: ";
                            y.FindSet(x.getSet(key,value))->printSet();
                            cout<<endl;
                        }
                        else
                            cout<<"**NON PRESENTE NELL'HASH TABLE**"<<endl;
                        break;
                    }

            case 3:{
                    int key2;
                    string value2;
                    cout<<endl<<"Inserisci key: ";
                    cin>>key;
                    cout<<"Inserisci Value (Per la stringa vuota digitare: /0 ): ";
                    fflush(stdin);
                    getline(cin,value);
                    if(value=="/0")
                        value="";
                        if(x.Search(key,value)){
                            cout<<endl<<"Inserisci key: ";
                            cin>>key2;
                            cout<<"Inserisci Value (Per la stringa vuota digitare: /0 ): ";
                            fflush(stdin);
                            getline(cin,value2);
                            if(value2=="/0")
                                value2="";
                            if(x.Search(key2,value2)){
                                y.Union(x.getSet(key,value),x.getSet(key2,value2));
                                cout<<"UNION AVVENUTA"<<endl;
                                }
                            else cout<<"**NON PRESENTE NELL'HASH TABLE**"<<endl;
                        }
                        else cout<<"**NON PRESENTE NELL'HASH TABLE**"<<endl;
                    break;
                }

            case 4:{x.displayHash(); break;}

            default: {cout<<"ERRORE"<<endl; break;}
            }
        system("pause");
        system("cls");
    }while(1);

    return 0;
}

void LetturaFile(HashTable &x,Disjoint &y){

    int key; string value;
    fstream file;
    file.open("File.txt",ios::in);
    if(file.is_open()){
        while(!file.eof()){
            file>>key;
            getline(file,value);
            if(value.size()!=0){
                int cont=0;
                while (value[cont]==' ')
                    cont++;
                value.erase(0,cont);
            }

            x.Insert(y.makeSet(new Set(key,value)));
        }

        file.close();
        }
    else cout<<"ERRORE APERTURA FILE"<<endl;
}
