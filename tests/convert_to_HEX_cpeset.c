#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_char(int c)
{
    if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
        return (-1);
    return (1);
}

static int    ft_ptr(unsigned long long nbr)
{
    ssize_t    bytes;

    if (nbr >= 16)
    {
        ft_ptr(nbr / 16);
        ft_ptr(nbr % 16);
    }
    else
    {
        if (nbr <= 9)
        {
            bytes = ft_char(nbr + '0');
            if (bytes == -1)
                return (-1);
        }
        else
        {
            bytes = ft_char(nbr - 10 + 'a');
            if (bytes == -1)
                return (-1);
        }
    }
    return (0);
}


int main() {
  
  int   a = 985998441;  
  int   b;
//  void  *ptr = &a;
    
  b = ft_ptr(a);
  printf("\n\n%%x of 985998441 = %x\n", a);
  return 0;
}
