/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:28:46 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 22:09:17 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_dict
{
	char			*nbr;
	char			*text;
	struct s_dict	*next;
	struct s_dict	*prev;
}				t_dict;

char			*work(int argc, char **argv, char **dict_name);
void			ch_val(t_dict **i, t_dict **j);
t_dict			*reader(char *path);
t_dict			*create_new_list(void);
char			*key_former(char *buffer, int *point);
char			*value_former(char *buffer, int *point);
t_dict			*former(char *buffer);
void			string_corrector(char *buf, char *value, int *zero, int *nul);
char			*check_nbr(char *str);
void			sort_dict(t_dict **dict);
int				eject_twins(t_dict **dict);
int				if_every_key(t_dict *dict);
void			nbr_to_text(char *nbr, t_dict *dict);
int				if_every_key2(t_dict *dict);
int				seek(t_dict *dict, char *c1);
int				len(char *s);
int				compare_str(char *s1, char *s2);
char			*search(char *nbr, t_dict *dict);
void			nbr_out(char *s);
int				if000(char *nbr, t_dict *dict);
void			ifn00(char *nbr, t_dict *dict, int i);
void			if01n(char *nbr, t_dict *dict, int i);
void			if00n(char *nbr, t_dict *dict, int i);
void			if0nn(char *nbr, t_dict *dict, int i);
int				check_poryadok(char *nbr, int size);
int				check_n(char *nbr);
int				check_nn(char *nbr, int size);
int				len(char *s);
int				check_100(char *nbr, int size);
void			eject(t_dict **dict);

#endif
