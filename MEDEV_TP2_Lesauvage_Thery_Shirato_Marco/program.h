/* 
 * File:   program.h
 * Author: user
 *
 * Created on 24 novembre 2016, 12:15
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include<cstdlib>
#include<iostream>
//-----------------------------------------------------------------
// class
//-----------------------------------------------------------------
class PGM
{
private:
    int W;
    int H;
    
    void free();
    
public:
    double **pixels;         //pixels[W][H]
    
    PGM();
    PGM(int width,int height);
    PGM(const char *file_name);
    ~PGM();
    
    int  width() { return W; }
    int  height(){ return H; }
    
    void reset(int width,int height);
    
    bool load_from_file(const char *file_name);
    bool save_to_file(const char *file_name);
};
//-----------------------------------------------------------------


#endif	/* PROGRAM_H */

