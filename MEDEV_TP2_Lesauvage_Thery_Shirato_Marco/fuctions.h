/* 
 * File:   functions.h
 * Author: user
 *
 * Created on 24 novembre 2016, 10:15
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>

typedef union pixcel_t{
    uint g;
}pixcel_t;

typedef struct image_t {
    uint width;
    uint height;
    pixcel_t **map;
}image_t;


bool writeFile(const char* filename, image_t *img);
bool writeStream(FILE *fp, image_t *img);
bool write_p2(FILE *fp, image_t *img);


image_t *read_file(const char *filename) ;

static int get_next_nspaceC(FILE * fp);

static int get_next_token(FILE *fp, char *buf, int size);

static int parse_int(const char *str);

static int get_next_int(FILE *fp);

image_t *read_stream(FILE *fp);

static uint normalize(int value, int max);

static bool read_p2(FILE *fp, image_t *img, int max);
#endif	/* FUNCTIONS_H */

