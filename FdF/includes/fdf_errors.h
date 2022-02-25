/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:16:28 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/23 14:04:09 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ERRORS_H
# define FDF_ERRORS_H

# include <errno.h>
# include <stdio.h>

# define WRONG_ARGS "Error: Only one argument is expected."
# define WRONG_EXT "Error: Wrong extension. *.fdf file is expected."
# define ERROR_OPEN "Error open()"
# define ERROR_MALLOC "Error malloc()"

void	error_handler(const char *message);

#endif
