#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	cout_w(char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			w++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			w++;
		i++;
	}
	return (w);
}

static char	**error(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
	return (NULL);
}

static void	put_word(char **res, char *s, int len, int j)
{
	int	i;

	res[j] = malloc(len + 1);
	if (!res[j])
	{
		error(res, j - 1);
		return ;
	}
	i = 0;
	while (i < len)
	{
		res[j][i] = s[i];
		i++;
	}
	res[j][i] = '\0';
}

static char	**put_words(char **res, char *s, char c)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			end = i;
			put_word(res, &s[start], end - start + 1, j);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w;

	if (!s)
		return (NULL);
	w = cout_w((char *)s, c);
	res = malloc((w + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (w == 0)
	{
		res[0] = NULL;
		return (&res[0]);
	}
	return (put_words(res, (char *)s, c));
}