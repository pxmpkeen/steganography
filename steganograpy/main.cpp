#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

void to_bmp()
{
  FILE *ptr_bmp_in;
  FILE *ptr_text_out;
  int c;

  ptr_bmp_in = fopen("pt.bmp", "rb");
  ptr_text_out = fopen("ct.txt", "w");

  if (!ptr_bmp_in)
  {
    printf("Unable to open file\n");
    exit(1);
  }

  while ((c = fgetc(ptr_bmp_in)) != EOF)
  {
    for (int i = 0; i <= 7; i++)
    {
      if (c & (1 << (7 - i)))
      {
        fputc('1', ptr_text_out);
      }
      else
      {
        fputc('0', ptr_text_out);
      }
    }
  }

  fclose(ptr_bmp_in);
  fclose(ptr_text_out);
  printf("Writing done\n");
}

char bytefromtext(unsigned char *text)
{
  char result = 0;
  for (int i = 0; i < 8; i++)
  {
    if (text[i] == '1')
    {
      result |= (1 << (7 - i));
    }
  }
  return result;
}

void to_txt()
{
  FILE *ptr_txt_in;
  FILE *ptr_bmp_out;
  unsigned char buf[8];
  int c;
  int j = 0;

  ptr_txt_in = fopen("ct.txt", "r");
  ptr_bmp_out = fopen("pt.bmp", "wb");

  if (!ptr_txt_in)
  {
    printf("Unable to open file\n");
    exit(1);

    while ((c = fgetc(ptr_txt_in)) != EOF)
    {
      buf[j++] = c;
      if (j == 8)
      {
        fputc(bytefromtext(buf), ptr_bmp_out);
        j = 0;
      }
    }

    fclose(ptr_txt_in);
    fclose(ptr_bmp_out);
    printf("Writing done\n");
  }
}

void str_change() {

  ifstream txt_file("ct.txt");
  stringstream txt_file_contents;
  txt_file_contents << txt_file.rdbuf();
  string content = txt_file_contents.str(); 
  for(int i = 432; i <= content.length(); i++) {

  }
}

void decimalToBinary(int n, int* arr){
	int i = 0, num = n;
    // Until the value of n becomes 0.
	while(n != 0){
		arr[i] = n % 2;
		i++;
		n = n / 2;
	}
}

void encrypt() {
  string plain_text = "salam";
  int** pt_binary = new int[5][8];
  int plain_text_array[plain_text.length()];
  for(int i = 0; i<= plain_text.length(); i++) {
    plain_text_array[i] = int(plain_text[i]);
    
  }

  for(int i = 0; i <= plain_text.length(); i++) {
    cout << plain_text_array[i] << endl;
  }
}

int main(int argc, char **argv)
{
  encrypt();
  return 0;
}