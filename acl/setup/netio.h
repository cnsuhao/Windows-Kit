/*
 * Copyright (c) 2000, Red Hat, Inc.
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

#ifndef SETUP_NETIO_H
#define SETUP_NETIO_H

#include "win32.h"

/* This is the parent class for all the access methods known to setup
   (i.e. ways to download files from the internet or other sources */

class NetIO
{
protected:
  BOOL ftp_auth;

  static char *net_user;
  static char *net_passwd;
  static char *net_proxy_user;
  static char *net_proxy_passwd;
  static char *net_ftp_user;
  static char *net_ftp_passwd;


public:
  /* if nonzero, this is the estimated total file size */
  int file_size;

  virtual ~ NetIO () {};

  /* The user calls this function to create a suitable accessor for
     the given URL.  It uses the network setup state in state.h.  If
     anything fails, either the return values is NULL or the returned
     object is !ok() */
  static NetIO *open (char const *url, bool cachable);

  /* If !ok() that means the transfer isn't happening. */
  virtual int ok ();

  /* Read `nbytes' bytes from the file.  Returns zero when the file
     is complete. */
  virtual int read (char *buf, int nbytes);

  static int net_method;
  static char *net_proxy_host;
  static int net_proxy_port;

  static const char *net_method_name();

  /* Helper functions for http/ftp protocols.  Both return nonzero for
     "cancel", zero for "ok".  They set net_proxy_user, etc, in
     state.h */
  int get_auth (HWND owner);
  int get_proxy_auth (HWND owner);
  int get_ftp_auth (HWND owner);
};

#endif /* SETUP_NETIO_H */
