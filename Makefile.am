bin_PROGRAMS = pkgr
EXTRA_DIST = $(TESTS)

TESTS =
TESTS += tests/package/create-tarxz.sh
TESTS += tests/package/create-with-name.sh
TESTS += tests/package/create-with-scripts.sh
TESTS += tests/install/added-to-library.sh
TESTS += tests/install/files-owned.sh
TESTS += tests/install/run-scripts.sh
TESTS += tests/library/remove-ownership.sh
TESTS += tests/library/remove-ownership-fail-if-not-owned.sh
TESTS += tests/query/owner-fails-if-not-found.sh
TESTS += tests/query/owner-match-by-full-path.sh
TESTS += tests/spec/install_create-files.sh
TESTS += tests/spec/install_blocked-if-file-already-owned.sh
TESTS += tests/spec/install_replace-file-ownership.sh
TESTS += tests/spec/install_run-scripts.sh
XFAIL_TESTS =

pkgr_CFLAGS = -ggdb -pedantic -Wall -Wextra
pkgr_SOURCES = src/main.c
pkgr_SOURCES += src/settings.c
pkgr_SOURCES += src/settings.h

pkgr_SOURCES += src/commands.h
pkgr_SOURCES += src/commands/install.c
pkgr_SOURCES += src/commands/package.c
pkgr_SOURCES += src/commands/library.c
pkgr_SOURCES += src/commands/query.c

pkgr_SOURCES += src/utils.h
pkgr_SOURCES += src/utils/exec.c
pkgr_SOURCES += src/utils/functions.c
pkgr_SOURCES += src/utils/io.c

pkgr_SOURCES += src/pkgr/install.h
pkgr_SOURCES += src/pkgr/install.c
pkgr_SOURCES += src/pkgr/library.h
pkgr_SOURCES += src/pkgr/library.c
pkgr_SOURCES += src/pkgr/package.h
pkgr_SOURCES += src/pkgr/package.c
