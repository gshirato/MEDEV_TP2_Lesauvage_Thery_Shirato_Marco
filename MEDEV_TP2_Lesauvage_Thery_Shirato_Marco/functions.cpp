#include "functions.h"




image_t *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");

    image_t *img = read_stream(fp);
    fclose(fp);
    return img;
}

static int get_next_nspaceC(FILE * fp) {
    int c;
    bool etat = false;
    while ((c = getc(fp)) != EOF) {
        if (etat) {
            if (c == '\n' || c == '\r') {
                etat = false;
            }
            continue;
        }
        if (c == '#') {
            etat = true;
            continue;
        }
        if (!isspace(c)) {
            break;
        }
    }
    return c;
}

static int get_next_token(FILE *fp, char *buf, int size) {
    int i = 0;
    int c = get_next_nspaceC(fp);
    while (c != EOF && !isspace(c) && i < size - 1) {
        buf[i++] = c;
        c = getc(fp);
    }
    buf[i] = 0;
    return 0;
}

static int parse_int(const char *str) {
    int i;
    int r = 0;
    if (str[0] == 0) {
        return -1;
    }
    for (i = 0; str[i] != 0; i++) {
        if (!isdigit((int) str[i])) {
            return -1;
        }
        r *= 10;
        r += str[i] - '0';
    }
    return r;
}

static int get_next_int(FILE *fp) {
    char token[11];
    get_next_token(fp, token, sizeof (token));
    return parse_int(token);
}

image_t *read_stream(FILE *fp) {
    char token[4];
    int type = 2;
    int width;
    int height;
    int max = 0;
    bool result = false;
    image_t *img = NULL;
    get_next_token(fp, token, sizeof (token));
    type = token[1] - '0';
    width = get_next_int(fp);
    height = get_next_int(fp);

    max = get_next_int(fp);

    result = read_p2(fp, img, max);

    return img;
}

static uint normalize(int value, int max) {
    return (value * 255 + max / 2) / max;
}

static bool read_p2(FILE *fp, image_t *img, int max) {
    int x, y;
    int tmp;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            if (tmp = get_next_int(fp) < 0) {
                return false;
            }
            img->map[x][y].g = normalize(tmp, max);

        }
    }
    return true;

}

// true:SUCCESS false:FAILURE
bool writeFile(const char* filename, image_t *img) {
    bool result;
    result = false;
    FILE *fp = fopen(filename, "wb");

    result = writeStream(fp, img);
    fclose(fp);

    return result;
}

bool writeStream(FILE *fp, image_t *img) {
    
    fprintf(fp, "P2\n");
    fprintf(fp, "%u %u\n", img->width, img->height);
    fprintf(fp, "255\n");

    write_p2(fp, img);

    return true;
}

bool write_p2(FILE *fp, image_t *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            fprintf(fp, "%u\n", img->map[x][y].g);
        }
    }
    return true;
}
