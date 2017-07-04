/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 20:48:09 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/03 12:12:08 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYPER_HEADER_H
# define HYPER_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"

# define MAX_PATH 512
# define C_RED			"\x1b[31m"
# define COLOR_GREEN   	"\x1b[32m"
# define C_YE			"\x1b[33m"
# define COLOR_BLUE    	"\x1b[34m"
# define COLOR_MAGENTA 	"\x1b[35m"
# define COLOR_CYAN    	"\x1b[36m"
# define C_RES			"\x1b[0m"
# define BOLD			"\x1b[1m"

typedef	struct	s_hard_soft
{
	int hard;
	int soft;
}				t_state;

void			power_gers(char **av, char ***env, char *t_path, char *r_path);
void			ft_echo_help(char *str, int *i, char **env, t_state *status);
void			set_pwd(char *path, char ***env);
void			set_env(char ***en, char *s);
void			unset_env(char ***s, char *key);
void			ft_echo(char *str, char **env);
int				valid_dir(char *av);
int				ft_env(char **env);
int				cd(int ac, char **av, char ***env);
int				cd_minus(char ***env);
int				cd_relative(char ***env, char *r_path, char **av);
int				cd_absolute(char **av, char ***env);
int				cd_hometilda(char ***env, char *r_path, char *temp_path, int i);
int				cd_double_dot(char ***env, char *r_path, char *t_path);
int				cd_absolute_tilda(char ***env, char **av, char *r_p, char *t_p);
char			*search_path(char *cmd, char **env);
char			*extract_path(char **env, char *field, int offset);
char			*good_path(char **splitted_path, DIR *p_dir, char *cmd);

#endif
