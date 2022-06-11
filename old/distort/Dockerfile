FROM debian:9 AS builder

RUN apt-get update && \
    apt-get install -y \
        build-essential \
        pkg-config \
        wget \
        tar \
        libltdl-dev \
        libpng-dev \
        libjpeg-dev \
        libwebp-dev \
        liblqr-dev \
        glib2.0-dev \
    && apt-get clean


RUN mkdir build
WORKDIR build
RUN wget https://www.imagemagick.org/download/ImageMagick.tar.xz
RUN tar -x --strip 1 -f ImageMagick.tar.xz

RUN ./configure \
    --enable-shared \
    --enable-delegate-build \
    --with-modules \
    --with-webp=yes \
    --with-png=yes \
    --with-jpeg=yes \
    --with-lqr=yes \
    --with-freetype=yes \
    --without-gslib \
    --without-x \
    --without-wmf \
    --disable-opencl \
    --without-magick-plus-plus \
    --without-perl \
    --disable-silent-rules \
    --disable-dependency-tracking

RUN make -j4
RUN make install DESTDIR=/dest

FROM debian:9 AS runner

RUN apt-get update && \
    apt-get install -y \
        libwebp6 \
        libwebpdemux2 \
        libwebpmux2 \
        libpng16-16 \
        libjpeg62-turbo \
        liblqr-1-0 \
        glib2.0 \
        libltdl7 \
        libgomp1 \
    && apt-get clean

COPY --from=builder /dest /

RUN ldconfig
