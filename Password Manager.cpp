#include<iostream>
#include<fstream>
#include<filesystem>
#include<limits>
#include<windows.h>
#include<random>

using namespace std;
using namespace std::filesystem;


char sas;


//los fakin archivos full disimulados
path dir = "C:/Users/Public/Documents/enbici";
string file = "Documents.rar";
path allshit = dir / file;
path inglishorspanish = dir / "ios.enbici";
//uso futuro depende ns
path liowi = dir / "liowi.enbici";

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtiene el manejador de la consola
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor); // Combina el color de texto y el fondo
}

int aleatoria(){
    random_device rd;
    mt19937 gen(rd());

    string carac = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    uniform_int_distribution<>distrib(0,carac.size());

    int lalgo; 

    cout<<"Cual quiere que sea el largo de la pass?:";
    cin>>lalgo;

    string sas;

    for (int i = 0; i < lalgo; i++)
    {
        sas +=carac[distrib(gen)];
    }
    
    cout<<"La Pass es: "<<sas;
    return 1;
}

int ver(){
    ifstream archivo(allshit);
    //esta string guarda las lineas 
    string linea;
    if (archivo.is_open())
    {
        while (getline(archivo,linea))
        {
            cout<<linea<<endl;
        }
    }
    else{
        cout<<"Error:Tenes que agregar una password antes de poder verlas campeon";
    }
   
    return 1;
}

int agregar(){
    char pass[50],user[50],serv[50];
    //creo la fakin carpeta de los cojones
    if (!exists(dir))
    {
        create_directory(dir);
        cout<<"Archivos de passwords creado";
    }

    ifstream achis(inglishorspanish);
    string lain;
    //pedir la data
    if (achis.is_open()){
        getline(achis,lain);
        if (lain == "1")
        { 
            cout<<endl<<"Ingrese la contraseña: ";
            cin.getline(pass,50,'\n');

            cout<<endl<<"Ingrese el usuario: ";
            cin.getline(user,50,'\n');
  
            cout<<endl<<"Ingrese el nombre del servicio: ";
            cin.getline(serv,50,'\n');
        }
        else{
            cout<<endl<<"Enter the password: ";
            cin.getline(pass,50,'\n');
   
            cout<<endl<<"Enter the username: ";
            cin.getline(user,50,'\n');

            cout<<endl<<"Enter the username of that service: ";
            cin.getline(serv,50,'\n');
        }
    }
    
    ofstream archivo(allshit,ios::app);
    //escribi el archivo
    if (archivo.is_open())
    {
        archivo<<endl<<serv<<"\n"<< string(30, '-') << "\n"<<"\n"<<user<<"\n"<<pass<< endl<<string(30, '-') ;
        archivo.close();
    }
    else{
        cout<<"Hubo un puto error XD";
    }

}

void menues(){
    cout<<endl;
    cout<< " _____       ____  _      _ \n";
    cout<< "| ____|_ __ | __ )(_) ___(_)\n";
    cout<< "|  _| | '_ \\|  _ \\| |/ __| |\n";
    cout<< "| |___| | | | |_) | | (__| |\n";
    cout<< "|_____|_| |_|____/|_|\\___|_|\n";
    cout<<"===Menu==="<<endl;
    cout<<"1-Agregar una clave "<<endl;;
    cout<<"2-Ver las claves"<<endl;
    cout<<"3-Clave aletoria"<<endl;
    cout<<"4-Eliminar claves(en proceso :/)"<<endl;
    cout<<"5-Limpiar la ventana"<<endl;
    cout<<"0-Salir"<<endl;
    cout<<"$";
}

void menuen(){
    cout<<endl;
    cout<< " _____       ____  _      _ \n";
    cout<< "| ____|_ __ | __ )(_) ___(_)\n";
    cout<< "|  _| | '_ \\|  _ \\| |/ __| |\n";
    cout<< "| |___| | | | |_) | | (__| |\n";
    cout<< "|_____|_| |_|____/|_|\\___|_|\n";
    cout<<"===Menu==="<<endl;
    cout<<"1-Add a password "<<endl;;
    cout<<"2-See the Passwords"<<endl;
    cout<<"3-Aleatory password"<<endl;
    cout<<"4-Delete a password(In process :/)"<<endl;
    cout<<"5-Clear"<<endl;
    cout<<"0-Exit"<<endl;
    cout<<"$";
}

int main(){
    int var;
    setColor(13,0);

    do
    {   
        if (!exists(inglishorspanish))
    {   
        cout<<"English Or Spanish?"<<endl;
        cout<<"1-Spanish"<<endl;
        cout<<"2-English"<<endl;
        cin>>var;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//como no ponga esto creo que caga todo
        ofstream achis(inglishorspanish);
        if (achis.is_open())
        {
            achis<<var;
            achis.close();
        }
        
    }
    string lain;

    ifstream achis(inglishorspanish);

    if (achis.is_open()){
        getline(achis,lain);   
        if (lain == "1")
        {
            menues();
        }   
        else{
        menuen();}
    }
        
        cin>>var;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpia el buffer DE MIERDA
        switch (var)
        {
        case 1:
            agregar();
            if (lain=="1")
            {   
                menues();
            }else{menuen();}
            system("cls");
            break;
            
        case 2:
            ver();
            break;
        case 3:
            aleatoria();
            break;
        case 5:
            system("cls");
         
            break;

        case 0:
            cout<<"Saliendo...";
            break;
        }
    } while (var !=0);
    

}