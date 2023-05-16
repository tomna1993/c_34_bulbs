#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BYTE_LENGTH = 8;

// If false -> print numbers
// If true -> print bulbs 
const bool PRINT_BULBS = false;

void print_bulbs(string text);

int main(void)
{
	// Get text from user
	string user_text = get_string("Message: ");

	// Convert text to binary and print out the result with bulbs
	print_bulbs(user_text);

	return 0;
}

void print_bulbs(string text)
{
	// Iterate through the given text
	for (int char_count = 0, length = strlen(text); char_count < length; char_count++)	
	{
		// Save the character's decimal value in a variable
		int char_dec = text[char_count];

		// Declare an array to save the converted decimal number
		int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};

		// In decimal to binary conversion we calculate the LSB first
		// and MSB last, so we have to fill the array from the last index
		for (int i = BYTE_LENGTH - 1; i >= 0; i--)	
		{
			// To get the binary number we have to divide the decimal number
			// with 2 then save the remainder - we can do that with modulus
			if (char_dec % 2)
			{
				binary[i] = 1;
			}

			// Divide the number with 2 and save the truncated result
			char_dec /= 2;
		}

		// If false -> print numbers
		// If true -> print bulbs 
		if (PRINT_BULBS)
		{
			// Iterate through the binary array and print black or yellow circles
			for (int j = 0; j < BYTE_LENGTH; j++)
			{
				if (binary[j])
				{
					printf("\U0001F7E1");
				}
				else
				{
					printf("\U000026AB");
				}
			}
		}
		else
		{
			// Iterate through the binary array and print 0s or 1s 
			for (int j = 0; j < BYTE_LENGTH; j++)
			{
				if (binary[j])
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
		}

		// Print each character's binary representation into a new row
		printf("\n");
	}
}