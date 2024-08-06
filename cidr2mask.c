#include <stdio.h>
#include <stdlib.h>


void todotquad(unsigned int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;
    printf( "\nSubnet Mask in Dotquad: %d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);

}

void usage(){
	printf("\nUsage: cidr2mask <cidr>");
	printf("\nE.g.: cidr2mask 24");
}



void subnetmasker(int CIDR){
	//Allocate array to store binary representation of array, IPv4 is always 32 bit
        char bin[32];

	//Pointer to start of array to be used as iterator to preserve position in array between loops
        char * ptr = bin; 

	//Loop until iterator is equal to CIDR range
	//setting the value at the pointer to be 1 and incrementing pointer	
        for (int x = 0; x < CIDR; x++){
                *ptr = '1';
                ptr++;

        }

	//Iterate over the rest of the array while pointer does not equal address of the last element of the array.
        while (ptr < &bin[32]){

                *ptr = '0';
                ptr++;
        }
	bin[32] = '\0';
        printf("\nBinary Subnet Mask: %s", bin);
	printf("\nDecimal Subnet Mask: %lu", strtoul(bin, NULL, 2));
	todotquad(strtoul(bin, NULL, 2));

}


int main (int argc, char* argv[]){
	//We take exactly three args
	if (argc != 2){
		printf("\nError: Too many or Too Few arguments passed");
		usage();	
		return 1;
	}

	else{
		subnetmasker(strtol(argv[1], NULL, 0));
	}

	return 0;

}





