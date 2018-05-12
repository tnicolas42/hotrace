#ifndef MAIN_H
#define  MAIN_H

# include <stdio.h> // TO DEL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdint.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# define BUFSIZE 4096

typedef struct	s_val
{
	int	nbval;
}				t_val;

int			ugo_strlen(char *str);
uint32_t	super_fast_hash(const char * data, int len);

#endif
