/*
 * Copyright (c) 2003, Robert Collins <rbtcollins@hotmail.com>
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     A copy of the GNU General Public License can be found at
 *     http://www.gnu.org/
 *
 * Written by Robert Collins.
 *
 */

#include <stdlib.h>
#include "ConnectionSetting.h"
#include "UserSettings.h"
#include "io_stream.h"
#include "netio.h"
#include "resource.h"
#include "String++.h"

ConnectionSetting::ConnectionSetting ()
{
  const char *fg_ret;
  if ((fg_ret = UserSettings::instance().get ("net-method")))
    NetIO::net_method = typeFromString(fg_ret);
  if ((fg_ret = UserSettings::instance().get ("net-proxy-host")))
    NetIO::net_proxy_host = strdup(fg_ret);
  if ((fg_ret = UserSettings::instance().get ("net-proxy-port")))
    NetIO::net_proxy_port = atoi(fg_ret);
}

ConnectionSetting::~ConnectionSetting ()
{
  switch (NetIO::net_method)
    {
    case IDC_NET_DIRECT:
      UserSettings::instance().set("net-method", "Direct");
      break;
    case IDC_NET_PRECONFIG:
      UserSettings::instance().set("net-method", "IE");
      break;
    case IDC_NET_PROXY:
      char port_str[20];
      UserSettings::instance().set("net-method", "Proxy");
      UserSettings::instance().set("net-proxy-host", NetIO::net_proxy_host);
      sprintf(port_str, "%d", NetIO::net_proxy_port);
      UserSettings::instance().set("net-proxy-port", port_str);
      break;
    default:
	break;
    }
}

int
ConnectionSetting::typeFromString(const std::string& aType)
{
  if (!casecompare(aType, "Direct"))
    return IDC_NET_DIRECT;
  if (!casecompare(aType, "IE"))
    return IDC_NET_PRECONFIG;
  if (!casecompare(aType, "Proxy"))
    return IDC_NET_PROXY;

  /* Migrate the removed direct(legacy) to direct */
  if (!casecompare(aType, "Legacy"))
    return IDC_NET_DIRECT;

  /* A sanish default */
  return IDC_NET_PRECONFIG;
}
