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

/* The purpose of this file is to manage the dialog box that lets the
   user choose the source of the install - from the net, from the
   current directory, or to just download files. */

#include "source.h"

#include "LogSingleton.h"

#include "win32.h"
#include <stdio.h>
#include "dialog.h"
#include "resource.h"
#include "state.h"
#include "msg.h"
#include "package_db.h"

#include "SourceSetting.h"

#include "getopt++/BoolOption.h"

static BoolOption DownloadOption (false, 'D', "download", "Download packages from internet only");
static BoolOption LocalOption (false, 'L', "local-install", "Install packages from local directory only");

static int rb[] =
  { IDC_SOURCE_NETINST, IDC_SOURCE_DOWNLOAD, IDC_SOURCE_LOCALDIR, 0 };

static void
load_dialog (HWND h)
{
  rbset (h, rb, source);
}

static void
save_dialog (HWND h)
{
  source = rbget (h, rb);
  /* We mustn't construct any packagedb objects until after the root
     directory has been selected, but setting the static data member
     that records the mode we're running in is fine here (and conversely,
     would be A Bad Thing if we did it again after the first time we
     construct a packagedb object; see package_db.h for details).  */
  packagedb::task = 
    source == IDC_SOURCE_DOWNLOAD ? PackageDB_Download : PackageDB_Install;
}

static BOOL
dialog_cmd (HWND h, int id, HWND hwndctl, UINT code)
{
  switch (id)
    {

    case IDC_SOURCE_DOWNLOAD:
    case IDC_SOURCE_NETINST:
    case IDC_SOURCE_LOCALDIR:
      save_dialog (h);
      break;

    default:
      break;
    }
  return 0;
}

bool
SourcePage::Create ()
{
  return PropertyPage::Create (NULL, dialog_cmd, IDD_SOURCE);
}

void
SourcePage::OnActivate ()
{
  if (DownloadOption && LocalOption)
    source = IDC_SOURCE_NETINST;
  else if (DownloadOption)
    source = IDC_SOURCE_DOWNLOAD;
  else if (LocalOption)
    source = IDC_SOURCE_LOCALDIR;
  else if (!source)
    //only default to IDC_SOURCE_NETINST if
    //source not already set:
    source = IDC_SOURCE_NETINST;

  load_dialog (GetHWND ());
  // Check to see if any radio buttons are selected. If not, select a default.
  if (SendMessage (GetDlgItem (IDC_SOURCE_DOWNLOAD), BM_GETCHECK, 0, 0)
      != BST_CHECKED
      && SendMessage (GetDlgItem (IDC_SOURCE_LOCALDIR), BM_GETCHECK, 0, 0)
	 != BST_CHECKED)
    SendMessage (GetDlgItem (IDC_SOURCE_NETINST), BM_SETCHECK,
		 BST_CHECKED, 0);
}

long
SourcePage::OnNext ()
{
  HWND h = GetHWND ();

  save_dialog (h);
  return 0;
}

long
SourcePage::OnBack ()
{
  save_dialog (GetHWND ());
  return 0;
}

void
SourcePage::OnDeactivate ()
{
  Log (LOG_PLAIN) << "source: "
    << ((source == IDC_SOURCE_DOWNLOAD) ? "download" :
        (source == IDC_SOURCE_NETINST) ? "network install" : "from local dir")
    << endLog;
}

long
SourcePage::OnUnattended ()
{
  return OnNext();
}
