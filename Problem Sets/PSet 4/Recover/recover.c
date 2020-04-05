#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // check file
    char *raw = argv[1];
    
    // Open file (abrir raw)
    FILE *arq_ptr = fopen(raw, "r");
    
    if (arq_ptr == NULL)
    {
        fprintf(stderr, "Sorry, could not open this file %s.\n", raw);
        return 2;
    }
    
    unsigned char *buffer = malloc(512);
    int imagecount = 0;
    FILE *image;
    
    while (fread(buffer, 512, 1, arq_ptr))
    {
        // image .jpg found
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //close .jpg
            if (imagecount > 0)
            {
                fclose(image);
            }
            
            // Filename of the image
            char filename[7];
            sprintf(filename, "%03i.jpg", imagecount);
            
            // Open new jpg
            image = fopen(filename, "w");
            
            imagecount++;
        }
        if (!imagecount)
        {
            continue;
        }
        fwrite(buffer, 512, 1, image);
    }
    // close last .jpg
    fclose(arq_ptr);
    fclose(image);
    return 0;
}