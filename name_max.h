#ifndef NAME_MAX_H
# define NAME_MAX_H

/*
** MACOS lacks HOST_NAME_MAX and LOGIN_NAME_MAX macros
*/

# ifndef HOST_NAME_MAX
#  if defined(_POSIX_HOST_NAME_MAX)
#   define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#  elif defined(MAXHOSTNAMELEN)
#   define HOST_NAME_MAX MAXHOSTNAMELEN
#  endif
# endif 

# ifndef LOGIN_NAME_MAX
#  if defined(_POSIX_LOGIN_NAME_MAX)
#   define LOGIN_NAME_MAX _POSIX_LOGIN_NAME_MAX
#  elif defined(MAXLOGINNAMELEN)
#   define LOGIN_NAME_MAX MAXLOGINNAMELEN
#  endif
# endif 

#endif
