/*
 * Copyright (c) 2000, 2001, 2002, 2003, 2006, 2008, 2013 Red Hat, Inc.
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     A copy of the GNU General Public License can be found at
 *     http://www.gnu.org/
 *
 * Written by DJ Delorie <dj@cygnus.com>
 *
 */

#ifndef SETUP_MOUNT_H
#define SETUP_MOUNT_H

/* Finds the existing root mount, or returns NULL.  istext is set to
   nonzero if the existing mount is a text mount, else zero for
   binary. */

#include <string>
#include "String++.h"

#define SETUP_KEY_WOW64 (is_64bit ? KEY_WOW64_64KEY : KEY_WOW64_32KEY)

void create_install_root ();
void read_mounts (const std::string);

/* Sets the cygdrive flags.  Used to make the automounted drives' binary/text
mode consistent with the standard Cygwin mounts. */

std::string cygpath (const std::string&);
void set_root_dir (const std::string);
const std::string &get_root_dir ();

#endif /* SETUP_MOUNT_H */
