#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int freq(int *a)
{int countmax=0,max=0;
 for(int i=0;i<26;i++)
    {if(countmax<a[i])
	{countmax=a[i];
	  max=i;
		}
	    }
  int key=(max+22)%26;
  return key;
}

int main(int argc, char ** argv)
{
  if(argc != 2)
    {fprintf(stderr,"Invalid argc\n");
      return EXIT_FAILURE;
    }

  FILE *f=fopen(argv[1], "r");
  if(f==NULL)
    {fprintf(stderr,"Could not open the file\n");
      return EXIT_FAILURE;
    }

   int a[26]={0};
  int b;
  while((b=fgetc(f)) != EOF)
    {if(isalpha(b))
	{b=tolower(b);
	  b = b - 'a';
      a[b]=a[b]+1;
	}
    }
  
  int k=freq(a);

  if(k>=0 && k<26)
    {fprintf(stdout,"%d\n",k);
    }
  if(k<0 && k>=26)
    { fprintf(stderr,"Key not in range\n");
      return EXIT_FAILURE;
    }
  if(fclose(f) != 0) {
    fprintf(stderr,"Failed to close the input file!\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

