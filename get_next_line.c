#include "get_next_line.h"

static int	ft_endline(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != '\n' && buff[i])
    i++;
  if (buff[i] == '\n')
  {
    buff[i] = '\0';
    return (i);
  }
  else
    return (-1);
}

static char	*join(char *buff, char *tmp)
{
  size_t	i;
  size_t	j;
  char		*ptr;

  i = 0;
  j = 0;
  if (buff)
    i = ft_strlen(buff);
  if (tab)
    j = ft_strlen(tab);
  ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
  ft_memcpy(ptr, buff, i);
  ft_memcpy(ptr + i, tab, j);
  ptr[i + j] = '\0';
  free(buff);
  ft_bzero(tab, BUFF_SIZE + 1);
  return (ptr);
}

static int	ft_check(char **buff, char **tmp, char **line)
{
  char		*ptr;
  int		final;

  *buff = ft_join(*buff, *tmp);
  final = ft_endline(*buff);
  if (final > -1)
  {
    *line = ft_strdup(*buff);
    ptr = *buff;
    *buf = ft_strdup(*buff + final + 1);
    free(ptr);
    return (1);
  }
  return (0);
}

int		get_next_line(int const fd, char **line)
{
  static char	*buff[256];
  char		*tmp;
  int		res;
  int		ret;

  tmp = ft_strnew(BUFF_SIZE);
  if (BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
    return (-1);
  while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
  {
    res = ft_check(&buff[fd], &tmp, line);
    free(tmp);
    if (res == 1)
      return (1);
    tmp = ft_strnew(BUFF_SIZE);
  }
  if ((res = ft_check(&buff[fd], &tmp, line)))
    return (1);
  else if (ft_strlen(buff[fd]) > 0)
  {
    *line = ft_strdup(buff[fd]);
    ft_strdel(&buff[fd]);
    return (1);
  }
  return (res);
}
