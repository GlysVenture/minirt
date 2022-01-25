//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef KEY_HANDLER_H
# define KEY_HANDLER_H

# ifdef __gnu_linux__

enum e_key
{
	key_esc = 65307
};

# endif

# ifdef __APPLE__

enum e_key
{
	key_esc = 53
};

# endif

#endif //KEY_HANDLER_H
