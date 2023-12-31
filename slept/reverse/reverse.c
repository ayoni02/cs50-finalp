#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
    printf("Usage: ./reverse input.wav output.wav\n");
    return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 1)
    {
        printf("Invalid format.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];
    int num_blocks = header.subchunk2Size / block_size;
    for (int i = 0; i < num_blocks; i++)
    {
        fseek(input, -(i + 1) * block_size, SEEK_END);
        fread(buffer, block_size, 1, input);
        fwrite(buffer, block_size, 1, output);
    }


    // Close files
    // TODO #9
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE check[] = {'W', 'A', 'V', '\0'};

    // Compare input header to "WAVE" marker characters found in the format member of the WAVHEADER struct
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != check[i])
        {
            // Format does not match, return 0 (false)
            return 0;
        }
    }

    // Format matches, return 1 (true)
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.bitsPerSample / 8 * header.numChannels;
}