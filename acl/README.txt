mkdir (root)build
mkdir (root)install 
cd build
(root)/src/configure --build=i686-pc-cygwin --prefix=(root)/install -v; make >& make.out make install > install.log 2>&1


replace (root) with "Windows-Kit" or your kit name.