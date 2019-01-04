#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int my_lastline(int);


int my_firstline(int n)
{
  int increment;
  int i;
  int nbr;

  i = 1;
  increment = 4;
  nbr = 1;

 
  while (i < n)
   {
       if(i%2 == 0)
	{
	  increment = increment + 2;
	}
      
      nbr = nbr + increment;
      i++;
    }
  return nbr;
}


int my_lastline(int n)
{
  int increment;
  int i;
  int nbr;
  
  i = 1;
  increment = 6;
  nbr = 7;

  
  while (i < n)
    {
       if(i%2 == 0)
	{
	  increment = increment + 2;
	}
      
      nbr = nbr + increment;
      i++;
    }
  return nbr;
}

void display_line(int nb_stars,int nb_space) 
{
  int i;
  
  for(i = 0; i < nb_space; i++)
    {
      write(1," ",1);
    }
  for(i = 0; i < nb_stars; i++)
    {
      write(1,"*",1);
    }
  write(1,"\n",1);
}

void display_zone(int nbr,int max)
{
  int stars; // nbr d'étoiles
  int nbspace; // nbr d'espaces
  int i;
  int nbline; // nbr de lignes
  int line;

  nbline = 3 + nbr;
  
  stars = my_firstline(nbr);
  nbspace = (max/2) - (stars/2);

  for(line = 0; line < nbline; line++)
    {
      display_line(stars, nbspace);
      stars = stars + 2;
      nbspace--;
    }
}

void tronc(int n,int max)
{
  int i;
  int nb_space;
  int nb_tr;
  
  nb_tr = n;
  if(n%2 == 0)
      {
	nb_tr = nb_tr + 1;
      }
    
    nb_space = (max/2) - (nb_tr/2);

  for(int line = 0; line < n ; line++)
    {     
      for(i = 0; i < nb_space; i++)
	{
	  write(1," ",1);
	}
      for(i = 0; i < nb_tr ; i++)
	{
	  write(1, "|",1);
	}
      write(1,"\n",1);  
    }
}

void sapin(int size)
{
  int max = my_lastline(size);
  
  for(int i = 1; i <= size; i++)
    {
      display_zone(i, max);
    }
  tronc(size, max);
}


int main(int argc, char **argv)
{
  if(argc < 1)
    {
      return (42);
    }
  sapin(atoi(argv[1]));
}
