/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:59:13 by margaritaso       #+#    #+#             */
/*   Updated: 2022/02/28 04:26:59 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEY_MACROS_H
# define FDF_KEY_MACROS_H

# define A_KEY		0
# define S_KEY	 	1
# define D_KEY	 	2
# define Q_KEY	 	12
# define W_KEY	 	13
# define E_KEY	 	14
# define PLUS_KEY 	24
# define MINUS_KEY 	27

# define ONE_KEY 	18
# define TWO_KEY 	19

# define L_ARROW	123
# define R_ARROW	124
# define D_ARROW	125
# define U_ARROW	126

# define ESC_KEY 	53
# define SPACE_KEY 	49

# define ON_DESTROY	17

void	manage_rotation(int key, t_fdf *params);
void	map_rotation(int *x, int *y, int *z, t_map *map);

#endif
