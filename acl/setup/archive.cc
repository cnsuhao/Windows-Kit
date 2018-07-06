/*
 * Copyright (c) 2001, Robert Collins.
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     A copy of the GNU General Public License can be found at
 *     http://www.gnu.org/
 *
 * Written by Robert Collins  <rbtcollins@hotmail.com>
 *
 */

/* Archive IO operations
 */

#include "LogSingleton.h"

#include "io_stream.h"
#include "archive.h"
#include "archive_tar.h"

/* This file is the sole user of alloca(), so do this here.
 * This will go away when this file is useing proper C++ string handling. */
#if HAVE_ALLOCA_H
#include <alloca.h>
#else
#ifndef alloca
#define alloca __builtin_alloca
#endif
#endif

/* In case you are wondering why the file magic is not in one place:
 * It could be. But there is little (any?) benefit.
 * What is important is that the file magic required for any _task_ is centralised.
 * One such task is identifying archives
 *
 * to federate into each class one might add a magic parameter to the constructor, which
 * the class could test itself.
 */

/* GNU TAR:
 * offset 257     string  ustar\040\040\0
 */


#define longest_magic 265

archive *
archive::extract (io_stream * original)
{
  if (!original)
    return NULL;
  char magic[longest_magic];
  if (original->peek (magic, longest_magic) > 0)
    {
      if (memcmp (&magic[257], "ustar\040\040\0", 8) == 0
          || memcmp (&magic[257], "ustar\0", 6) == 0)
	{
	  /* tar */
	  archive_tar *rv = new archive_tar (original);
	  if (!rv->error ())
	    return rv;
	  return NULL;
	}
#if 0
      else if (memcmp (magic, "BZh", 3) == 0)
	{
	  archive_bz *rv = new archive_bz (original);
	  if (!rv->error ())
	    return rv;
	  return NULL;
	}
#endif
    }
  return NULL;
}

archive::extract_results
archive::extract_file (archive * source, const std::string& prefixURL,
                       const std::string& prefixPath, std::string suffix)
{
  extract_results res = extract_other;
  if (source)
    {
      const std::string destfilename = prefixURL + prefixPath
	+ source->next_file_name() + suffix;
      switch (source->next_file_type ())
	{
	case ARCHIVE_FILE_REGULAR:
	  {
	    /* TODO: remove in-the-way directories via mkpath_p */
	    if (io_stream::mkpath_p (PATH_TO_FILE, destfilename, 0755))
	      {
		Log (LOG_TIMESTAMP) << "Failed to make the path for " << destfilename
				    << endLog;
		res = extract_inuse;
		goto out;
	      }
	    io_stream::remove (destfilename);
	    io_stream *in = source->extract_file ();
	    if (!in)
	      {
		Log (LOG_TIMESTAMP) << "Failed to extract the file "
				    << destfilename << " from the archive"
				    << endLog;
		res = extract_inuse;
		goto out;
	      }
	    io_stream *tmp = io_stream::open (destfilename, "wb", in->get_mode ());
	    if (!tmp)
	      {
		delete in;
		Log (LOG_TIMESTAMP) << "Failed to open " << destfilename;
		Log (LOG_TIMESTAMP) << " for writing." << endLog;
		res = extract_inuse;
	      }
	    else if (io_stream::copy (in, tmp))
	      {
		Log (LOG_TIMESTAMP) << "Failed to output " << destfilename
				    << endLog;
		delete in;
		delete tmp;
		io_stream::remove (destfilename);
		res = extract_other;
	      }
	    else
	      {
		tmp->set_mtime (in->get_mtime ());
		delete in;
		delete tmp;
		res = extract_ok;
	      }
	  }
	  break;
	case ARCHIVE_FILE_SYMLINK:
	  if (io_stream::mkpath_p (PATH_TO_FILE, destfilename, 0755))
	    {
	      Log (LOG_TIMESTAMP) << "Failed to make the path for %s"
				  << destfilename << endLog;
	      res = extract_other;
	    }
	  else
	    {
	      io_stream::remove (destfilename);
	      int x = io_stream::mklink (destfilename,
					 prefixURL+ source->linktarget (),
					 IO_STREAM_SYMLINK);
	      /* FIXME: check what tar's filelength is set to for symlinks */
	      source->skip_file ();
	      res = x == 0 ? extract_ok : extract_inuse;
	    }
	  break;
	case ARCHIVE_FILE_HARDLINK:
	  if (io_stream::mkpath_p (PATH_TO_FILE, destfilename, 0755))
	    {
	      Log (LOG_TIMESTAMP) << "Failed to make the path for %s"
				  << destfilename << endLog;
	      res = extract_other;
	    }
	  else
	    {
	      io_stream::remove (destfilename);
	      int x = io_stream::mklink (destfilename,
					 prefixURL + prefixPath + source->linktarget (),
					 IO_STREAM_HARDLINK);
	      /* FIXME: check what tar's filelength is set to for hardlinks */
	      source->skip_file ();
	      res = x == 0 ? extract_ok : extract_inuse;
	    }
	  break;
	case ARCHIVE_FILE_DIRECTORY:
	  {
	    char *path = (char *) alloca (destfilename.size());
	    strcpy (path, destfilename.c_str());
	    while (path[0] && path[strlen (path) - 1] == '/')
	      path[strlen (path) - 1] = 0;
	    io_stream *in = source->extract_file ();
	    int x = io_stream::mkpath_p (PATH_TO_DIR, path, in->get_mode ());
	    delete in;
	    source->skip_file ();
	    res = x == 0 ? extract_ok : extract_other;
	  }
	  break;
	case ARCHIVE_FILE_INVALID:
	  source->skip_file ();
	  break;
	}
    }
out:
  return res;
}

archive::~archive () {};

#if 0
ssize_t archive::read (void *buffer, size_t len)
{
  Log (LOG_TIMESTAMP, "archive::read called");
  return 0;
}

ssize_t archive::write (void *buffer, size_t len)
{
  Log (LOG_TIMESTAMP, "archive::write called");
  return 0;
}

ssize_t archive::peek (void *buffer, size_t len)
{
  Log (LOG_TIMESTAMP, "archive::peek called");
  return 0;
}

long
archive::tell ()
{
  Log (LOG_TIMESTAMP, "bz::tell called");
  return 0;
}

int
archive::error ()
{
  Log (LOG_TIMESTAMP, "archive::error called");
  return 0;
}

const char *
archive::next_file_name ()
{
  Log (LOG_TIMESTAMP, "archive::next_file_name called");
  return NULL;
}

#endif
