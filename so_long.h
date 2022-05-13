/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:46:27 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stddef.h>

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
	SL_TILE_WALL,
	SL_TILE_FLOOR,
	SL_TILE_COIN,
	SL_TILE_EXIT,
	SL_TILE_PLAYER,
}	t_tile;

// A collection of error that might occur whilst parsing a map.
typedef enum e_parsing_error
{
	SL_PERR_SUCCESS,
	SL_PERR_CANT_READ,
	SL_PERR_MISSING_WALL,
	SL_PERR_NOT_A_RECTANGLE,
}	t_perr;

// A fully parsed map.
typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_tile	*tiles;
}	t_map;

// Parses a map defined in the provided file descriptor.
t_perr	sl_parse_map(int fd, t_map *map);

// Frees the resources allocated for a `t_map` instance. The provided map must
// come from a successful call to `sl_pase_map`.
t_perr	sl_free_map(t_map *map);

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
bool	sl_init_game(t_game *game, t_map *map);

// Frees the resources allocated for a `game` instance using the `sl_init_game`
// function.
void	sl_deinit_game(t_game *game);

#endif