#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static char	**ft_goingfree(char **ptr, int len)
{
	int	i;

	i = 0;
	while (len > i)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

// Función que usamos para conocer el tamaño de cada "palabra" que esta delimi-
// tada por el carácter c.

static int	ft_wcount(char const *s, char c)
{
	size_t	i;
	int		nbr_w;

	i = 0;
	nbr_w = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				++nbr_w;
			++i;
		}
	}
	return (nbr_w);
}

// Función que recorre la array de 2 dimensiones para alocar la memoría
// necesaria mediante el uso de la función malloc. En caso de que falle la
// alocación de memoria, llamaremos a nuestra implementación de la función
// free y así vaciar el contenido hasta ese momento alocado.

static char	**ft_mem_alloc(char const *s, char c)
{
	char	**sptr;
	int		i;
	int		j;
	int		idx;

	sptr = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!sptr)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_wcount(s, c))
	{
		idx = 0;
		while (s[j] == c)
			j++;
		while ((s[j] && s[j] != c)
			&& ((j == 0 && s[j] != c) || (s[j] != c)) && idx++ != -1)
			j++;
		sptr[i] = (char *)malloc(sizeof(char) * (idx + 1));
		if (!sptr[i])
			return (ft_goingfree(sptr, i));
	}
	return (sptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		idx;

	ptr = ft_mem_alloc((char *)s, c);
	if (!ptr || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_wcount((char *)s, c))
	{
		idx = 0;
		while ((char)s[j] == c)
			j++;
		if ((j == 0 && (char)s[j] != c) || ((char)s[j] != c && (char)s[j]))
		{
			while ((char)s[j] && (char)s[j] != c)
				ptr[i][idx++] = (char)s[j++];
			ptr[i][idx] = '\0';
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
