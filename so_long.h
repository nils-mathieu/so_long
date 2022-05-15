/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/15 21:36:55 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <time.h>

// The number of images that have to be loaded within a `t_game` instance.
# define IMAGE_COUNT 3

// ========================================================================== //
//                                Useful Typedefs			                  //
// ========================================================================== //

// A pointer to the data of an MLX instance. An instance of this type is
// returned by `mlx_init`.
//
// This pointer should be passed to the `mlx_destroy_display` and `free`
// functions when it is not needed anymore.
typedef void			*t_mlx;

// A pointer to the data of an active window, managed by a `t_mlx` instance.
//
// This pointer should be passed to the `mlx_destory_window` function when it is
// not needed anymore.
typedef void			*t_win;

// A pointer to the data of a loaded image, managed by a `t_mlx` instance.
//
// This pointer should be passed to the `mlx_destroy_image` once it is not
// needed anymore.
typedef void			*t_img;

// A simle type alias for the `struct timeval` type defined in `time.h`.
typedef struct timespec	t_instant;

// ========================================================================== //
//                                 	  Math                                    //
// ========================================================================== //

// A position within the game world.
typedef struct s_float_position
{
	float	x;
	float	y;
}	t_fpos;

/// A discrete position within the game world.
typedef struct s_uint32_position
{
	uint32_t	x;
	uint32_t	y;
}	t_upos;

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

// A fully parsed map.
typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;

	t_upos		player;
	t_upos		exit;

	size_t		coin_count;
	t_upos		*coins;
	size_t		wall_count;
	t_upos		*walls;
}	t_map;

// Stores the state required when reading a map.
typedef struct s_map_parser
{
	uint32_t	players;
	uint32_t	exits;
	bool		is_rectangle;
	bool		is_enclosed;
	bool		contains_invalid_character;
	char		invalid_character;

	size_t		line_len;
	size_t		coins_cap;
	size_t		walls_cap;
	t_map		map;
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

// Identifies an image loaded for a `t_game`.
//
// Those values can be used as indices for the `image` field.
typedef enum e_game_image
{
	SL_GIMG_PLAYER,
	SL_GIMG_EXIT,
	SL_GIMG_COIN,
}	t_gimg;

// Stores the state of the game.
typedef struct s_game
{
	t_mlx		mlx;
	t_win		win;

	t_img		images[IMAGE_COUNT];

	uint32_t	width;
	uint32_t	height;

	t_instant	frame_last_instant;
	float		delta_time;

	bool		pressing_up;
	bool		pressing_down;
	bool		pressing_right;
	bool		pressing_left;
	t_fpos		player_pos;
}	t_game;

// An error that might occur during the game's execution.
typedef enum e_game_error
{
	SL_GERR_SUCCESS,
	SL_GERR_MLX,
	SL_GERR_IMAGE,
}	t_gerr;

// Loads `IMAGE_COUNT` images into `images`.
bool	sl_load_images(t_mlx mlx, t_img *images);

// Starts the game for the provided *valid* map.
//
// This function will only return once the game instance is closed.
t_gerr	sl_game_start(t_map *map);

// Computes the amout of time since `prev`, in seconds.
//
// `prev` is updated to the current instant.
float	sl_delta_time(t_instant *prev);

// Advances the game by one frame. This function is called by the event loop
// of MiniLibX.
//
// This includes updating the game world and drawing the next frame.
int		sl_loop_hook(t_game *game);

// Stops the MiniLibX event loop. This is called by MLX when the users wants
// the window to be closed.
int		sl_destroy_hook(t_game *game);

// Handle the player's key presses. This is called by MLX when the user presses
// a key.
int		sl_key_press_hook(unsigned long keysym, t_game *game);

// Handle the player's key presses. This is called by MLX when the user presses
// a key.
int		sl_key_release_hook(unsigned long keysym, t_game *game);

#endif