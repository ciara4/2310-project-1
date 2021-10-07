/*****************
Stephen Russell
SRUSSE5 
Ciara Morrissey
CIARA4 
CPSC 2310 F21 - section 002
PA1 - DUE OCT. 8
*****************/
/* This file is where we implement the functions listed in EncodeDecode.h */
#include <stdio.h>
#include <stdlib.h>
#include "./EncodeDecode.h"
#include "./utils.h"

/*
Parameters: 
    - pixel: pixel_t struct pointer to the pixel we want to modify
    - header: header_t struct of the pixel we want to modify
Returns:  
Removes the value of the ones place of each channel in the pixel 
and replaces it with 0. For example, if the red channel of the first pixel 
has an integer value of 255, it reduces the value by 5 to equal 250.*/
void removeDigit(pixel_t** pixel, header_t header){

};

/*
Parameters: 
    - in - 
Returns:  
Implements the logic described in the image in the PA1Specs document.
For each character, adds a 1 or 0 to the value of each of the three channels
for the three pixels. 

Steps:
1.	Declare necessary local variables
    - character counter, helpful when accessing the char * msg which holds 
      the literal string that represents the message you will encode. 
    - a bit counter
    - an int array to hold the 9 values that will be added to the 3 RGB 
      values for the 3 pixels
2.	Call writeHeader
3.	Use charToBinary() to convert each character in the message to its
    binary number equivalent.
4.	Encode the binary number in the image.
5.	After looping through all pixels, when there are no more characters left...
    Use writePixels() to write the new pixels to the output file 
    (You will need nested loops and some if statements for this function)
*/
void encodeMsg(FILE* in, FILE* out, char* msg){
    // step 1: declare variables
    // int charCounter = 0;
    // int bitCounter = 0;
    // int nineValsToBeAddedToThreeRGBPixels[9];

    // step 2: call writeHeader, passing in our original ppm's header
    header_t h = readHeader(in);
    writeHeader(out,h);
    // step 3: convert each character to its binary equivalent
    // INCOMPLETE. TODO: fini
    int msgLength = sizeof *msg / sizeof *msg;
    unsigned int *msgInBinarryArray = (unsigned int*)malloc(256 * sizeof(unsigned int));
    for(int i = 0; i < msgLength; i++){
        unsigned int *binaryRepresentation = NULL;
        // charToBinary(msg[i],binaryRepresentation); // This is the line causing segfault
        // add each binaryRep to an array of ints
        // msgInBinarryArray[i] = *binaryRepresentation;
        // printf("%d",msgInBinarryArray[i]);
    }

};

/*
Parameters:
Returns: void
// no comments provided in doc specs
*/
void charToBinary(char character, unsigned int *integer){
    int c = character;
	printf("c's binary value: ");
	for (int i = 0; i < 8; i++) {
		//*integer = *integer + 10*((c << i) & 0x80) ? 1 : 0;
    *integer = (c>>i) & 1 ? 1 : 0);
	}
};

/*
Parameters:
Returns:
Converts a binary number to decimal.
    - (Notice this is returned as an unsigned char...
       Remember we are working with three pixels which equals 9 bits,
       but the most significant bit is always 0. Why???)*/
unsigned char binToCharacter(int* integer){
    /*use strol to convert from a string into a long int*/
    /*parameters:  string containing the binary, the beginning & the base*/
    char c = strtol(integer, 0, 2);
    return c;

}
/* 
Parameters: 
Returns: void
(Called by decodeMsg... As the decodeMsg function grabs the onesdigit of each 
pixel channel (red,green, and blue) it passes that value to queue as “n”.)

Keeps track of the “n’s” passed to the function.

Notice bin is an array which should be of size 9.

An array created in decodeMsg is passed to queue, a.k.a. bin.

Also, “index” is a pointer that is pointing to a variable passed to 
queue by decodeMsg.

The queue function will continue to add the digit represented by “n” to bin
until 9 digits have been added.

Once 9 digits (1 or 0) are received you now have the binary bits needed 
to convert the content of bin to a character by calling binToCharacter. 

Obviously, the character returned from binToCharacter should be less than 256.

If the value retuned from binToCharacter is less than 256 then 
queue prints the character.
*/
void queue(int, int*, int*);

/* 
Parameters: 
Returns: void
Converts a decimal number to binary, storing the bits in an array. */ 
void dec2bin(int*, int);

/*
Parameters: 
Returns: void
1.	Calls readHeader() to read the header of the encoded ppm image
2.	Allocates the memory for the pixels of the encoded ppm image. 
        Suggestion:  you could create a function that allocates the memory 
        for the pixels then return the double pointer. 
3.	Uses readPixel() calls to read the pixels of the encoded ppm image,
    storing them in the memory it just allocated.
4.	Grabs the last digit of the red, green, and blue numbers, 
    saves them as integers (int red, int green, int blue)
5.	Sends each number it's grabbed to the queue function. 
6.	Continues this process for all pixels in the image.
    As an example:
    for the first red digit I grab I will:
        - call queue(digit, arr, address),
          where [digit] is the digit
                [arr] is an array that'll be used by queue to store this digit
            and [address] is the address of a variable that will be used to 
                keep track of the number of digits passed to queue.*/
void decodeMsg(FILE*);
