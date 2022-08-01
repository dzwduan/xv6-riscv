#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        exit(1);
    }
    if(chdir(argv[1])!= 0)
    {
        exit(1);
    }

    exit(0);
}