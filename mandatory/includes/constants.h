/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:23:00 by alaualik          #+#    #+#             */
/*   Updated: 2025/07/04 16:16:28 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// Window settings
# define WIN_W 1024
# define WIN_H 768

// Colors
# define GREY 0x00A0A7A5
# define GRASS 0x00B1E1A1
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define INVISIBLE 0x00FF00FF

// Map elements
# define E_WALL '1'
# define E_INSIDE '0'
# define E_EMPTY ' '
# define E_NORTH 'N'
# define E_SOUTH 'S'
# define E_WEST 'W'
# define E_EAST 'E'

// Game mechanics
# define FOV_DEGREES 66
# define FOV_SCALE 0.649407f
# define ROTATION_SPEED 0.15f
# define MOVEMENT_SPEED 0.13f
# define MOVEMENT_SECURITY 0.2f

// Keys
# define K_ESCAPE 65307
# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100

// Math
# define PI 3.14159265358979323846f

// Parsing
# define VISITED 'X'

# define BONUS_NAME "cub3D_bonus"

// Textures
# define TEXTURE_SIZE 1024

// Error messages

# define MSP_OPEN "Error\n opening file"
# define MSP_INVALID_COLOR "Error\ninvalid color"
# define MSP_INVALID_FILENAME "Error\ninvalid filename"
# define MSP_IVF "Error\ninvalid map path"
# define MSP_IVL "Error\ninvalid configuration line"
# define MSP_IVM "Error\ninvalid map line"
# define MSP_IVC "Error\ninvalid content after configuration"
# define MSP_UNK "Error\nUnknown or misplaced element in .cub file"
# define MSP_ELM "Error\nempty line in map content"
# define MSP_MISSING "Error\nmissing informations"
# define MSP_NOT_CLOSED "Error\nmap is not closed or player not inside"
# define MSP_MPP "Error\nmultiple player positions"
# define MSP_MIP "Error\nmissing player position"
# define MSP_PIM "Error\nplayer must be inside the map"
# define MSP_ERR "Error\nparsing error"
# define MSG_USAGE "Error\nusage cub3D <map path>"
# define MSG_EMPTY_ENV "Error\nempty env var"
# define MSG_ALLOC "Error\nmemory allocation error"
# define MSP_DFC "Error\nduplicate floor color"
# define MSP_DCC "Error\nduplicate ceiling color"
# define MSG_DTP "Error\nduplicate texture path"
# define MSG_MTP "Error\nmissing texture path"
# define MSG_DCC "Error\nduplicate ceiling color"
# define MSG_EXC "Error\nextra content after texture path"
# define MSG_TEX "Error\nadding texture"

#endif
