/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 07:40:26 by minsokim          #+#    #+#             */
/*   Updated: 2020/06/18 06:40:17 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct	s_map_info
{
	int scale_x;
	int scale_y;
	char **map;
}				t_map_info;

typedef struct	s_map
{
	char space;
	char obstacle;
	char fill;
	t_map_info info;
}				t_map;

typedef struct	s_square_info
{
	int size;
	int x;
	int y;
}				t_square_info;

typedef struct	s_dynamic
{
	t_square_info square;
	int *dp_table;
	int	dp[2];
	int x;
	int y;
}				t_dynamic;

typedef struct	s_fd
{
	int	fd;
	int *buffer;
	int file;
}				t_fd;

int		ft_compare(int a, int b, int c);
void 	set_result(int size, int x, int y, t_dynamic *dp);
int 	set_dp_table_first_line(t_map *map, t_dynamic *dp);
int 	set_dp(t_dynamic *dp, t_map *map);
int		bsq(t_dynamic *dp, t_map *map);

void 	parse_stdin(void);
int		parse_file(char *argv);

int		ft_strlen(char *str);
char 	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_strcat(char *desti, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_atoi(char *str);

int main(int argc, char **argv);

void	memory_free_map(t_map *map, t_dynamic *dp);
int 	memory_malloc_dp(t_dynamic *dp, int xscale);
int		memory_make_map(t_map *map, int pos, t_fd *fd);

char	*read_stdin(int fd);
char	*ft_make_file(char *file, char *buf, int file_size, int read_size);
char	*realloc_buf(char *buf, int buf_size);
int		open_file(char *argv);

void	print_error();
void    print_map(t_map *map);
void	fill(t_dynamic *dp, t_map *map);

int	make_map_info(t_map *map, t_fd *fd);
int		readmap_valid_check(t_map *map, t_fd *fd);
int	memory_make_map(t_map *map, int pos, t_fd *fd);
int pass_firstline(char *file);
int cnt_enter(char *file);

#endif