#ifndef		GET_GETXT_LINE_H
# define	GET_NEXT_LINE_H

# include	"libft/includes/libft.h"
# include	<sys/types.h>
# include	<sys/uio.h>
# include	<unistd.h>
# include	<fcntl.h>
# define	BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
