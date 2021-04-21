#include "..\Public\main_core.h"

void init_commit(fgit_commit *out_commit)
{
    out_commit->b_init = true;
    memset(out_commit->name, 0, strlen(out_commit->name));
    memset(out_commit->commit, 0, strlen(out_commit->commit));
    memset(out_commit->data, 0, strlen(out_commit->data));

    normalization_guid(&out_commit->guid);
}

void init_git_path_2ds(fgit_path_2ds *path_2d)
{
    path_2d->size = 0;
    memset(path_2d->paths, 0, sizeof(path_2d->paths));
}