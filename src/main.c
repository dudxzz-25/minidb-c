#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DB_PATH "data/records.dat"
#define NAME_LEN 80
#define EMAIL_LEN 120

typedef struct { int32_t id; uint8_t active; char name[NAME_LEN]; char email[EMAIL_LEN]; } Record;

static void ensure_data_dir(void){
#ifdef _WIN32
    system("if not exist data mkdir data >nul 2>nul");
#else
    system("mkdir -p data");
#endif
}
static FILE* open_db(const char *mode){ ensure_data_dir(); FILE *f=fopen(DB_PATH,mode); if(!f){perror("database");exit(EXIT_FAILURE);} return f; }
static int find_record(FILE *f,int32_t id,Record *out,long *pos){ Record r; rewind(f); while(fread(&r,sizeof r,1,f)==1){ if(r.active&&r.id==id){if(out)*out=r;if(pos)*pos=ftell(f)-(long)sizeof r;return 1;}} return 0; }
static void cmd_init(void){ FILE *f=open_db("wb"); fclose(f); puts("Database initialized."); }
static void cmd_insert(const char *sid,const char *name,const char *email){ int32_t id=(int32_t)strtol(sid,NULL,10); if(id<=0){fprintf(stderr,"ID must be positive.\n");exit(2);} FILE *f=open_db("a+b"); if(find_record(f,id,NULL,NULL)){fprintf(stderr,"ID already exists.\n");fclose(f);exit(3);} Record r={0};r.id=id;r.active=1;snprintf(r.name,NAME_LEN,"%s",name);snprintf(r.email,EMAIL_LEN,"%s",email);fseek(f,0,SEEK_END);fwrite(&r,sizeof r,1,f);fclose(f);puts("Inserted."); }
static void cmd_get(const char *sid){ int32_t id=(int32_t)strtol(sid,NULL,10); FILE *f=open_db("rb");Record r;if(find_record(f,id,&r,NULL))printf("%d | %s | %s\n",r.id,r.name,r.email);else{fprintf(stderr,"Not found.\n");fclose(f);exit(4);}fclose(f); }
static void cmd_list(void){ FILE *f=open_db("rb");Record r;while(fread(&r,sizeof r,1,f)==1)if(r.active)printf("%d | %s | %s\n",r.id,r.name,r.email);fclose(f); }
static void cmd_delete(const char *sid){ int32_t id=(int32_t)strtol(sid,NULL,10);FILE *f=open_db("r+b");Record r;long pos;if(!find_record(f,id,&r,&pos)){fprintf(stderr,"Not found.\n");fclose(f);exit(4);}r.active=0;fseek(f,pos,SEEK_SET);fwrite(&r,sizeof r,1,f);fclose(f);puts("Deleted."); }
int main(int argc,char **argv){ if(argc<2){fprintf(stderr,"Usage: minidb init|insert|get|list|delete ...\n");return 1;} if(!strcmp(argv[1],"init")&&argc==2)cmd_init(); else if(!strcmp(argv[1],"insert")&&argc==5)cmd_insert(argv[2],argv[3],argv[4]); else if(!strcmp(argv[1],"get")&&argc==3)cmd_get(argv[2]); else if(!strcmp(argv[1],"list")&&argc==2)cmd_list(); else if(!strcmp(argv[1],"delete")&&argc==3)cmd_delete(argv[2]); else {fprintf(stderr,"Invalid command or arguments.\n");return 1;} return 0; }
