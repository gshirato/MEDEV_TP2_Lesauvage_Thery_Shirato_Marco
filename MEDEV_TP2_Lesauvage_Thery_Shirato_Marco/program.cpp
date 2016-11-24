//-----------------------------------------------------------------
#include "program.h"

#include <fstream>
using namespace std;

//-----------------------------------------------------------------
//constructeur
//-----------------------------------------------------------------
PGM::PGM()
{
    W=0;
    H=0;
    pixels=NULL;
}
//-----------------------------------------------------------------
PGM::PGM(const char *file_name)
{
    pixels=NULL;
    load_from_file(file_name);
}
//-----------------------------------------------------------------
//detructuer
//-----------------------------------------------------------------
PGM::~PGM()
{
    free();
}
//-----------------------------------------------------------------
//initialisation
//-----------------------------------------------------------------
void PGM::reset(int _w,int _h)
{
    free();
    
    W=_w;
    H=_h;
    
    pixels   =new double*[W];
    pixels[0]=new double[W*H];
    for(int x=1;x<W;x++) pixels[x]=pixels[x-1]+H;
}
//-----------------------------------------------------------------
//free
//-----------------------------------------------------------------
void PGM::free()
{
    if(pixels!=NULL){
        if(pixels[0]!=NULL) delete[] pixels[0];
        delete[] pixels;
        pixels=NULL;
    }
    
    W=0;
    H=0;
}
//-----------------------------------------------------------------
//read
//-----------------------------------------------------------------
bool PGM::load_from_file(const char *file_name)
{
    ifstream file(file_name);
    
    if(!file.is_open()) return false;
    
    bool grayscale=true;
    string str;
    
    file>>str;
    if(str!="P2") return false;    //PGM
    
    //lire sa taille
    for(int i=0;i<3;i++){
        file>>str;
        while(str[0]=='#'){
            getline(file,str);
            file>>str;
        }
        switch(i){
            case 0: W=atoi(str.c_str()); break;
            case 1: H=atoi(str.c_str()); break;
        }
    }
    
    //keep 
    reset(W,H);
    
    //read
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            file>>str;
            while(str[0]=='#'){
                getline(file,str);
                file>>str;
                
            }
           pixels[x][y]=atoi(str.c_str());
           cout << str << " ";
            }
        cout <<endl;
        }
    
    file.close();
    
    return true;
}
//-----------------------------------------------------------------
//save
//-----------------------------------------------------------------
bool PGM::save_to_file(const char *file_name)
{
    ofstream file(file_name);
    
    if(!file.is_open()) return false;
    
    file<<"P2"<<endl;
    
    file<<"# CREATOR: no name"<<endl;
    file<<W<<" "<<H<<endl;
    file<<255<<endl;
    
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            double tmp=pixels[x][y];
            if(tmp<0) tmp=0;
            else if(tmp>255) tmp=255;
            
            file<<(int)(tmp)<<endl;
        }
    }
    file.close();
    
    return true;
}
//-----------------------------------------------------------------



