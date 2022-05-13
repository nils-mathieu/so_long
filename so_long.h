/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/14 00:49:06 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>

// ========================================================================== //
//                                Useful Typedefs			                  //
// ========================================================================== //

// A pointer to the data of an MLX instance. An instance of this type is
// returned by `mlx_init`.
//
// This pointer should be passed to the `mlx_destroy_display` and `free`
// functions when it is not needed anymore.
typedef void	*t_mlx;

// A pointer to the data of an active window, managed by a `t_mlx` instance.
//
// This pointer should be passed to the `mlx_destory_window` function when it is
// not needed anymore.
typedef void	*t_win;

// A pointer to the data of a loaded image, managed by a `t_mlx` instance.
//
// This pointer should be passed to the `mlx_destroy_image` once it is not
// needed anymore.
typedef void	*t_img;

// ========================================================================== //
//                                   Math                                     //
// ========================================================================== //

// A discrete position within the game world.
typedef struct s_pos
{
	uint32_t	x;
	uint32_t	y;
}	t_pos;

// ========================================================================== //
//                                 	Parsing                                   //
// ========================================================================== //

// A tile that may be defined in a map file.
typedef enum e_tile
{
	SL_TILE_FLOOR,
	SL_TILE_WALL,
	SL_TILE_COIN,
	SL_TILE_EXIT,
	SL_TILE_PLAYER,
}	t_tile;

// A collection of error that might occur whilst parsing a map.
typedef enum e_parsing_error
{
	SL_PERR_SUCCESS,
	SL_PERR_CANT_READ,
	SL_PERR_OUT_OF_MEMORY,
	SL_PERR_INVALID_MAP,
}	t_perr;

// Stores the state required when reading a map.
typedef struct s_map_parser
{
	uint32_t	players;
	uint32_t	coins;
	uint32_t	exits;
	bool		is_rectangle;
	bool		is_enclosed;
	bool		contains_invalid_character;
	char		invalid_character;

	uint32_t	width;
	uint32_t	height;

	uint32_t	line_len;
	size_t		cap;
	t_tile		*tiles;
}	t_map_parser;


// Parses a map defined in the provided file descriptor.
//
// Whatever happens, once this function has returned, the initialized
// `t_map_parser` instance should be freed using the `sl_free_map_parser`
// function.
t_perr	sl_parse_map(int fd, t_map_parser *p);

// Parses a single byte for a map.
//
// If the function returns `false`, then the system is out of memory.
bool	sl_parse_byte(uint8_t byte, t_map_parser *p);

// Frees the resources allocated for a properly initialized `t_map_parser`
// instance.
void	sl_free_map_parser(t_map_parser *p);

// Prints to the standard error an error describing why the provided map was
// rejected.
void	sl_print_map_error(t_map_parser *p);

// ========================================================================== //
//                                Game State                                  //
// ========================================================================== //

// A image associated to a position within the game world.
typedef struct s_sprite
{
	t_img	img;
	t_pos	*pos;
}	t_sprite;

// Stores the state of the game.
typedef struct s_game
{
	t_mlx		mlx;
	t_win		win;

	t_img		player_image;
	t_img		floor_image;
	t_img		wall_image;
	t_img		coin_image;
	t_img		exit_image;

	uint32_t	width;
	uint32_t	height;

	t_sprite	*sprites;
}	t_game;

// Initializes a `t_game` instance.
//
// This function returns whether the operation is a success, and in that case,
// the initialized `t_game` instance should be passed to the `sl_deinit_game`
// function.
bool	sl_init_game(t_game *game, t_tile *tiles, uint32_t w, uint32_t h);

// Frees the resources allocated for a `game` instance using the `sl_init_game`
// function.
void	sl_deinit_game(t_game *game);

#endif