// #include "so_long.h"

// int	move_error_left(t_vars vars, t_map map, t_pos pos)
// {
// 	if (map.matrix[pos.x - 1][pos.y] == '1')
// 		return (0);
// 	if (map.matrix[pos.x - 1][pos.y] == 'K')
// 		free_and_exit(vars, map);
// 	return (1);
// }

// int	move_error_right(t_vars vars, t_map map, t_pos pos)
// {
// 	if (map.matrix[pos.x + 1][pos.y] == '1')
// 		return (0);
// 	if (map.matrix[pos.x + 1][pos.y] == 'K')
// 		free_and_exit(vars, map);
// 	return (1);
// }

// int	move_error_up(t_vars vars, t_map map, t_pos pos)
// {
// 	if (map.matrix[pos.x][pos.y + 1] == '1')
// 		return (0);
// 	if (map.matrix[pos.x][pos.y + 1] == 'K')
// 		free_and_exit(vars, map);
// 	return (1);
// }

// int	move_error_down(t_vars vars, t_map map, t_pos pos)
// {
// 	if (map.matrix[pos.x][pos.y - 1] == '1')
// 		return (0);
// 	if (map.matrix[pos.x][pos.y - 1] == 'K')
// 		free_and_exit(vars, map);
// 	return (1);
// }

// int	move_error(int	key_kode, t_vars vars, t_map map, t_pos pos)
// {
// 	if (key_kode == A || key_kode == LEFT)
// 		if (!move_error_left(vars, map, pos))
// 			return (0);
// 	if (key_kode == D || key_kode == RIGHT)
// 		if (!move_error_right(vars, map, pos))
// 			return (0);
// 	if (key_kode == W || key_kode == UP)
// 		if (!move_error_up(vars, map, pos))
// 			return (0);
// 	if (key_kode == S || key_kode == DOWN)
// 		if (!move_error_down(vars, map, pos))
// 			return (0);
// 	return (1);
// }