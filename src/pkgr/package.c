#include "package.h"
#include "../utils.h"
#include <limits.h>

#define DIR_SCRIPTS "pkgr/scripts"
#define SCRIPTS_INSTALL_PRE DIR_SCRIPTS"/pre-install.sh"
#define SCRIPTS_INSTALL_POST DIR_SCRIPTS"/post-install.sh"

void package_create(const char *root, const char *name) {
    char archive[PATH_MAX + 1];
    sprintf(archive, "%s/%s.tar.xz", root, name);

    execute("touch %s/"SCRIPTS_INSTALL_PRE, root);
    execute("touch %s/"SCRIPTS_INSTALL_POST, root);

    execute("tar cpPJf %s --transform 's,%s/,,' --owner=0 --group=0"
            " %s/"DIR_ROOT
            " %s/"SCRIPTS_INSTALL_PRE
            " %s/"SCRIPTS_INSTALL_POST
            , archive, root, root, root, root);
}

FILE *package_read_file_list(const char *archive) {
    FILE *f;
    start_pipe(f, "tar tPf %s --wildcards "DIR_ROOT"/* "
            "--transform 's,"DIR_ROOT",,' "
            "--show-stored-names | grep -v '/$'",
            archive);
    return f;
}

void package_extract_files(const char *archive, const char *to) {
    execute("tar vxPf %s --wildcards "DIR_ROOT"/* --transform 's,"DIR_ROOT",%s,' --show-stored-names",
        archive, to);
}

const char *package_get_name(const char *archive, char *name) {
    split_filename(archive, NULL, name);
    name[strlen(name) - 7] = 0;         // drop .tar.xz
    return name;
}

void package_run_scripts_pre_install(const char *archive, const char *root) {
    set_environment_variable("R", root);
    execute("tar -xf %s -O " SCRIPTS_INSTALL_PRE " | sh", archive);
}

void package_run_scripts_post_install(const char *archive, const char *root) {
    set_environment_variable("R", root);
    execute("tar -xf %s -O " SCRIPTS_INSTALL_POST " | sh", archive);
}
