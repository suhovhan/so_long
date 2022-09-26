#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_img	img;
	t_vars	vars;

	map = get_map(ac, av);
	vars.mlx = mlx_init();
	ft_printf("OK!\n");
	img.i_0 = "./img/map.xpm";
	img.i_1 = "./img/wall.xpm";
	img.p_d = "./img/pers_D.xpm";
	img.p_a = "./img/pers_A.xpm";
	img.p_s = "./img/pers_S.xpm";
	img.p_w = "./img/pers_W.xpm";
	img.i_c = "./img/coin.xpm";
	img.i_e = "./img/exit.xpm";
	img.i_k = "./img/enemy.xpm";
	img.xpm_1 = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_0 = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_pd = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_pa = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_pw = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_ps = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_c = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_e = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.xpm_k = mlx_new_image(vars.mlx, SIZE, SIZE);
	free_and_exit(map);
	return (0);
}