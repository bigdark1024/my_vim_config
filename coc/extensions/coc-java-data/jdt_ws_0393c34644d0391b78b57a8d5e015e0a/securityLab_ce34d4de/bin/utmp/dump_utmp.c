#include <stdio.h>
#include <utmp.h>

int main(int argc, char *argv[]) {
    struct utmp *u;
    utmpname(UTMP_FILE);
    while((u = getutent()))
    {
      if(u->ut_type == RUN_LVL) {
        printf("ut_type=%d ut_id=%s  ut_line = %s ut_host=%s ut_pid=%d\n", u->ut_type, u->ut_id, u->ut_line, u->ut_host, u->ut_pid - '0');
      }
    }
    endutent();
  return 0;
}

