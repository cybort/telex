/* Copyright 2007-2010 Jozsef Kadlecsik (kadlec@blackhole.kfki.hu)
 *
 * This program is free software; you can redistribute it and/or modify   
 * it under the terms of the GNU General Public License version 2 as 
 * published by the Free Software Foundation.
 */
#ifndef LIBIPSET_UI_H
#define LIBIPSET_UI_H

#include <libipset/linux_ip_set.h>		/* enum ipset_cmd */

/* Commands in userspace */
struct ipset_commands {
	enum ipset_cmd cmd;
	int has_arg;
	const char *name[2];
	const char *help;
};

extern const struct ipset_commands ipset_commands[];

struct ipset_session;
struct ipset_data;

/* Environment options */
struct ipset_envopts {
	int flag;
	int has_arg;
	const char *name[2];
	const char *help;
	int (*parse)(struct ipset_session *s, int flag, const char *str);
	int (*print)(char *buf, unsigned int len,
		     const struct ipset_data *data, int flag, uint8_t env);
};

extern const struct ipset_envopts ipset_envopts[];

extern bool ipset_match_cmd(const char *arg, const char * const name[]);
extern bool ipset_match_option(const char *arg, const char * const name[]);
extern bool ipset_match_envopt(const char *arg, const char * const name[]);
extern void ipset_shift_argv(int *argc, char *argv[], int from);
extern void ipset_port_usage(void);

#endif /* LIBIPSET_UI_H */
