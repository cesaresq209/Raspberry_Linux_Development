DESCRIPTION = "Hello World example"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

S = "${WORKDIR}"

SRC_URI = "file://gpiolibgpio.c"

do_compile() {
        ${CC} ${CFLAGS} ${LDFLAGS} gpiolibgpio.c -o gpiolibgpio
}

do_install() {
        install -d -m 0755 ${D}/${bindir}
        install -m 0755 gpiolibgpio ${D}/${bindir}/gpiolibgpio
}

do_image:prepend() {
    bb.warn("Hello World recipe was built")
}