#ifndef FLR_VISUAL_H
# define FLR_VISUAL_H

# include "libft.h"
# include "Audio.h"
# include "Graphics.h"
# include "flr_loadfile.h"
# include "flr_human_player.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>

# define MARGIN			40
# define CELL_SZ		30
# define NAME_MAX		16
# define P_FONT_SZ		80

# define FLR_FIN		1
# define FLR_MUSI		2
# define FLR_SOUN		4
# define FLR_LOSE		8
# define FLR_NAME		16

extern	uint8_t			g_state;

typedef struct			s_player
{
	char				name[NAME_MAX + 1];
	uint32_t			score;
	sfTexture			*texture;
	sfSoundBuffer		*sound;
	sfText				*txt_name;
	sfText				*txt_score;
	sfSprite			*sprite_s;
	sfSprite			*sprite_m;
	sfRectangleShape	*shape_ok;
	sfRectangleShape	*shape_er;
	sfRectangleShape	*shape_bl;
}						t_player;

typedef	struct			s_text
{
	sfFont				*font;
	sfText				*text;
	sfText				*text_aux;
}						t_text;

typedef struct			s_sfml
{
	int32_t				height;
	int32_t				width;
	int32_t				height_sc;
	int32_t				width_sc;
	int32_t				stop;
	uint32_t			cell_cnt;
	int32_t				map_vm;
	int32_t				fd;
	t_player			*p1;
	t_player			*p2;
	t_text				*footer;
	t_text				*title;
	sfRenderWindow		*window;
	sfRenderTexture		*render;
	sfSoundBuffer		*sound_buf_pl;
	sfSoundBuffer		*sound_buf_er;
	sfSprite			*sprite;
	sfMusic				*music;
	sfSound				*sound;
	sfFont				*p_font;
	sfVector2f			pos_sc;
	sfVector2f			scale_sc;
	double				scale;
}						t_sfml;

int8_t					ft_init(int32_t argc, char **argv, t_sfml *sfml);
t_player				*ft_init_player(char *img, t_sfml *sfml);
int8_t					ft_init_player_name(t_player *p, int32_t fd);
void					ft_draw_shape(t_sfml *sfml);
void					ft_set_shape(t_sfml *sfml, char **shape);
void					ft_draw_header(t_sfml *sfml);
void					ft_destroy_sfml(t_sfml *sfml);
int32_t					ft_get_nbr(char **s);
int8_t					ft_check_loadfile(int32_t argc, char **argv);
void					ft_event_handle(t_sfml *sfml, sfEvent *event,
														sfThread *thread_rndr);
void					ft_get_size(int32_t *width, int32_t *height);
void					ft_sfml_null(t_sfml *sfml);
void					ft_handle_cmd(void *sfml);
void					ft_name_norm(char *s);

#endif
