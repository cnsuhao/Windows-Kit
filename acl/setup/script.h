/*
 * Copyright (c) 2001, Jan Nieuwenhuizen.
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     A copy of the GNU General Public License can be found at
 *     http://www.gnu.org/
 *
 * Written by Jan Nieuwenhuizen <janneke@gnu.org>
 *
 */
#ifndef SETUP_SCRIPT_H
#define SETUP_SCRIPT_H

/* Initialisation stuff for run_script: sh, cmd, CYGWINROOT and PATH */
void init_run_script ();

/* Run the script named dir/fname.ext
   Returns the script exit status or negative error if any.  */
int try_run_script (const std::string& dir,
                    const std::string& fname,
                    const std::string& ext);

/* Run a command and capture it's output to the log */
int run (const char *cmdline);

class Script {
public:
  static bool isAScript (const std::string& file);
  bool is_p  (const std::string& stratum);
  bool not_p (const std::string& stratum);
  Script (const std::string& fileName);
  std::string baseName() const;
  std::string fullName() const;
/* Run the script.  If its suffix is .sh, and we have a Bourne shell, execute
   it using sh.  Otherwise, if the suffix is .bat, execute using cmd.exe (NT)
   or command.com (9x).  Returns the exit status of the process, or
   negative error if any.  */
  int run() const;
  bool operator == (const Script s) const {
    return scriptName == s.scriptName;
  };
  bool operator <  (const Script s) const {
    return scriptBaseName < s.scriptBaseName;
  };
private:
  bool match (const std::string& stratum, const std::string& type);
  std::string scriptName;
  std::string scriptBaseName;
  std::string scriptExtension;
  std::string scriptStratum;
  std::string scriptType;
  static char const ETCPostinstall[];
  static char const allowedStrata[];
  static char const allowedTypes[];
};

#endif /* SETUP_SCRIPT_H */
