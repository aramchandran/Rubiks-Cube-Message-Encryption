#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector.h>
#include<fstream>
#include<algorithm>
#include<time.h>
using namespace std;
ofstream keyfile("key.txt");
char mat[6][4][4]={0},temp[4]={0},e[6][4][4]={0};
void encode();
void swapx();
void key()
{
  ifstream ifile("letterlist.txt");
  for (int x = 0 ; x <6; ++x)
      {
           for (int y = 0 ; y <4; ++y)
           {
               for (int z = 0 ; z <4; ++z)
               {
                   ifile >> noskipws >>mat[x][y][z];
                   e[x][y][z]=mat[x][y][z];
               }
           }
      }
ifile.close();
} 
int pseudoran()
{
    int r;
    r = (rand()%4);
    return r;
}
int pseudoran1()
{
    int r;
    r = (rand()%200);
    return r;
}
void swapx()
{
          for(int x=0; x<6; x++)
          {
                  for(int y=0; y<4; y++)
                  {
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector = pseudoran();
                                           keyfile << shiftvector <<" ";
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[shiftvector][y][z];
                                           e[shiftvector][y][z]=temp[z];
                                 }
                  }
          }
}
void swapy()
{
          for(int x=0; x<6; x++)
          {
                  for(int y=0; y<4; y++)
                  {
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector = pseudoran();
                                           keyfile << shiftvector <<" ";
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[x][shiftvector][z];
                                           e[x][shiftvector][z]=temp[z];
                                 }
                  }
          }
}          
void swapz()
{          
          for(int x=0; x<6; x++)
          {       
                  for(int y=0; y<4; y++)
                  {
                                 
                                 for(int z=0; z<4; z++)
                                 {
                                           int shiftvector = pseudoran();
                                           keyfile << shiftvector <<" ";
                                           temp[z]=e[x][y][z];
                                           e[x][y][z]=e[x][y][shiftvector];
                                           e[x][y][shiftvector]=temp[z];
                                 }
                  }
          }
}
int main()
{
int i=0,n=0,n1=0,n2=0;
srand(time(NULL));
key();
n=pseudoran1();
keyfile<< n <<" ";
for(i=0;i<n+1;i++)
{
swapx();
swapy();
swapz();
}
n1=pseudoran1();
keyfile<< n1<<" ";
for(i=0;i<n1+1;i++)
{
swapx();
swapy();
swapz();
}
n2=pseudoran1();
keyfile<< n2<<" ";
for(i=0;i<n2+1;i++)
{
swapx();
swapy();
swapz();
}     
      cout<<"\n WELCOME TO THE RUBIX CRYPT!";
      ifstream is("plaintext.txt");   
      char c;
      ofstream ofile("ciphertext.txt");
      while (is.get(c))        
      for (int x = 0 ; x <6; ++x)
              {
                  for (int y = 0 ; y <4; ++y)
                  {
                      for (int z = 0 ; z <4; ++z)
                      {
                          
                          if(mat[x][y][z] == c)
                          {
                            ofile << noskipws<<e[x][y][z];
                          }
                      }
                  }
              }

      is.close();               
      ofile.close();
      keyfile.close();
      cout<<"\nThe key for decryption is stored in key.txt...\n";
      cout<<"\nCiphertext is stored in ciphertext.txt\n";           
      getch();
}     
