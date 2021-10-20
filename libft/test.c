#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "bonjour";
	char *s2 = "/lab8764";

	printf("%d", strncmp(s1, s2, 4));
}
