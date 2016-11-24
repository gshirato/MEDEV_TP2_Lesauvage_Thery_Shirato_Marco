
#ifndef function_h
#define function_h

class Image{
public:
    int sx, sy;
    double **img;
    int gray;

    Image();
    Image(int dx, int dy);
    void allocate(int dx,int dy,int dgray);
    virtual ~Image();
};


void getPGM(Image *in,char *filename);
void savePGM(Image *in,char *filename){
#endif // function_h
