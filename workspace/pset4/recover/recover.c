//Recovers jpg files

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

#define IMAGES 50
#define MAXSIZE 200

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE byte[512];
    BYTE fourthbyte;
    int filecount = 0;
    int cf = 0;
    int counter = 0;
    do
    {
        cf = fread(&byte,sizeof(BYTE),512,inptr);
        fourthbyte = byte[3] - byte[3]%0x10;
    } while( cf != EOF && !(byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && fourthbyte == 0xe0) );
    while( filecount < IMAGES && cf != EOF)
    {
        char name[10];
        sprintf(name,"jpg/%02d.jpg",filecount);
        FILE *outptr = fopen(name,"w");
        if( outptr != NULL)
        {
            counter = 0;
            do
            {
                fwrite(&byte,sizeof(BYTE),512,outptr);
                cf = fread(&byte,sizeof(BYTE),512,inptr);
                fourthbyte = byte[3] - byte[3]%0x10;
                if( filecount == IMAGES - 1)
                {
                    counter++;
                    if(counter > MAXSIZE)
                        break;
                }
            } while( cf != EOF && !(byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && fourthbyte == 0xe0)  );
            filecount++;
            fclose(outptr);
        }
    }

    // success
    return 0;
}
