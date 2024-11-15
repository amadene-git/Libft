#include <libft.h>
#include <fcntl.h>
#include <errno.h>

static char **recusiveParsing(int fd, int recursionLevel)
{
    char *line = NULL;
    char **tab = NULL;
    int ret = get_next_line(fd, &line);
    
    if (ret == 0) {
        tab = malloc(sizeof(char*) * (recursionLevel + 2));
        tab[recursionLevel + 1] = NULL;
    }
    else if (ret == 1) {
        tab = recusiveParsing(fd, recursionLevel + 1);
    }
    tab[recursionLevel] = line;
    return (tab);
}

char **getFile(const char *filename)
{
    int fd;
    if ((fd = open(filename, O_RDONLY)) < 0) {
        ft_putendl_fd(strerror(errno), 2);
        return (NULL);
    }

    char **tab = recusiveParsing(fd, 0);
    close(fd);
    return (tab);
}