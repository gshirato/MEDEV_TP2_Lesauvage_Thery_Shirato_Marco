
#include "functions.h"

Image::Image(){
    img=0;
    sx=0;
    sy=0;
    gray=255;
}
Image::Image(int dx,int dy){
    allocate(dx,dy,255);
}
void Image::allocate(int dx,int dy, int dgray){
    sx=dx;
    sy=dy;
    int i;
    img =new double*[sy];
    for(i=0;i<sy;i++){
        img[i]=new double[dx];
    }
    gray =dgray;
}
virtual ~Image(){
    int i;
    for(i=0;i<sy;i++){
        delete[] img[i];
    }
    delete[] img;
}

void getPGM(Image *in,char *filename){
    if(in==NULL)return;
    FILE *fp =fopen(filename,"r");
    char P2[100];
    fscanf(fp,"%s",P2);
    int sx,sy,gray;
    fscanf(fp, "%d %d",&sx, &sy);
    fscanf(fp, "%d",&gray);
    in->allocate(sx,sy,gray);
    int i,j;
    for(i=0;i<in->sy;i++){
         for(j=0;j<in->sx;j++){

                int val;
         fscanf(fp,"%d ",&val);
         in->img[i][j] =((double)(val));
        }
    }
    fclose(fp);
}

void savePGM(Image *in,char *filename){
    FILE *fp = fopen(filename, "w");
    fprintf(fp,"P2\n");
    fprintf(fp,"%d %d\n",in->sx,in->sy);
    fprintf(fp,"%d\n",in->gray);
    int i,j;
    int i,j;
    for(i=0;i<in->sy;i++){
        for(j=0;j<in->sx;j++){
        int val = ((int)(in->img[i][j]));
        if(fabs(val-in->img[i][j])>=0.5)
            val++;
        if(val<0)
            val=0;
        if(val>in->gray)
            val=in->gray;

        fprintf(fp,"%d ",val);
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
}
