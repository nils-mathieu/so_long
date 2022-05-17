/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:28:33 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 01:26:16 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <time.h>

// ========================================================================== //
//                               Game Rules                                   //
// ========================================================================== //

// The target amount of time between two frames, in nanoseconds.
# define TARGET_DELTA 16666667
// The maximum amout of time allowed between frames.
# define MAX_DELTA_TIME 20000000

// The force applied on the player when a key is pressed.
# define PLAYER_ACCELERATION_FORCE 60.0f
// The coef applied to the velocity to determine how quickly the player should
// stop when they are doing nothing.
# define PLAYER_DRAG_AMOUNT 0.97f

// The width of the player's collider.
# define PLAYER_COL_W 0.6f
// The height of the player's collider.
# define PLAYER_COL_H 0.6f

// The bounciness of walls.
# define BOUNCE_AMOUNT 10.0f
// The amount of time the player is unable to control the ship once it have
// bounced against a wall.
# define RECOIL_DURATION 0.3f

// The amount of room given to the physics engine.
# define PHYSICS_ROOM 1.001f

// The size of the collider of coins.
# define COIN_COL_R 0.8f

// The size of the collider of the exit portal.
# define EXIT_COL_R 1.0f

// The number of pixels each unit of the game world takes.
# define PIXELS_PER_UNIT 24.0f

// The speed of the camera.
# define CAMERA_SPEED 0.1f

// The width of the window.
# define WIDTH 1280
// The height of the window.
# define HEIGHT 720

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

// ========================================================================== //
//                                 	  Math                                    //
// ========================================================================== //

// Linearly interpolates between `a` and `b`.
float	sl_lerp(float a, float b, float t);

// A position within the game world.
typedef struct s_float_position
{
	float	x;
	float	y;
}	t_fpos;

// Computes the squared distance between `a` and `b`.
float		sl_sqdist(t_fpos a, t_fpos b);

// A vector.
typedef struct s_float_vector
{
	float	x;
	float	y;
}	t_fvec;

/// A discrete position within the game world.
typedef struct s_uint32_position
{
	uint32_t	x;
	uint32_t	y;
}	t_upos;

/// A discrete rectangle.
typedef struct s_rectangle
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	width;
	uint32_t	height;
}	t_rect;

// A color, encoded as an RGBA array of `uint8_t`s.
//
// The RGBA - Value transmutation expects a little endian system.
typedef struct s_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgba;

// ========================================================================== //
//                                 	Parsing                                   //
// ========================================================================== //

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
t_perr		sl_parse_map(int fd, t_map_parser *p);

// Parses a single byte for a map.
//
// If the function returns `false`, then the system is out of memory.
bool		sl_parse_byte(uint8_t byte, t_map_parser *p);

// Frees the resources allocated for a properly initialized `t_map_parser`
// instance.
void		sl_free_map_parser(t_map_parser *p);

// Prints to the standard error an error describing why the provided map was
// rejected.
void		sl_print_map_error(t_map_parser *p);

// ========================================================================== //
//                                Game State                                  //
// ========================================================================== //

// The number of images that have to be loaded within a `t_game` instance.
# define IMAGE_COUNT 4

// Identifies an image loaded for a `t_game`.
//
// Those values can be used as indices for the `image` field.
typedef enum e_game_image
{
	SL_GIMG_PLAYER,
	SL_GIMG_EXIT,
	SL_GIMG_COIN,
	SL_GING_WALL,
}	t_gimg;

// Represents a game canvas.
typedef struct s_image_and_address
{
	t_img		image;
	uint8_t		*addr;
	uint32_t	line_len;
}	t_imgi;

// Stores the state of the game.
typedef struct s_game
{
	t_mlx		mlx;
	t_win		win;

	t_imgi		images[IMAGE_COUNT];
	t_imgi		canvas;

	uint32_t	width;
	uint32_t	height;

	uint64_t	frame_last_instant;
	float		delta_time;

	size_t		wall_count;
	t_fpos		*walls;

	size_t		max_coins;
	size_t		rem_coins;
	t_fpos		*coins;


	t_fpos		exit;

	bool		pressing_up;
	bool		pressing_down;
	bool		pressing_right;
	bool		pressing_left;
	float		recoil_duration;
	t_fvec		movement_input;
	t_fpos		camera_pos;
	t_fvec		player_vel;
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
bool		sl_load_images(t_mlx mlx, t_imgi *images);

// Starts the game for the provided *valid* map.
//
// This function will only return once the game instance is closed.
t_gerr		sl_game_start(t_map *map);

// Ges the current timestamp, in microseconds.
uint64_t	sl_get_current_timestamp(void);

// Computes the amout of time since `prev`, in seconds.
//
// `prev` is updated to the current instant.
float		sl_delta_time(uint64_t *prev);

// Advances the game by one frame. This function is called by the event loop
// of MiniLibX.
//
// This includes updating the game world and drawing the next frame.
int			sl_loop_hook(t_game *game);

// Stops the MiniLibX event loop. This is called by MLX when the users wants
// the window to be closed.
int			sl_destroy_hook(t_game *game);

// Handle the player's key presses. This is called by MLX when the user presses
// a key.
int			sl_key_press_hook(unsigned long keysym, t_game *game);

// Handle the player's key presses. This is called by MLX when the user presses
// a key.
int			sl_key_release_hook(unsigned long keysym, t_game *game);

// Properly move the player within the game world, preventing them from
// going through walls.
void		sl_move_player(t_game *game);

// Renders the curremt game state on the screen.
void		sl_render_game(t_game *game);

// Detects whether the player can collect any coin.
void		sl_collect_coins(t_game *game);

// If the player has finished and is on the finish line, the game ends.
void		sl_finish(t_game *game);

// Returns the position of the camera.
t_fpos		sl_camera_pos(t_game *game);

// Renders the player.
void		sl_render_player(t_fpos camera, t_game *game);

// Renders coins on the screen.
void		sl_render_coins(t_fpos camera, t_game *game);

// Renders the final portal.
void		sl_render_portal(t_fpos camera, t_game *game);

// Renders the walls.
void		sl_render_walls(t_fpos camera, t_game *game);

// Updates the position of the camera.
void		sl_update_camera(t_game *game);

// ========================================================================== //
//                                Rendering                                   //
// ========================================================================== //

// Creates a new empty image.
bool		sl_create_image(t_mlx mlx, uint32_t w, uint32_t h, t_imgi *result);

// Loads a new image from a file in the XPM format.
bool		sl_load_image(t_mlx mlx, const char *s, t_imgi *result);

// Converts a position from world-space to screen-space.
t_upos		sl_pos_to_screen(t_fpos camera, t_fpos pos);

// Puts a portion of `src` into the canvas.
//
// If part of the image would be outside of the canvas, it is not drawn.
void		sl_put_image(t_game *game, t_upos dst, t_imgi *simg, t_rect src);

#endif
