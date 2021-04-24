#include "..\Public\main_core.h"
#include "..\..\simple_c_array\simple_c_array.h"
#include "..\..\simple_c_helper_file\simple_c_helper_file.h"
#include "..\..\simple_c_string_algorithm\simple_c_string_algorithm.h"
#include <direct.h>

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

void read_user()
{
    char *cofg_path_buf = get_git_local_user_filename();

    char buf_cofg[2048] = {0};
    if (get_file_buf(buf_cofg, cofg_path_buf))
    {
        simple_c_string c_str_sentence;
        dismantling_string(buf_cofg, "\n", &c_str_sentence);
        for (int i = 0; i < c_str_sentence.size; i++)
        {
            char *tmp = get_string(i, &c_str_sentence);
            if (strstr(tmp, "name="))
            {
                dismantling_string_by_index(user.name,tmp,"=",1);
            }
            else if (strstr(tmp, "password="))
            {
                dismantling_string_by_index(user.name,tmp,"=",1);
            }
            else if (strstr(tmp, "email="))
            {
                dismantling_string_by_index(user.name,tmp,"=",1);
            }
        }
        destroy_string(&c_str_sentence);
    }
}

void save_user()
{
    char *cofg_path_buf = get_git_local_user_filename();
    FILE *p = NULL;
    if ((p = fopen(cofg_path_buf,"w+"))!=NULL)
    {
        fprintf(p,"account=%s\n",user.name);
        fprintf(p,"password=%s\n",user.password);
        fprintf(p,"email=%s\n",user.email);

        fclose(p);
    }
    
}

char *get_git_local_user_filename()
{
    if (gir_local_cofg_filename[0] == '\0')
    {
        _mkdir(git_local_cofg_file);
        strcpy(gir_local_cofg_filename, git_local_cofg_file);

        strcat(gir_local_cofg_filename, "git_user.ini");
        if (_access(gir_local_cofg_filename, 0) == -1)
        {
            create_file(gir_local_cofg_filename);
        }
    }
}

char*get_git_project_remote_url()
{
    if (git_project_remote_url[0] = '\0')
    {
        strcpy(git_project_remote_url,git_remote_origin);
        strcat(git_project_remote_url,"\\git_server");
    }
    return git_project_remote_url;
}