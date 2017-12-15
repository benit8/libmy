#include <stdio.h>
#include <stdlib.h>
#include <Libmy.h>

int buffer_calc_lines(char *buffer)
{
	int l = 1;

	for (int i = 0; buffer[i] != '\0'; ++i){
		if (buffer[i] == '\n')
			l++;
	}
	return (l);
}

char **create_tab(char *buffer)
{
	char **tab;
	int rows = buffer_calc_lines(buffer);
	int start = 0;
	int size_w = 0;
	int j = 0;

	// Alloc de tab
	tab = malloc(sizeof(char *) * (rows + 1));
	if (!tab)
		return (NULL);
	// Copie du contenu
	for (int i = 0; j < rows && buffer[i] != '\0'; ++i, ++j){
		// On sauvegarde le début de la ligne dans `start`
		// et on avance `i` jusqu'a une nouvelle ligne (ou la fin du buffer)
		// (le `!strnchr` évite un `buffer[...] != '...' && ...` à rallonge)
		for (start = i; !str_nchr("\n\0", buffer[i], 2); ++i);
		// On calcule la longueur de la ligne
		size_w = i - start;
		// On alloue la ligne
		tab[j] = malloc(sizeof(char) * (size_w + 1));
		// On copie le contenu du buffer dans la ligne
		str_ncpy(tab[j], buffer + start, size_w);
		// Safety first
		tab[j][size_w] = '\0';
	}
	// Safety first
	tab[j] = NULL;
	return (tab);
}

int main(void)
{
	char *buffer = file_get_contents("zdoc/z2.doc");
	char **tab = create_tab(buffer);

	for (size_t i = 0; tab[i]; ++i) {
		printf("%lu: '%s'\n", i, tab[i]);
		free(tab[i]);
	}

	free(tab);
	my_free(buffer);
	return (0);
}