#! /bin/sh
# Used to setup the configure.in, autoheader and Makefile.in's if configure
# has not been generated. This script is only needed for developers when
# configure has not been run, or if a Makefile.am in a non-configured directory
# has been updated


bootstrap() {
  if "$@"; then
    true # Everything OK
  else
    echo "$1 failed"
    echo "Autotool bootstrapping failed. You will need to investigate and correct" ;
    echo "before you can develop on this source tree" 
    exit 1
  fi
}

# Make sure we are running in the right directory
if [ ! -f src/GetOption.cc ]; then
    echo "You must run this script from the directory containing it"
    exit 1
fi

# Make sure cfgaux exists
mkdir -p cfgaux

# Bootstrap the autotool subsystems
bootstrap aclocal
bootstrap autoheader
bootstrap libtoolize --automake
bootstrap automake --foreign --add-missing
bootstrap autoconf

echo "Autotool bootstrapping complete."
