/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:27:51 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/22 13:15:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **split, int j)
{
	while (--j >= 0)
		free(split[j]);
	free(split);
	return (NULL);
}

static size_t	cont_words(char *s, char c)
{
	size_t	i;
	size_t	cont;

	i = 1;
	cont = 0;
	if (s[0] == '\0')
		return (cont);
	else if (s[0] != c && s[0] != '\0')
		cont++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			cont++;
		i++;
	}
	return (cont);
}

static size_t	cont_letters(char *s, char c, size_t pos)
{
	size_t	i;

	i = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		i++;
		pos++;
	}
	return (i);
}

static char	**intro_words(char **split, char *s, char c, size_t con)
{
	size_t	ikj[3];

	ikj[0] = 0;
	ikj[2] = 0;
	ikj[1] = 0;
	while (s[ikj[0]])
	{
		con = cont_letters(s, c, ikj[0]);
		if (con > 0)
		{
			split[ikj[2]] = (char *)malloc((con + 1) * sizeof(char));
			if (!split[ikj[2]])
				return (ft_free(split, ikj[2]));
			while (con--)
				if (s[ikj[0]] != c)
					split[ikj[2]][ikj[1]++] = s[ikj[0]++];
			split[ikj[2]++][ikj[1]] = '\0';
			ikj[1] = 0;
		}
		else
			ikj[0]++;
	}
	split[ikj[2]] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	size_t	cont;
	int		pos;

	pos = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	cont = cont_words(str, c);
	split = (char **)malloc((cont + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = intro_words(split, str, c, 0);
	if (!split)
		return (NULL);
	return (split);
}
/*
int main(void)
{
    char s[] = "xxxxxxxxxhexllo!";
    char c = 'x';

    char **split = ft_split(s, c);
    if (split == NULL)
    {
        printf("NULL\n");
        return (0);
    }

    int i = 0;
    while (split[i] != NULL)
    {
        printf("%s\n", split[i]);
        i++;
    }
    if (split != NULL)
    {
        int i = 0;
        while (split[i] != NULL)
        {
            free(split[i]);
            i++;
        }
        free(split);
    }
    return 0;
}*/
