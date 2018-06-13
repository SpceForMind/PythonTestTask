
#include <stdio.h>

#pragma pack(push, 1)
typedef struct file_header
{
	unsigned short signature;
	unsigned int file_size;
	unsigned short reserverd1;
	unsigned short reserved2;
	unsigned int offset_to_pixel_arr;
} FileHeader;


typedef struct 
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}Rgb;


typedef struct
{
	FileHeader file_header;
	//
	Rgb **array;
} Bmp;

#pragma pack(pop)

void printFileHeader(FileHeader header)
{
	printf("signature:\t %x (%hu)\n", header.signature, header.signature);
	printf("filesize:\t %x (%u)\n", header.file_size, header.filei_size);
	printf("reserved1:\t %x (%hu)\n", header.reserved1, header.reserved1);
	printf("reserved2:\t %x (%hu)\n", header.reserved2, header.reserved2);
	printf("offset:\t %x (%hu)\n", header.signature, header.signature);
}


int main()
{
	FileHeader header;
//	FILE *file = fopen("", "rb");
	
	//fread(&header, sizeof(FileHeader), 1, f);
//	fclose(file);

	return 0;
}
