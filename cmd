
#IDIR=/home/countify/install
#SWIG_DIR=/home/countify/projects/swig

IDIR=/media/windows/linux/repos/reposit/install
SWIG_DIR=/media/windows/linux/repos/reposit/swig

#    CXXFLAGS=-gdwarf-2 \
./configure \
    --prefix=$IDIR \
    --with-boost-include=$IDIR/include \
    --with-boost-lib=$IDIR/lib \
    --with-swig=$SWIG_DIR
