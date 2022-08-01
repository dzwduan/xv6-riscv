#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"


void 
help(){
    printf("Usage:\n");
    printf("pwd [OPTION]\n");
    printf("Options:\n");
    printf("-L : Menampilkan alamat meskipun terdapat symlinks\n");
    printf("-P : Menampilkan alamat tanpa mengandung symlinks\n\n");
    printf("--help : Memperlihatkan bantuan lalu exit\n");
    printf("--versi : Menunjukkan informasi tentang versi lalu exit\n");
    printf("Dikarenakan pada xv6 tidak terdapat synmlinks, maka fungsi dari opsi -L dan -P menjadi sama\n");
    exit(0);
}

void
prog(){
    printf("pwd version 1.00\n");
    printf("Dibuat oleh Ferdinand Jason, Nurlita Dhuha, Alvin Tanuwijaya, Bagus Aji Sinto\n");
    exit(0);
}

int main(int argc,char *argv[])
{
    char cwd[100];
    int logical=0,physical=1;
    int err=open("/temp.pwd",O_RDONLY);
    if(argv[1][0]=='-')
    {
        if(strcmp(argv[1],"-L")==0) {logical=1;physical=0;}
        if(strcmp(argv[1],"-P")==0) physical=1;
        if(strcmp(argv[1],"--help")==0) help();
        if(strcmp(argv[1],"--versi")==0) prog();
	else 
	{
		printf("pwd: invalid opsi %s\nCoba ketik 'pwd --help' untuk info lebih lanjut\n",argv[1]);
		exit(1);
	}
    }
    if(err<0) 
    {
        printf("/\n");
        exit(1);
    }
    int red=read(err,cwd,sizeof(cwd));
    if(red<0)
    {
        printf("ERROR\n");
        exit(1);
    }
    close(err);
    // di xv6 tidak ada symlink.    
    if(logical==1 || physical==1 || logical==0)
        printf("%s\n",cwd);
    exit(0);
}